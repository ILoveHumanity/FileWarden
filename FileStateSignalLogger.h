#ifndef FileObserverSignalLogger_H
#define FileObserverSignalLogger_H
#pragma once

#include "IFileStateSignalHandler.h"
#include "ILog.h"

class FileStateSignalLogger : public IFileStateSignalHandler
{
    Q_OBJECT
private:
    ILog *logger;
public:
    FileStateSignalLogger(ILog *logger_);
    ~FileStateSignalLogger();
    void setLogger(ILog *logger_);
public slots:
    void onFileExistence(const MyFInfo& data, const int& size);
    void onFileUpdate(const MyFInfo& data, const int& size);
    void onFileMissing(const MyFInfo& data);
};

#endif // FileObserverSignalLogger_H
