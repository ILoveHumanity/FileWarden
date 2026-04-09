#include "MyFInfoVectorContainer.h"
#include <QDateTime>

MyFInfoVectorContainer::MyFInfoVectorContainer()
{
    VFilePath_ = QVector<QString>();
    VExist_ = QVector<bool>();
    VLastModified_ = QVector<QDateTime>();
}
MyFInfo MyFInfoVectorContainer::getByPath(const QString& filePath)
{
    int i = VFilePath_.indexOf(filePath);
    if (i == -1){
        return MyFInfo();
    }
    return MyFInfo(VFilePath_[i], VExist_[i], VLastModified_[i]);
}
void MyFInfoVectorContainer::setNewData(const QVector<MyFInfo>& data)
{
    VFilePath_.clear();
    VExist_.clear();
    VLastModified_.clear();
    for (int i = 0; i < data.size(); ++i){
        VFilePath_.append(data[i].getFilePath());
        VExist_.append(data[i].getExist());
        VLastModified_.append(data[i].getLastModified());
    }
    VFilePath_.squeeze();
    VExist_.squeeze();
    VLastModified_.squeeze();
}
QVector<QString> MyFInfoVectorContainer::getAllPaths()
{
    return VFilePath_;
}
void MyFInfoVectorContainer::clear()
{
    VFilePath_.clear();
    VFilePath_.squeeze();
    VExist_.clear();
    VExist_.squeeze();
    VLastModified_.clear();
    VLastModified_.squeeze();
}
