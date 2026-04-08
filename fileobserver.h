#ifndef FileObserver_H
#define FileObserver_H
#pragma once

#include "IFileStateSignalHandler.h"
#include "IObservationSource.h"
#include "IObservationTrigger.h"
#include "IMyFInfoContainer.h"
#include "MyFInfo.h"
#include <QDateTime>
#include <QFileInfo>
#include <QObject>

class FileObserver : public QObject
{
    Q_OBJECT
private:
    IObservationSource *observationSource;
    IMyFInfoContainer *myFInfoContainer;
    IObservationTrigger *observationTrigger;
    IFileStateSignalHandler *fileStateSignalHandler;

private:
    FileObserver();
    ~FileObserver();
    FileObserver(const FileObserver &) = delete;
    FileObserver &operator=(const FileObserver &) = delete;

public:
    static FileObserver& GetInstance(IObservationSource *observationSource_, IMyFInfoContainer *myFInfoContainer_, IObservationTrigger *observationTrigger_, IFileStateSignalHandler *fileStateSignalHandler_);
    void setObservationSource(IObservationSource *observationSource_);
    void setMyFInfoContainer(IMyFInfoContainer *myFInfoContainer_);
    void setObservationTrigger(IObservationTrigger *observationTrigger_);
    void setFileStateSignalHandler(IFileStateSignalHandler *fileStateSignalHandler_);
    void startObservation();

signals:
    void fileExist(const MyFInfo& data, const int& size);
    void fileUpdate(const MyFInfo& data, const int& size);
    void fileMissing(const MyFInfo& data);
};

#endif // FileObserver_H
