#include "SourceFile.h"

SourceFile::SourceFile(QString externalSourceFilePath)
{
    sourceFilePath = externalSourceFilePath;
}

SourceFile::~SourceFile()
{

}

void SourceFile::update(QFileInfoList& newObservedFiles, QSet<QString>& observedFilesPath)
{
    QFile sourceFile(sourceFilePath);

    // opens file for reading
    if (sourceFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        newObservedFiles.clear();
        observedFilesPath.clear();
        QTextStream inFile(&sourceFile);
        while (!inFile.atEnd())
        {
            QString newFilePath = inFile.readLine();
            if (newFilePath.isEmpty())
            {
                continue;
            }
            observedFilesPath.insert(QFileInfo(newFilePath).absoluteFilePath());
        }
    }
    foreach (const QString &path, observedFilesPath)
    {
        newObservedFiles.append(QFileInfo(path));
    }
    return;
}
