#ifndef ObservationSourceFile_H
#define ObservationSourceFile_H
#pragma once

#include <IObservationSource.h>
#include <QDateTime>

class ObservationSourceFile : public IObservationSource
{
public:
    ObservationSourceFile(QString sourceFilePath);
    ~ObservationSourceFile() = default;
    bool update(QVector<QString>& pathsToObservedFiles);

private:
    QString sourceFilePath_;
    QDateTime lastModified_;
};

#endif // ObservationSourceFile_H
