#ifndef MyFInfoVectorContainer_H
#define MyFInfoVectorContainer_H
#pragma once

#include "IMyFInfoContainer.h"
#include "MyFInfo.h"
#include <QVector>
#include <QString>

class MyFInfoVectorContainer : public IMyFInfoContainer
{
public:
    MyFInfoVectorContainer();
    ~MyFInfoVectorContainer() = default;
    MyFInfo getByPath(const QString& filePath);
    void setNewData(const QVector<MyFInfo>& newData);
    QVector<QString> getAllPaths();
    void clear();

private:
    QVector<QString> VFilePath_;
    QVector<bool> VExist_;
    QVector<QDateTime> VLastModified_;
};

#endif // MyFInfoVectorContainer_H
