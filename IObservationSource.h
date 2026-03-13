#ifndef IObservationSource_H
#define IObservationSource_H
#pragma once

#include <QFileInfo>
#include <QSet>
#include <QString>

class IObservationSource
{
public:
    virtual ~IObservationSource() = default;
    virtual void update(QFileInfoList& newObservedFiles, QSet<QString>& observedFilesPath) = 0;
};

#endif // IObservationSource_H
