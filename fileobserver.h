#ifndef FileObserver_H
#define FileObserver_H
#pragma once

#include "Ilog.h"
#include "IObservationSource.h"
#include "IObservationTrigger.h"
#include <QDateTime>
#include <QTime>
#include <QFileInfo>



class FileObserver
{
private:
    QVector<QPair<bool, QDateTime>> characteristicsOfObservedFiles;
    QVector<QString> pathsToObservedFiles;
    IObservationSource *observationSource;
    ILog *logger;
    IObservationTrigger *observationTrigger;

private:
    FileObserver(IObservationSource *observationSource_, IObservationTrigger *observationTrigger_, ILog *logger_);
    ~FileObserver();
    FileObserver(const FileObserver &) = delete;
    FileObserver &operator=(const FileObserver &) = delete;


public:
    static FileObserver& GetInstance(IObservationSource *observationSource_, IObservationTrigger *observationTrigger_, ILog *logger_);
    void setObservationSource(IObservationSource *observationSource_);
    void setLogger(ILog *logger_);
    void setObservationTrigger(IObservationTrigger *observationTrigger_);

    void startObservation();
};

#endif // FileObserver_H
