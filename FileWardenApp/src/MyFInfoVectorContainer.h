#ifndef MyFInfoVectorContainer_H
#define MyFInfoVectorContainer_H
#pragma once

#include "IMyFInfoContainer.h"
#include "MyFInfo.h"
#include <QVector>
#include <QString>

/// @brief Контейнер для хранения информации о файлах на основе векторов.
/// @details Реализация интерфейса IMyFInfoContainer
class MyFInfoVectorContainer : public IMyFInfoContainer
{
public:
    /// @brief Конструктор.
    MyFInfoVectorContainer();

    /// @brief Деструктор.
    ~MyFInfoVectorContainer() = default;

    /// @brief Получить информацию о файле по пути.
    /// @param[in] filePath_ Путь к файлу
    /// @return Информация о файле если есть, иначе нулевой объект
    virtual MyFInfo getByPath(const QString& filePath_);

    /// @brief Получить список всех путей до файлов в контейнере.
    /// @return Вектор строк с путями до файлов
    virtual QVector<QString> getAllPaths();

    /// @brief Установить новые данные в контейнер.
    /// @param[in] data_ Вектор информации о файлах
    virtual void setNewData(const QVector<MyFInfo>& data_);

    /// @brief Очистить контейнер от всех данных.
    virtual void clear();

private:
    QVector<QString> VFilePath_; ///< Вектор путей к файлам.
    QVector<bool> VExist_; ///< Вектор флагов существования файлов.
    QVector<QDateTime> VLastModified_; ///< Вектор времени последней модификации файлов.
};

#endif // MyFInfoVectorContainer_H
