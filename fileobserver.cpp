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

    QFileInfoList newObservedFiles;
    while (true)
    {
        observationSource->update(newObservedFiles, observedFilesPath);
        for (int i = 0; i < newObservedFiles.size(); ++i)
        {
            newObservedFiles[i].refresh();
            if(logger != nullptr)
            {
                int last_i = observedFiles.indexOf(newObservedFiles[i]);

                //if (last_i >= 0){qDebug() << observedFiles[last_i].isFile() << newObservedFiles[i].isFile();}

                // Если файл добавился под наблюдение
                if (last_i < 0)
                {
                    // signal
                    logger->Log("File: " + newObservedFiles[i].filePath() + " added under observation" + (newObservedFiles[i].exists()?"size: [" + QString::number(newObservedFiles[i].size()) + " B]" : " file dont exist") );
                }
                // Если файл удалили/добавили
                else if(observedFiles[last_i].isFile() != newObservedFiles[i].isFile())
                {
                    // signal
                    logger->Log("File: " + newObservedFiles[i].filePath() + (newObservedFiles[i].exists()?" file exist size: [" + QString::number(newObservedFiles[i].size()) + " B]" : " file dont exist"));
                }
                // Если файл поменяли
                else if(observedFiles[last_i].lastModified() != newObservedFiles[i].lastModified())
                {
                    // signal
                    logger->Log("File: " + newObservedFiles[i].filePath() + " updated at: " + newObservedFiles[i].lastModified().toString("dd.MM hh:mm:ss") + " size: [" + QString::number(newObservedFiles[i].size()) + " B]" );
                }
            }
        }
        observedFiles = newObservedFiles;
        QThread::sleep(fileStateCheckInterval);
    }
}

