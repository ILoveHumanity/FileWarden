#ifndef IObservationTrigger_H
#define IObservationTrigger_H
#pragma once

#include <QObject>

/// @brief Абстракция триггера наблюдения.
class IObservationTrigger : public QObject
{
    Q_OBJECT
public:
    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~IObservationTrigger() = default;

signals:
    /// @brief Сигнал о необходимости выполнить наблюдение.
    void doObservation();
};
#endif // IObservationTrigger_H
