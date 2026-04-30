#include "FileObserver.h"
#include <QDateTime>
#include <QFileInfo>

FileObserver::FileObserver() : observationSource_(nullptr), connection_()
{
}

FileObserver &FileObserver::getInstance()
{
    static FileObserver sObject;
    return sObject;
}

void FileObserver::setObservationSource(IObservationSource *observationSource)
{
    observationSource_ = observationSource;
}

void FileObserver::connectFileStateSignalHandler(const IFileStateSignalHandler *fileStateSignalHandler)
{
    if(fileStateSignalHandler)
    {
        connect(this, &FileObserver::fileExist, fileStateSignalHandler, &IFileStateSignalHandler::onFileExistence);
        connect(this, &FileObserver::fileUpdate, fileStateSignalHandler, &IFileStateSignalHandler::onFileUpdate);
        connect(this, &FileObserver::fileMissing, fileStateSignalHandler, &IFileStateSignalHandler::onFileMissing);
    }
}

bool FileObserver::startObservation(const IObservationTrigger *observationTrigger)
{
    // Проверяем наличие всех необходимых сущностей
    if (!observationTrigger)
    {
        return false;
    }
    // Очищаем хранилище информации
    observedFiles_.clear();

    connection_ = connect(observationTrigger, &IObservationTrigger::doObservation, this, &FileObserver::onDoObservation);
    return true;
}

void FileObserver::onDoObservation()
{
    // Обновляем список наблюдаемых файлов, в случае ошибки заканчиваем наблюдение
    if(!observationSource_->update(observedFiles_))
    {
        disconnect(connection_);
        return;
    }

    // Для каждого файла устанавливаем его параметры, сравниваем их с предыдущими, генерируя сигналы
    for (int i = 0; i < observedFiles_.size(); ++i)
    {
        QFileInfo newFileInfo(observedFiles_[i].filePath_);
        bool newObservedFileExist = newFileInfo.isFile() && !newFileInfo.isSymLink() && newFileInfo.size() != 0;
        QDateTime newObservedFileLastModified = newFileInfo.lastModified();
        int newObservedFileSize = newFileInfo.size();
        // Если файл добавился под наблюдение || Если файл удалили/создали
        if (observedFiles_[i].notObserved_ || observedFiles_[i].exist_ != newObservedFileExist)
        {
            if(newObservedFileExist)
            {
                emit fileExist(observedFiles_[i].filePath_, newObservedFileSize);
            }
            else
            {
                emit fileMissing(observedFiles_[i].filePath_);
            }
        }
        // Если файл изменился
        else if(newObservedFileExist && observedFiles_[i].lastModified_ != newObservedFileLastModified)
        {
            emit fileUpdate(observedFiles_[i].filePath_, newObservedFileLastModified, newObservedFileSize);
        }
        // Устанавливаем новые данные
        observedFiles_[i].notObserved_ = false;
        observedFiles_[i].exist_ = newObservedFileExist;
        observedFiles_[i].lastModified_ = newObservedFileLastModified;
    }
}
