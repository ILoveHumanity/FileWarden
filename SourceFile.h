#ifndef SourceFile_H
#define SourceFile_H
#pragma once

#include <IObservationSource.h>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

class SourceFile : public IObservationSource
{
    QString sourceFilePath;
public:
    SourceFile(QString externalSourceFilePath);
    ~SourceFile();
    void update(QVector<QString>& newPathsToObservedFiles);
};

#endif // SourceFile_H
