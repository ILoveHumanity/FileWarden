#ifndef MyFInfo_H
#define MyFInfo_H
#pragma once

#include <QString>
#include <QDateTime>

/// @brief Класс для хранения информации о файле.
class MyFInfo
{
public:
    /// @brief Конструктор с параметрами по умолчанию.
    /// @param[in] filePath Путь к файлу (по умолчанию пустая строка)
    /// @param[in] exist Флаг существования файла (по умолчанию false)
    /// @param[in] lastModified Время последней модификации файла (по умолчанию пустая)
    MyFInfo(QString filePath = QString(), bool exist = false, QDateTime lastModified = QDateTime());

    /// @brief Деструктор.
    ~MyFInfo() = default;

    /// @brief Конструктор копирования.
    /// @param[in] a Источник копирования
    MyFInfo(const MyFInfo& a);

    /// @brief Оператор присваивания.
    /// @param[in] a Источник присваивания
    /// @return Ссылка на объект
    MyFInfo& operator = (const MyFInfo& a);

    /// @brief Получить путь к файлу.
    /// @return Путь к файлу
    QString getFilePath() const;

    /// @brief Получить флаг существования файла.
    /// @return Флаг существования файла
    bool getExist() const;

    /// @brief Получить время последней модификации файла.
    /// @return Время последней модификации файла
    QDateTime getLastModified() const;

    /// @brief Проверить, является ли объект нулевым.
    /// @details Объект считается нулевым, если путь пустой, флаг существования равен false и время последней модификации не установленно
    /// @return true, если объект нулевой, иначе false
    bool isNull() const;

private:
    QString filePath_; ///< Путь к файлу.
    bool exist_;  ///< Флаг существования файла.
    QDateTime lastModified_; ///< Время последней модификации файла.
};

#endif // MyFInfo_H
