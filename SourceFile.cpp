#include "SourceFile.h"

SourceFile::SourceFile(QString externalSourceFilePath)
{
    sourceFilePath = externalSourceFilePath;
}

SourceFile::~SourceFile()
{

}

void SourceFile::update(QVector<QString>& pathsToObservedFiles_)
{
    QFile sourceFile(sourceFilePath);

    // open file for reading
    if (sourceFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        pathsToObservedFiles_.clear();
        QTextStream inFile(&sourceFile);
        while (!inFile.atEnd())
        {
            QString newFilePath = inFile.readLine();
            if (newFilePath.isEmpty())
            {
                continue;
            }
            newFilePath = QFileInfo(newFilePath).absoluteFilePath();
            if(pathsToObservedFiles_.indexOf(newFilePath) == -1){
                pathsToObservedFiles_.append(newFilePath);
            }
        }
    }
    return;
}
