#ifndef IMyFInfoContainer_H
#define IMyFInfoContainer_H
#pragma once

#include <MyFInfo.h>
#include <QVector>
#include <QString>

class IMyFInfoContainer
{
public:
    virtual ~IMyFInfoContainer() = default;
    virtual MyFInfo getByPath(const QString& filePath_) = 0;
    virtual QVector<QString> getAllPaths() = 0;
    virtual void setNewData(const QVector<MyFInfo>& newData) = 0;
    virtual void clear() = 0;
};
#endif // IMyFInfoContainer_H
