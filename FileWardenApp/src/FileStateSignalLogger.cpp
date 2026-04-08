#include "FileStateSignalLogger.h"

FileStateSignalLogger::FileStateSignalLogger(ILog *logger_)
{
    logger = logger_;
}
FileStateSignalLogger::~FileStateSignalLogger()
{

}
void FileStateSignalLogger::setLogger(ILog *logger_)
{
    logger = logger_;
}
void FileStateSignalLogger::onFileExistence(const MyFInfo& data, const int& size)
{
    if(logger)
    {
        logger -> log("[EXIST]\t" + data.getFilePath() + "\tsize: [" + QString::number(size) + " B]");
    }
}
void FileStateSignalLogger::onFileUpdate(const MyFInfo& data, const int& size)
{
    if(logger)
    {
        logger -> log("[UPDATED]\t" + data.getFilePath() + "\tsize: [" + QString::number(size) + " B] " + data.getLastModified().toString("dd.MM hh:mm:ss"));
    }
}
void FileStateSignalLogger::onFileMissing(const MyFInfo& data)
{
    if(logger)
    {
        logger -> log("[MISSING]\t" + data.getFilePath());
    }
}
