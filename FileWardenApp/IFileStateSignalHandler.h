#ifndef IFileStateSignalHandler_H
#define IFileStateSignalHandler_H
#pragma once

#include <QObject>
#include <MyFInfo.h>

    class IFileStateSignalHandler : public QObject
{
    Q_OBJECT
public:
    virtual ~IFileStateSignalHandler() = default;

public slots:
    virtual void onFileExistence(const MyFInfo& data, const int& size) = 0;
    virtual void onFileUpdate(const MyFInfo& data, const int& size) = 0;
    virtual void onFileMissing(const MyFInfo& data) = 0;
};


#endif // IFileStateSignalHandler_H
