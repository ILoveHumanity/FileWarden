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
    SourceFile(QString sourceFilePath_);
    ~SourceFile();
    bool update(QVector<QString>& pathsToObservedFiles_);
};

#endif // SourceFile_H
