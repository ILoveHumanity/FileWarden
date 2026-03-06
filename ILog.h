#pragma once
#include <QString>
#include <qDebug>

class ILog
{
public:
    virtual ~ILog() = default;
    virtual void Log(QString data) = 0;
};

class ConsoleLog : public ILog
{
public:
    ~ConsoleLog() = default;
    ConsoleLog() = default;
    void Log(QString data);
};
