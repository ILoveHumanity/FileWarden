#include "ConsoleLog.h"

ConsoleLog::ConsoleLog()
{

}
ConsoleLog::~ConsoleLog()
{

}
void ConsoleLog::Log(QString data)
{
    qDebug() << "Log: " << data;
}
