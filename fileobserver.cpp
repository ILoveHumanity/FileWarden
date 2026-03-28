#include "FileObserver.h"
#include "QDebug"

FileObserver::FileObserver(IObservationSource *observationSource_, IObservationTrigger *observationTrigger_, ILog *logger_)
{
    // initiate variables
    observationSource = observationSource_;
    logger = logger_;
    observationTrigger = observationTrigger_;
}

FileObserver::~FileObserver()
{

}

FileObserver &FileObserver::GetInstance(IObservationSource *observationSource_, IObservationTrigger *observationTrigger_, ILog *logger_)
{
    static FileObserver Sobject(observationSource_, observationTrigger_, logger_);
    return Sobject;
}

void FileObserver::setObservationSource(IObservationSource *observationSource_)
{
    observationSource = observationSource_;
    pathsToObservedFiles.clear();
    characteristicsOfObservedFiles.clear();
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


    QVector<QString> newPathsToObservedFiles;
    QVector<QPair<bool, QDateTime>> newCharacteristicsOfObservedFiles;
    while (true)
    {
        newCharacteristicsOfObservedFiles.clear();
        //newPathsToObservedFiles = pathsToObservedFiles;
        observationSource->update(newPathsToObservedFiles); //getNewPathsToObservedFiles myFileInfoContainer
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

