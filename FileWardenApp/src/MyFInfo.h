#ifndef MyFInfo_H
#define MyFInfo_H
#pragma once

#include <QString>
#include <QDateTime>

/// @brief Структура для хранения информации о файле.
struct MyFInfo
{
    bool notObserved_; ///< Флаг добавления файла под наблюдение.
    QString filePath_; ///< Путь к файлу.
    bool exist_; ///< Флаг существования файла.
    QDateTime lastModified_; ///< Время последней модификации файла.

    bool operator== (const MyFInfo& a){
        return filePath_ == a.filePath_;
    }
};

#endif // MyFInfo_H
