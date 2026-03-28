#ifndef ILog_H
#define ILog_H
#pragma once

#include <QString>

class ILog
{
public:
    virtual ~ILog() = default;
    virtual void log(QString data) = 0;
};

#endif // ILog_H
