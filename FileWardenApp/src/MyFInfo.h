#ifndef MyFInfo_H
#define MyFInfo_H
#pragma once

#include <QString>
#include <QDateTime>

class MyFInfo
{
    QString filePath_;
    bool exist_;
    QDateTime lastModified_;
public:
    MyFInfo(QString filePath = QString(), bool exist = false, QDateTime lastModified = QDateTime());
    ~MyFInfo();
    MyFInfo(const MyFInfo& a);
    MyFInfo& operator = (const MyFInfo& a);
    QString getFilePath() const;
    bool getExist() const;
    QDateTime getLastModified() const;
    bool isNull() const;
};

#endif // MyFInfo_H
