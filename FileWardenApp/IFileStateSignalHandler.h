#ifndef IFileStateSignalHandler_H
#define IFileStateSignalHandler_H
#pragma once

#include <QObject>
#include <MyFInfo.h>

/// @brief Интерфейс обработчика сигналов состояния файлов.
class IFileStateSignalHandler : public QObject
{
    Q_OBJECT
public:
    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~IFileStateSignalHandler() = default;

public slots:
    /// @brief Обработчик события существования файла.
    /// @param[in] data Информация о файле
    /// @param[in] size Размер файла в байтах
    virtual void onFileExistence(const MyFInfo& data, const int size) = 0;

    /// @brief Обработчик события обновления файла.
    /// @param[in] data Информация о файле
    /// @param[in] size Новый размер файла в байтах
    virtual void onFileUpdate(const MyFInfo& data, const int size) = 0;

    /// @brief Обработчик события отсутствия файла.
    /// @param[in] data Информация о файле
    virtual void onFileMissing(const MyFInfo& data) = 0;
};


#endif // IFileStateSignalHandler_H
