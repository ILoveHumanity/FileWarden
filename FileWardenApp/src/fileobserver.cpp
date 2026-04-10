#include "FileObserver.h"
#include <QDateTime>
#include <QFileInfo>

FileObserver::FileObserver() : observationSource_(nullptr), myFInfoContainer_(nullptr), observationTrigger_(nullptr)
{
}

FileObserver &FileObserver::getInstance(IObservationSource *observationSource, IMyFInfoContainer *myFInfoContainer, IObservationTrigger *observationTrigger)
{
    static FileObserver sObject;
    sObject.setObservationSource(observationSource);
    sObject.setMyFInfoContainer(myFInfoContainer);
    sObject.setObservationTrigger(observationTrigger);
    return sObject;
}

void FileObserver::setObservationSource(IObservationSource *observationSource)
{
    observationSource_ = observationSource;
}

void FileObserver::setMyFInfoContainer(IMyFInfoContainer *myFInfoContainer)
{
    myFInfoContainer_ = myFInfoContainer;
}

void FileObserver::setObservationTrigger(IObservationTrigger *observationTrigger)
{
    observationTrigger_ = observationTrigger;
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

void FileObserver::startObservation()
{
    // Проверяем наличие всех необходимых сущностей
    if (!observationSource_ || !observationTrigger_ || !myFInfoContainer_)
    {
        return;
    }
    // Очищаем хранилище информации
    myFInfoContainer_ -> clear();
    // Получаем начальный список наблюдаемых файлов
    QVector<QString> newPathsToObservedFiles = myFInfoContainer_->getAllPaths();
    QVector<MyFInfo> newObservedFiles;
    while (true)
    {
        // Обновляем список наблюдаемых файлов, в случае ошибки заканчиваем наблюдение
        if(!observationSource_->update(newPathsToObservedFiles))
        {
            return;
        }
        // Очищаем локальное хранилище информации
        newObservedFiles.clear();
        // Для каждого файла устанавливаем его параметры, сравниваем их с предыдущими, генерируя сигналы
        for (int i = 0; i < newPathsToObservedFiles.size(); ++i)
        {
            QFileInfo newFileInfo(newPathsToObservedFiles[i]);
            MyFInfo newObservedFile(newFileInfo.absoluteFilePath(), newFileInfo.isFile() && !newFileInfo.isSymLink(), newFileInfo.lastModified());
            int size = newFileInfo.size();
            newObservedFiles.append(newObservedFile);
            MyFInfo observedFile = myFInfoContainer_->getByPath(newObservedFile.getFilePath());
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
            else if(newObservedFile.getExist() && observedFile.getLastModified() != newObservedFile.getLastModified())
            {
                emit fileUpdate(newObservedFile, size);
            }
        }
        // Устанавливаем новые данные
        myFInfoContainer_->setNewData(newObservedFiles);
        // Ожидаем следующего цикла наблюдения
        observationTrigger_->wait();
    }
}
