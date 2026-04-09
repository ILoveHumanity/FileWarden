#include "ObservationSourceFile.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QFileInfo>

ObservationSourceFile::ObservationSourceFile(QString sourceFilePath)
{
    sourceFilePath_ = sourceFilePath;
    lastModified_ = QDateTime();
}

bool ObservationSourceFile::update(QVector<QString>& pathsToObservedFiles)
{
    QFileInfo sourceFileInfo(sourceFilePath_);
    // Если файл существует
    if(sourceFileInfo.isFile())
    {
        // Если файл не обновлялся выходим сразу
        if(lastModified_ == sourceFileInfo.lastModified())
        {
            return true;
        }
        QFile sourceFile(sourceFilePath_);
        // Иначе обновляем данные читая с файла
        if (sourceFile.open(QIODevice::ReadOnly | QIODevice::ExistingOnly | QIODevice::Text))
        {
            pathsToObservedFiles.clear();
            QTextStream inFile(&sourceFile);
            while (!inFile.atEnd())
            {
                QString newFilePath = inFile.readLine();
                if (newFilePath.isEmpty())
                {
                    continue;
                }
                newFilePath = QFileInfo(newFilePath).absoluteFilePath();
                if(pathsToObservedFiles.indexOf(newFilePath) == -1){
                    pathsToObservedFiles.append(newFilePath);
                }
            }
            sourceFile.close();
            return true;
        }
    }
    return false;
}
