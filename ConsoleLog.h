#ifndef ConsoleLog_H
#define ConsoleLog_H
#pragma once

#include "ILog.h"
#include <QTextStream>

class ConsoleLog : public ILog
{
    Q_OBJECT
public:
    ~ConsoleLog();
    ConsoleLog();
    void log(QString data);

public slots:
    void onFileExistence(const MyFInfo& data, const int& size);
    void onFileUpdate(const MyFInfo& data, const int& size);
    void onFileMissing(const MyFInfo& data);
};

#endif // ConsoleLog_H
