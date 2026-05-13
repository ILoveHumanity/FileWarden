#include "ConsoleLog.h"
#include <QTextStream>

void ConsoleLog::log(QString data)
{
    QTextStream out(stdout);
    out << "[Log]" << data << Qt::endl;
}
