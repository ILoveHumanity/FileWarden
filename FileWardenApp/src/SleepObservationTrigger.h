#ifndef SleepObservationTrigger_H
#define SleepObservationTrigger_H
#pragma once

#include "IObservationTrigger.h"

/// @brief Триггер задержки между циклами наблюдения на основе QThread::msleep.
/// Реализация абстракции IObservationTrigger
class SleepObservationTrigger : public IObservationTrigger
{
    Q_OBJECT
public:
    /// @brief Конструктор с параметром по умолчанию.
    /// @param[in] timeInterval Интервал задержки в миллисекундах (по умолчанию 100 мс).
    SleepObservationTrigger(unsigned int timeInterval = 100);

    /// @brief Деструктор.
    ~SleepObservationTrigger() = default;

    /// @brief Запуск бесконечного цикла
    void start();

private:
    unsigned int timeInterval_; ///< Интервал задержки в миллисекундах.
};

#endif // SleepObservationTrigger_H
