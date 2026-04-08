#include "FileObserver.h"

FileObserver::FileObserver()
{
    observationSource = nullptr;
    myFInfoContainer = nullptr;
    observationTrigger = nullptr;
    fileStateSignalHandler = nullptr;
}

FileObserver::~FileObserver()
{

}

FileObserver &FileObserver::GetInstance(IObservationSource *observationSource_, IMyFInfoContainer *myFInfoContainer_, IObservationTrigger *observationTrigger_, IFileStateSignalHandler *fileStateSignalHandler_)
{
    static FileObserver sObject;
    sObject.setObservationSource(observationSource_);
    sObject.setMyFInfoContainer(myFInfoContainer_);
    sObject.setObservationTrigger(observationTrigger_);
    sObject.setFileStateSignalHandler(fileStateSignalHandler_);
    return sObject;
}

void FileObserver::setObservationSource(IObservationSource *observationSource_)
{
    observationSource = observationSource_;
}

void FileObserver::setMyFInfoContainer(IMyFInfoContainer *myFInfoContainer_)
{
    myFInfoContainer = myFInfoContainer_;
}

void FileObserver::setObservationTrigger(IObservationTrigger *observationTrigger_)
{
    observationTrigger = observationTrigger_;
}

void FileObserver::setFileStateSignalHandler(IFileStateSignalHandler *fileStateSignalHandler_)
{
    if(fileStateSignalHandler)
    {
        disconnect(fileStateSignalHandler);
    }
    fileStateSignalHandler = fileStateSignalHandler_;
    if(fileStateSignalHandler)
    {
        connect(this, &FileObserver::fileExist, fileStateSignalHandler, &IFileStateSignalHandler::onFileExistence);
        connect(this, &FileObserver::fileUpdate, fileStateSignalHandler, &IFileStateSignalHandler::onFileUpdate);
        connect(this, &FileObserver::fileMissing, fileStateSignalHandler, &IFileStateSignalHandler::onFileMissing);
    }
}

void FileObserver::startObservation()
{
    if (!observationSource)
    {
        return;
    }
    if(!observationTrigger)
    {
        return;
    }
    if (!myFInfoContainer)
    {
        return;
    }
    if (!fileStateSignalHandler)
    {
        return;
    }
    myFInfoContainer -> clear();
    QVector<QString> newPathsToObservedFiles = myFInfoContainer->getAllPaths();
    QVector<MyFInfo> newObservedFiles;
    bool continueFlag;
    while (true)
    {
        continueFlag = observationSource->update(newPathsToObservedFiles);
        if(!continueFlag)
        {
            return;
        }
        newObservedFiles.clear();
        for (int i = 0; i < newPathsToObservedFiles.size(); ++i)
        {
            QFileInfo newFileInfo(newPathsToObservedFiles[i]);
            MyFInfo newObservedFile(newFileInfo.absoluteFilePath(), newFileInfo.isFile(), newFileInfo.lastModified());
            int size = newFileInfo.size();
            newObservedFiles.append(newObservedFile);
            MyFInfo observedFile = myFInfoContainer->getByPath(newObservedFile.getFilePath());
            // Если файл добавился под наблюдение || Если файл удалили/добавили
            if (observedFile.isNull() || observedFile.getExist() != newObservedFile.getExist())
            {
                if(newObservedFile.getExist())
                {
                    emit fileExist(newObservedFile, size);
                }
                else
                {
                    emit fileMissing(newObservedFile);
                }
            }
            // Если файл изменился
            else if(observedFile.getLastModified() != newObservedFile.getLastModified())
            {
                emit fileUpdate(newObservedFile, size);
            }
        }
        myFInfoContainer->setNewData(newObservedFiles);
        observationTrigger->wait();
    }
}
