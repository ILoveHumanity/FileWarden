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
    QVector<QDateTime> VLastUpdated;
public:
    MyFInfoVectorContainer();
    ~MyFInfoVectorContainer();
    MyFInfo getByPath(const QString& filePath_) = 0;
    void setNewData(const QVector<MyFInfo>& newData) = 0;
};

#endif // MyFInfoVectorContainer_H
