#include "ILog.h"

void ConsoleLog::Log(QString data)
{
    qDebug() << "Log: " << data;
}
