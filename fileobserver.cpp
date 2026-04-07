#include "FileObserver.h"

FileObserver::FileObserver(IObservationSource *observationSource_, IMyFInfoContainer *observedFiles_, IObservationTrigger *observationTrigger_, ILog *logger_)
{
    observationSource = observationSource_;
    observedFiles = observedFiles_;
    observationTrigger = observationTrigger_;
    logger = logger_;
    if(logger)
    {
        connect(this, &FileObserver::fileExist, logger, &ILog::onFileExistence);
        connect(this, &FileObserver::fileUpdate, logger, &ILog::onFileUpdate);
        connect(this, &FileObserver::fileMissing, logger, &ILog::onFileMissing);
    }
}

FileObserver::~FileObserver()
{

}

FileObserver &FileObserver::GetInstance(IObservationSource *observationSource_, IMyFInfoContainer *observedFiles_, IObservationTrigger *observationTrigger_, ILog *logger_)
{
    static FileObserver Sobject(observationSource_, observedFiles_, observationTrigger_, logger_);
    return Sobject;
}

void FileObserver::setObservationSource(IObservationSource *observationSource_)
{
    observationSource = observationSource_;
}
void FileObserver::setLogger(ILog *logger_)
{
    logger = logger_;
    if(logger)
    {
        connect(this, &FileObserver::fileExist, logger, &ILog::onFileExistence);
        connect(this, &FileObserver::fileUpdate, logger, &ILog::onFileUpdate);
        connect(this, &FileObserver::fileMissing, logger, &ILog::onFileMissing);
    }
}
void FileObserver::setObservationTrigger(IObservationTrigger *observationTrigger_)
{
    observationTrigger = observationTrigger_;
}
void FileObserver::setMyFInfoContainer(IMyFInfoContainer *observedFiles_)
{
    observedFiles = observedFiles_;
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
    if (!observedFiles)
    {
        return;
    }
    observedFiles -> clear();
    QVector<QString> newPathsToObservedFiles = observedFiles->getAllPaths();
    QVector<MyFInfo> newObservedFiles;
    while (true)
    {
        newObservedFiles.clear();
        observationSource->update(newPathsToObservedFiles);
        for (int i = 0; i < newPathsToObservedFiles.size(); ++i)
        {
            QFileInfo newFileInfo(newPathsToObservedFiles[i]);
            MyFInfo newObservedFile(newFileInfo.absoluteFilePath(), newFileInfo.isFile(), newFileInfo.lastModified());
            int size = newFileInfo.size();
            newObservedFiles.append(newObservedFile);
            if(logger)
            {
                MyFInfo observedFile = observedFiles->getByPath(newObservedFile.getFilePath());
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
        }
        observedFiles->setNewData(newObservedFiles);
        observationTrigger->wait();
    }
}
