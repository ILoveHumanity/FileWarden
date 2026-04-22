#ifndef IFileStateSignalHandler_H
#define IFileStateSignalHandler_H
#pragma once

#include <QObject>
#include <QString>
#include <QDateTime>

/// @brief Интерфейс обработчика сигналов состояния файлов.
class IFileStateSignalHandler : public QObject
{
    Q_OBJECT
public:
    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~IFileStateSignalHandler() = default;

public slots:
    /// @brief Обработчик события существования файла.
    /// @param[in] filePath Путь до файла
    /// @param[in] size Размер файла в байтах
    virtual void onFileExistence(const QString& filePath, const int size) = 0;

    /// @brief Обработчик события обновления файла.
    /// @param[in] filePath Путь до файла
    /// @param[in] lastModified Время последнего изменения файла
    /// @param[in] size Новый размер файла в байтах
    virtual void onFileUpdate(const QString& filePath, const QDateTime& lastModified, const int size) = 0;

    /// @brief Обработчик события отсутствия файла.
    /// @param[in] filePath Путь до файла
    virtual void onFileMissing(const QString& filePath) = 0;
};


#endif // IFileStateSignalHandler_H
