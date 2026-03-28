#include "FileObserver.h"
#include "QDebug"

FileObserver::FileObserver(IObservationSource *externalObservationSource, ILog *external_logger, unsigned int interval)
{
    // initiate variables
    observationSource = externalObservationSource;
    logger = external_logger;
    fileStateCheckInterval = interval;
}

FileObserver::~FileObserver()
{

}

FileObserver &FileObserver::GetInstance(IObservationSource *externalObservationSource, ILog *external_logger, unsigned int interval = 5)
{
    static FileObserver Sobject(externalObservationSource, external_logger, interval);
    return Sobject;
}


void FileObserver::setLogger(ILog *external_logger)
{
    logger = external_logger;
}

void FileObserver::setStateCheckInterval(unsigned int interval)
{
    fileStateCheckInterval = interval;
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
                    logger->Log("File: " + newObservedFile.filePath() + " added under observation" + (newObservedFile.exists()?" size: [" + QString::number(newObservedFile.size()) + " B]" : " file dont exist") );
                }
                // Если файл удалили/добавили
                else if(characteristicsOfObservedFiles[last_i].first != newObservedFile.exists())
                {
                    // signal
                    logger->Log("File: " + newObservedFile.filePath() + (newObservedFile.exists()?" file exist size: [" + QString::number(newObservedFile.size()) + " B]" : " file dont exist"));
                }
                // Если файл поменяли
                else if(characteristicsOfObservedFiles[last_i].second != newObservedFile.lastModified())
                {
                    // signal
                    logger->Log("File: " + newObservedFile.filePath() + " updated at: " + newObservedFile.lastModified().toString("dd.MM hh:mm:ss") + " size: [" + QString::number(newObservedFile.size()) + " B]" );
                }
            }
        }
        //fileInfoContainer->setNew(newPathsToObservedFiles, newCharacteristicsOfObservedFiles)
        pathsToObservedFiles = newPathsToObservedFiles;
        characteristicsOfObservedFiles = newCharacteristicsOfObservedFiles;
        QThread::sleep(fileStateCheckInterval);
    }
}

