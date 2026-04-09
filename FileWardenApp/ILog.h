#ifndef ILog_H
#define ILog_H
#pragma once

#include <QObject>
#include <QString>

/// @brief Интерфейс логирования.
class ILog
{
public:
    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~ILog() = default;

    /// @brief Записывает сообщение в лог.
    /// @param[in] data Текстовая информация для записи
    virtual void log(QString data) = 0;
};

#endif // ILog_H
