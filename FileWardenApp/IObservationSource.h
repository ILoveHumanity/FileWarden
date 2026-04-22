#ifndef IObservationSource_H
#define IObservationSource_H
#pragma once

#include <QVector>
#include "MyFInfo.h"

/// @brief Интерфейс источника списка наблюдения.
class IObservationSource
{
public:
    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~IObservationSource() = default;

    /// @brief Обновить список путей для наблюдения.
    /// @param[in,out] newPathsToObservedFiles Вектор для сохранения новых путей
    /// @return true в случае успешного обновления, false при ошибке
    virtual bool update(QVector<MyFInfo>& observedFiles) = 0;
};

#endif // IObservationSource_H
