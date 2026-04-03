#include "FileObserver.h"
#include "QDebug"

FileObserver::FileObserver(IObservationSource *observationSource_, IMyFInfoContainer *observedFiles_, IObservationTrigger *observationTrigger_, ILog *logger_)
{
    // initiate variables
    observationSource = observationSource_;
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
            QFileInfo newObservedFile(newPathsToObservedFiles[i]);
            newCharacteristicsOfObservedFiles.append(qMakePair(newObservedFile.exists(), newObservedFile.lastModified()));
            if(logger != nullptr)
            {
                int last_i = pathsToObservedFiles.indexOf(newPathsToObservedFiles[i]);
                // Если файл добавился под наблюдение
                if (last_i < 0)
                {
                    // signal
                    logger->log("File: " + newObservedFile.filePath() + " added under observation" + (newObservedFile.exists()?" size: [" + QString::number(newObservedFile.size()) + " B]" : " file dont exist") );
                }
                // Если файл удалили/добавили
                else if(characteristicsOfObservedFiles[last_i].first != newObservedFile.exists())
                {
                    // signal
                    logger->log("File: " + newObservedFile.filePath() + (newObservedFile.exists()?" file exist size: [" + QString::number(newObservedFile.size()) + " B]" : " file dont exist"));
                }
                // Если файл поменяли
                else if(characteristicsOfObservedFiles[last_i].second != newObservedFile.lastModified())
                {
                    // signal
                    logger->log("File: " + newObservedFile.filePath() + " updated at: " + newObservedFile.lastModified().toString("dd.MM hh:mm:ss") + " size: [" + QString::number(newObservedFile.size()) + " B]" );
                }
            }
        }
        //fileInfoContainer->setNew(newPathsToObservedFiles, newCharacteristicsOfObservedFiles)
        pathsToObservedFiles = newPathsToObservedFiles;
        characteristicsOfObservedFiles = newCharacteristicsOfObservedFiles;
        observationTrigger->wait();
    }
}

