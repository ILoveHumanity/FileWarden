#ifndef FileStateSignalHandlerLogger_H
#define FileStateSignalHandlerLogger_H
#pragma once

#include "IFileStateSignalHandler.h"
#include "ILog.h"

/// @brief Обработчик сигналов состояния файлов с логированием.
/// Реализация интерфейса IFileStateSignalHandler
class FileStateSignalHandlerLogger : public IFileStateSignalHandler
{
    Q_OBJECT
public:
    /// @brief Конструктор.
    /// @param[in] logger Указатель на интерфейс логирования
    FileStateSignalHandlerLogger(ILog *logger);

    /// @brief Деструктор.
    ~FileStateSignalHandlerLogger() = default;

    /// @brief Установить логгер.
    /// @param[in] logger Указатель на интерфейс логирования
    void setLogger(ILog *logger);

private:
    ILog *logger_; ///< Указатель на интерфейс логирования.

public slots:
    /// @brief Обработчик события существования файла.
    /// @param[in] filePath Путь до файла
    /// @param[in] size Размер файла в байтах
    virtual void onFileExistence(const QString& filePath, const int size);

    /// @brief Обработчик события обновления файла.
    /// @param[in] filePath Путь до файла
    /// @param[in] lastModified Время последнего изменения файла
    /// @param[in] size Новый размер файла в байтах
    virtual void onFileUpdate(const QString& filePath, const QDateTime& lastModified, const int size);

    /// @brief Обработчик события отсутствия файла.
    /// @param[in] filePath Путь до файла
    virtual void onFileMissing(const QString& filePath);
};

#endif // FileStateSignalHandlerLogger_H
