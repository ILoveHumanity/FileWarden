#ifndef MyFInfoVectorContainer_H
#define MyFInfoVectorContainer_H
#pragma once

#include "IMyFInfoContainer.h"
#include "MyFInfo.h"
#include <QVector>
#include <QString>
#include <QDateTime>

class MyFInfoVectorContainer : public IMyFInfoContainer
{
    QVector<QString> VFilePath;
    QVector<bool> VExist;
    QVector<QDateTime> VLastModified;
public:
    MyFInfoVectorContainer();
    ~MyFInfoVectorContainer();
    MyFInfo getByPath(const QString& filePath_);
    void setNewData(const QVector<MyFInfo>& newData);
    QVector<QString> getAllPaths();
    void clear();
};

#endif // MyFInfoVectorContainer_H
