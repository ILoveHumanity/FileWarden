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
void ConsoleLog::onFileExistence(const MyFInfo& data, const int& size)
{
    log("[EXIST]\t" + data.getFilePath() + "\tsize: [" + QString::number(size) + " B]");
}
void ConsoleLog::onFileUpdate(const MyFInfo& data, const int& size)
{
    log("[UPDATED]\t" + data.getFilePath() + "\tsize: [" + QString::number(size) + " B] " + data.getLastModified().toString("dd.MM hh:mm:ss"));
}
void ConsoleLog::onFileMissing(const MyFInfo& data)
{
    log("[MISSING]\t" + data.getFilePath());
}
