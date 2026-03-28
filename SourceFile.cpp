#include "SourceFile.h"

SourceFile::SourceFile(QString externalSourceFilePath)
{
    sourceFilePath = externalSourceFilePath;
}

SourceFile::~SourceFile()
{

}

void SourceFile::update(QVector<QString>& newPathsToObservedFiles)
{
    QFile sourceFile(sourceFilePath);

    // open file for reading
    if (sourceFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        newPathsToObservedFiles.clear();
        QTextStream inFile(&sourceFile);
        while (!inFile.atEnd())
        {
            QString newFilePath = inFile.readLine();
            if (newFilePath.isEmpty())
            {
                continue;
            }
            newFilePath = QFileInfo(newFilePath).absoluteFilePath();
            if(newPathsToObservedFiles.indexOf(newFilePath) == -1){
                newPathsToObservedFiles.append(newFilePath);
            }
        }
    }
    return;
}
