#ifndef ObservationSourceFile_H
#define ObservationSourceFile_H
#pragma once

#include "IObservationSource.h"
#include "MyFInfo.h"
#include <QDateTime>

/// @brief Источник списка наблюдения из текстового файла.
/// Реализация интерфейса IObservationSource
class ObservationSourceFile : public IObservationSource
{
public:
    /// @brief Конструктор.
    /// @param[in] sourceFilePath Путь к файлу со списком путей для наблюдения.
    ObservationSourceFile(QString sourceFilePath);

    /// @brief Деструктор.
    ~ObservationSourceFile() = default;

    /// @brief Обновить список путей для наблюдения.
    /// @param[in,out] newPathsToObservedFiles Вектор для сохранения новых путей
    /// @return true в случае успешного обновления, false при ошибке
    bool update(QVector<MyFInfo>& observedFiles);

private:
    QString sourceFilePath_; ///< Путь к файлу со списком наблюдения.
    QDateTime lastModified_; ///< Время последнего изменения.
};

#endif // ObservationSourceFile_H
