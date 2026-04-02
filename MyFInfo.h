#ifndef MyFInfo_H
#define MyFInfo_H
#pragma once

#include <QString>
#include <QDateTime>

class MyFInfo
{
    QString filePath;
    bool exist;
    QDateTime lastUpdated;
public:
    MyFInfo(QString filePath_ = QString(), bool exist_ = false, QDateTime lastUpdated_ = QDateTime());
    ~MyFInfo();
    MyFInfo(const MyFInfo& a);
    MyFInfo& operator = (const MyFInfo& a);
    QString getFilePath() const;
    bool getExist() const;
    QDateTime getLastUpdated() const;
    bool isNull();
};

#endif // MyFInfo_H
