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

bool ObservationSourceFile::update(QVector<MyFInfo>& observedFiles)
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
        lastModified_ = sourceFileInfo.lastModified();
        QFile sourceFile(sourceFilePath_);
        // Иначе обновляем данные читая с файла
        if (sourceFile.open(QIODevice::ReadOnly | QIODevice::ExistingOnly | QIODevice::Text))
        {
            QVector<MyFInfo> newObservedFiles;
            QTextStream inFile(&sourceFile);
            while (!inFile.atEnd())
            {
                QString newFilePath = inFile.readLine();
                if (newFilePath.isEmpty())
                {
                    continue;
                }
                MyFInfo newMyFInfo;
                newMyFInfo.filePath_ = QFileInfo(newFilePath).absoluteFilePath();
                if(newObservedFiles.indexOf(newMyFInfo) == -1) // Проверяем на повторы
                {
                    int i = observedFiles.indexOf(newMyFInfo); // Проверяем на наличие в предыдущем списке наблюдения
                    if(i == -1)
                    {
                        newMyFInfo.notObserved_ = true;
                        newObservedFiles.append(newMyFInfo);
                    }
                    else
                    {
                        newObservedFiles.append(observedFiles[i]);
                    }
                }
            }
            sourceFile.close();
            observedFiles = newObservedFiles;
            return true;
        }
    }
    return false;
}
