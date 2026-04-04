#ifndef FileObserver_H
#define FileObserver_H
#pragma once

#include "Ilog.h"
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
    IMyFInfoContainer *observedFiles;
    IObservationSource *observationSource;
    ILog *logger;
    IObservationTrigger *observationTrigger;

private:
    FileObserver(IObservationSource *observationSource_, IMyFInfoContainer *observedFiles, IObservationTrigger *observationTrigger_, ILog *logger_);
    ~FileObserver();
    FileObserver(const FileObserver &) = delete;
    FileObserver &operator=(const FileObserver &) = delete;

public:
    static FileObserver& GetInstance(IObservationSource *observationSource_, IMyFInfoContainer *observedFiles, IObservationTrigger *observationTrigger_, ILog *logger_);
    void setObservationSource(IObservationSource *observationSource_);
    void setLogger(ILog *logger_);
    void setObservationTrigger(IObservationTrigger *observationTrigger_);
    void startObservation();

signals:
    void fileExist(const MyFInfo& data, const int& size);
    void fileUpdate(const MyFInfo& data, const int& size);
    void fileMissing(const MyFInfo& data);
};

#endif // FileObserver_H
