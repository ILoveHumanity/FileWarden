#ifndef IObservationSource_H
#define IObservationSource_H
#pragma once

#include <QFileInfo>
#include <QVector>
#include <QString>

class IObservationSource
{
public:
    virtual ~IObservationSource() = default;
    virtual void update(QVector<QString>& newPathsToObservedFiles) = 0;
};

#endif // IObservationSource_H
