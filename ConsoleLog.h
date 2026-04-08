#ifndef ConsoleLog_H
#define ConsoleLog_H
#pragma once

#include "ILog.h"
#include <QTextStream>

class ConsoleLog : public ILog
{
public:
    ~ConsoleLog();
    ConsoleLog();
    void log(QString data);
};

#endif // ConsoleLog_H
