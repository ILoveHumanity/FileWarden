#ifndef IObservationTrigger_H
#define IObservationTrigger_H
#pragma once

/// @brief Интерфейс триггера задержки между циклами наблюдения.
class IObservationTrigger
{
public:
    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~IObservationTrigger() = default;

    /// @brief Ожидание перед следующим циклом наблюдения.
    virtual void wait() = 0;
};
#endif // IObservationTrigger_H
