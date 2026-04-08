#include "ConsoleLog.h"

ConsoleLog::ConsoleLog()
{

}
ConsoleLog::~ConsoleLog()
{

}
void ConsoleLog::log(QString data)
{
    QTextStream out(stdout);
    out << "[Log]" << data;
    Qt::endl(out);
}
