#ifndef FileObserver_H
#define FileObserver_H
#pragma once

#include "IFileStateSignalHandler.h"
#include "IObservationSource.h"
#include "IObservationTrigger.h"
#include "IMyFInfoContainer.h"
#include "MyFInfo.h"
#include <QObject>

/// @brief Класс для наблюдения за состоянием файлов.
/// Управляет циклом наблюдения, отслеживает изменения файлов и сигнализирует о событиях через Qt-сигналы
class FileObserver : public QObject
{
    Q_OBJECT
public:
    /// @brief Метод для получения единственного экземпляра наблюдателя.
    /// @return Ссылка на единственный экземпляр FileObserve
    static FileObserver& getInstance();

    /// @brief Установить источник списка наблюдения.
    /// @param[in] observationSource Указатель на источник списка наблюдения
    void setObservationSource(IObservationSource *observationSource);

    /// @brief Установить контейнер для хранения информации о файлах.
    /// @param[in] myFInfoContainer Указатель на контейнер для хранения информации о файлах
    void setMyFInfoContainer(IMyFInfoContainer *myFInfoContainer);

    /// @brief Установить триггер задержки между циклами наблюдения.
    /// @param[in] observationTrigger Указатель на триггер задержки между циклами наблюдения
    void setObservationTrigger(IObservationTrigger *observationTrigger);

    /// @brief Подключить обработчик сигналов состояния файлов.
    /// @param[in] fileStateSignalHandler Указатель на обработчик сигналов состояния файлов
    void connectFileStateSignalHandler(const IFileStateSignalHandler *fileStateSignalHandler);

    /// @brief Запустить бесконечный цикл наблюдения за файлами.
    void startObservation();

private:
    /// @brief Конструктор.
    FileObserver();

    /// @brief Деструктор.
    ~FileObserver() = default;

    FileObserver(const FileObserver &) = delete; // Запрещаем копирование
    FileObserver &operator=(const FileObserver &) = delete;  // Запрещаем присвоение

private:
    IObservationSource *observationSource_; ///< Указатель на источник списка наблюдения.
    IMyFInfoContainer *myFInfoContainer_; ///< Указатель на контейнер для хранения информации о файлах.
    IObservationTrigger *observationTrigger_; ///< Указатель на триггер цикла наблюдения.

signals:
    /// @brief Сигнал о существовании файла.
    /// @param[in] data Информация о файле
    /// @param[in] size Размер файла в байтах
    void fileExist(const MyFInfo& data, const int size);

    /// @brief Сигнал об обновлении файла.
    /// @param[in] data Информация о файле
    /// @param[in] size Новый размер файла в байтах
    void fileUpdate(const MyFInfo& data, const int size);

    /// @brief Сигнал об отсутствии файла.
    /// @param[in] data Информация о файле
    void fileMissing(const MyFInfo& data);
};

#endif // FileObserver_H
