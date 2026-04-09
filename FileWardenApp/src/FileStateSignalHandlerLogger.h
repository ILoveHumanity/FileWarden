#ifndef FileStateSignalHandlerLogger_H
#define FileStateSignalHandlerLogger_H
#pragma once

#include "IFileStateSignalHandler.h"
#include "ILog.h"

class FileStateSignalHandlerLogger : public IFileStateSignalHandler
{
    Q_OBJECT
public:
    FileStateSignalHandlerLogger(ILog *logger);
    ~FileStateSignalHandlerLogger() = default;
    void setLogger(ILog *logger);

private:
    ILog *logger_;

public slots:
    void onFileExistence(const MyFInfo& data, const int size);
    void onFileUpdate(const MyFInfo& data, const int size);
    void onFileMissing(const MyFInfo& data);
};

#endif // FileStateSignalHandlerLogger_H
