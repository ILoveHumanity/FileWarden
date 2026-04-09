#include "FileStateSignalHandlerLogger.h"

FileStateSignalHandlerLogger::FileStateSignalHandlerLogger(ILog *logger)
{
    logger_ = logger;
}
void FileStateSignalHandlerLogger::setLogger(ILog *logger)
{
    logger_ = logger;
}
void FileStateSignalHandlerLogger::onFileExistence(const MyFInfo& data, const int size)
{
    if(logger_)
    {
        logger_ -> log("[EXIST]\t" + data.getFilePath() + "\tsize: [" + QString::number(size) + " B]");
    }
}
void FileStateSignalHandlerLogger::onFileUpdate(const MyFInfo& data, const int size)
{
    if(logger_)
    {
        logger_ -> log("[UPDATED]\t" + data.getFilePath() + "\tsize: [" + QString::number(size) + " B] " + data.getLastModified().toString("dd.MM hh:mm:ss"));
    }
}
void FileStateSignalHandlerLogger::onFileMissing(const MyFInfo& data)
{
    if(logger_)
    {
        logger_ -> log("[MISSING]\t" + data.getFilePath());
    }
}
