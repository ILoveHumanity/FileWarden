#include "FileObserver.h"
#include "QDebug"

FileObserver::FileObserver(IObservationSource *observationSource_, IMyFInfoContainer *observedFiles_, IObservationTrigger *observationTrigger_, ILog *logger_)
{
    // initiate variables
    observationSource = observationSource_;
    observedFiles = observedFiles_;
    observedFiles -> clear();
    observationTrigger = observationTrigger_;
    logger = logger_;
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
    observedFiles -> clear();
}
void FileObserver::setLogger(ILog *logger_)
{
    logger = logger_;
}
void FileObserver::setObservationTrigger(IObservationTrigger *observationTrigger_)
{
    observationTrigger = observationTrigger_;
}

void FileObserver::startObservation()
{
    if (observationSource == nullptr)
    {
        return;
    }


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
            if(logger != nullptr)
            {
                MyFInfo observedFile = observedFiles->getByPath(newObservedFile.getFilePath());
                // Если файл добавился под наблюдение
                if (observedFile.isNull())
                {
                    // signal
                    logger->log("File: " + newObservedFile.getFilePath() + " added under observation" + (newObservedFile.getExist()?" size: [" + QString::number(size) + " B]" : " file dont exist") );
                }
                // Если файл удалили/добавили
                else if(observedFile.getExist() != newObservedFile.getExist())
                {
                    // signal
                    logger->log("File: " + newObservedFile.getFilePath() + (newObservedFile.getExist()?" file exist size: [" + QString::number(size) + " B]" : " file dont exist"));
                }
                // Если файл поменяли
                else if(observedFile.getLastModified() != newObservedFile.getLastModified())
                {
                    // signal
                    logger->log("File: " + newObservedFile.getFilePath() + " updated at: " + newObservedFile.getLastModified().toString("dd.MM hh:mm:ss") + " size: [" + QString::number(size) + " B]" );
                }
            }
        }
        observedFiles->setNewData(newObservedFiles);
        observationTrigger->wait();
    }
}

