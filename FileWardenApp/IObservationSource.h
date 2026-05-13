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

    /// @brief Обновить список наблюдаемых файлов.
    /// @param[in,out] observedFiles Контейнер с хранящейся информацией о файлах.
    /// @return true в случае успешного обновления, false при ошибке
    virtual bool update(QVector<MyFInfo>& observedFiles) = 0;
};

#endif // IObservationSource_H
