#include "ConsoleLog.h"

ConsoleLog::ConsoleLog()
{

}
ConsoleLog::~ConsoleLog()
{

}
void ConsoleLog::log(QString data)
{
    qDebug() << "Log: " << data;
}
