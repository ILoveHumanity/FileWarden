#ifndef ConsoleLog_H
#define ConsoleLog_H
#pragma once

#include "ILog.h"

/// @brief Класс для логирования сообщений в консоль.
/// Реализация интерфейса ILog
class ConsoleLog : public ILog
{
public:
    /// @brief Конструктор.
    ConsoleLog() = default;

    /// @brief Деструктор.
    ~ConsoleLog() = default;

    /// @brief Записать информацию в консоль.
    /// @param[in] data Текстовая информация для записи
    void log(QString data);
};

#endif // ConsoleLog_H
