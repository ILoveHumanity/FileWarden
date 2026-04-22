#include "FileStateSignalHandlerLogger.h"

FileStateSignalHandlerLogger::FileStateSignalHandlerLogger(ILog *logger)
{
    logger_ = logger;
}
void FileStateSignalHandlerLogger::setLogger(ILog *logger)
{
    logger_ = logger;
}
void FileStateSignalHandlerLogger::onFileExistence(const QString& filePath, const int size)
{
    if(logger_)
    {
        logger_ -> log("[EXIST]\t" + filePath + "\tsize: [" + QString::number(size) + " B]");
    }
}
void FileStateSignalHandlerLogger::onFileUpdate(const QString& filePath, const QDateTime& lastModified, const int size)
{
    if(logger_)
    {
        logger_ -> log("[UPDATED]\t" + filePath + "\tsize: [" + QString::number(size) + " B] " + lastModified.toString("dd.MM hh:mm:ss"));
    }
}
void FileStateSignalHandlerLogger::onFileMissing(const QString& filePath)
{
    if(logger_)
    {
        logger_ -> log("[MISSING]\t" + filePath);
    }
}
