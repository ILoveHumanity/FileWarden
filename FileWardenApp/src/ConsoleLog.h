#ifndef ConsoleLog_H
#define ConsoleLog_H
#pragma once

#include "ILog.h"

class ConsoleLog : public ILog
{
public:
    ~ConsoleLog() = default;
    ConsoleLog() = default;
    void log(QString data);
};

#endif // ConsoleLog_H
