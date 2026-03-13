#ifndef FileObserver_H
#define FileObserver_H
#pragma once

#include "Ilog.h"
#include "IObservationSource.h"
#include <QDateTime>
#include <QTime>
#include <QFileInfo>
#include <QSet>
#include <QThread>


class FileObserver
{
private:
    QFileInfoList observedFiles;
    QSet<QString> observedFilesPath;
    IObservationSource *observationSource;
    ILog *logger;
    unsigned int fileStateCheckInterval = 10;

private:
    FileObserver();
    FileObserver(IObservationSource *observationSource, ILog *logger, unsigned int fileStateCheckInterval);
    ~FileObserver();
    FileObserver(const FileObserver &) = delete;
    FileObserver &operator=(const FileObserver &) = delete;


public:
    static FileObserver& GetInstance(IObservationSource *observationSource, ILog *logger, unsigned int fileStateCheckInterval);

    void setLogger(ILog *logger);
    void setStateCheckInterval(unsigned int interval);

    void startObservation();
};

#endif // FileObserver_H
