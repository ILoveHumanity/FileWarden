#ifndef ConsoleLog_H
#define ConsoleLog_H
#pragma once

#include "ILog.h"
#include <qDebug>

class ConsoleLog : public ILog
{
public:
    ~ConsoleLog();
    ConsoleLog();
    void Log(QString data);
};

#endif // ConsoleLog_H
