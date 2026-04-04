#ifndef ILog_H
#define ILog_H
#pragma once

#include <QString>
#include <QObject>
#include <MyFInfo.h>

class ILog : public QObject
{
    Q_OBJECT
public:
    virtual ~ILog() = default;
    virtual void log(QString data) = 0;

public slots:
    virtual void onFileExistence(const MyFInfo& data, const int& size) = 0;
    virtual void onFileUpdate(const MyFInfo& data, const int& size) = 0;
    virtual void onFileMissing(const MyFInfo& data) = 0;
};

#endif // ILog_H
