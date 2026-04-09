#ifndef FileObserver_H
#define FileObserver_H
#pragma once

#include "IFileStateSignalHandler.h"
#include "IObservationSource.h"
#include "IObservationTrigger.h"
#include "IMyFInfoContainer.h"
#include "MyFInfo.h"
#include <QObject>

class FileObserver : public QObject
{
    Q_OBJECT
public:
    static FileObserver& getInstance(IObservationSource *observationSource, IMyFInfoContainer *myFInfoContainer, IObservationTrigger *observationTrigger, IFileStateSignalHandler *fileStateSignalHandler);
    void setObservationSource(IObservationSource *observationSource);
    void setMyFInfoContainer(IMyFInfoContainer *myFInfoContainer);
    void setObservationTrigger(IObservationTrigger *observationTrigger);
    void setFileStateSignalHandler(IFileStateSignalHandler *fileStateSignalHandler);
    void startObservation();

private:
    FileObserver();
    ~FileObserver() = default;
    FileObserver(const FileObserver &) = delete;
    FileObserver &operator=(const FileObserver &) = delete;

private:
    IObservationSource *observationSource_;
    IMyFInfoContainer *myFInfoContainer_;
    IObservationTrigger *observationTrigger_;
    IFileStateSignalHandler *fileStateSignalHandler_;

signals:
    void fileExist(const MyFInfo& data, const int& size);
    void fileUpdate(const MyFInfo& data, const int& size);
    void fileMissing(const MyFInfo& data);
};

#endif // FileObserver_H
