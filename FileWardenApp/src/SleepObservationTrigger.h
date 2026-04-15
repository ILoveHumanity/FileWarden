#ifndef SleepObservationTrigger_H
#define SleepObservationTrigger_H
#pragma once

#include "IObservationTrigger.h"

/// @brief Триггер задержки между циклами наблюдения на основе QThread::msleep.
/// Реализация интерфейса IObservationTrigger
class SleepObservationTrigger : public IObservationTrigger
{
public:
    /// @brief Конструктор с параметром по умолчанию.
    /// @param[in] timeInterval Интервал задержки в миллисекундах (по умолчанию 100 мс).
    SleepObservationTrigger(unsigned int timeInterval = 100);

    /// @brief Деструктор.
    ~SleepObservationTrigger() = default;

    /// @brief Ожидание перед следующим циклом наблюдения.
    void wait();

private:
    unsigned int timeInterval_; ///< Интервал задержки в миллисекундах.

};

#endif // SleepObservationTrigger_H
