#ifndef IMyFInfoContainer_H
#define IMyFInfoContainer_H
#pragma once

#include <MyFInfo.h>
#include <QVector>
#include <QString>

/// @brief Интерфейс контейнера для хранения информации о файлах.
class IMyFInfoContainer
{
public:
    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~IMyFInfoContainer() = default;

    /// @brief Получить информацию о файле по пути.
    /// @param[in] filePath_ Путь к файлу
    /// @return Информация о файле если есть, иначе нулевой объект
    virtual MyFInfo getByPath(const QString& filePath) = 0;

    /// @brief Получить список всех путей до файлов в контейнере.
    /// @return Вектор строк с путями до файлов
    virtual QVector<QString> getAllPaths() = 0;

    /// @brief Установить новые данные в контейнер.
    /// @param[in] data_ Вектор информации о файлах
    virtual void setNewData(const QVector<MyFInfo>& data) = 0;

    /// @brief Очистить контейнер от всех данных.
    virtual void clear() = 0;
};
#endif // IMyFInfoContainer_H
