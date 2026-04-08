#include "MyFInfoVectorContainer.h"

MyFInfoVectorContainer::MyFInfoVectorContainer()
{
    VFilePath = QVector<QString>();
    VExist = QVector<bool>();
    VLastModified = QVector<QDateTime>();
}
MyFInfoVectorContainer::~MyFInfoVectorContainer()
{

}
MyFInfo MyFInfoVectorContainer::getByPath(const QString& filePath_)
{
    int i = VFilePath.indexOf(filePath_);
    if (i == -1){
        return MyFInfo();
    }
    return MyFInfo(VFilePath[i], VExist[i], VLastModified[i]);
}
void MyFInfoVectorContainer::setNewData(const QVector<MyFInfo>& data_)
{
    VFilePath.clear();
    VExist.clear();
    VLastModified.clear();
    for (int i = 0; i < data_.size(); ++i){
        VFilePath.append(data_[i].getFilePath());
        VExist.append(data_[i].getExist());
        VLastModified.append(data_[i].getLastModified());
    }
    VFilePath.squeeze();
    VExist.squeeze();
    VLastModified.squeeze();
}
QVector<QString> MyFInfoVectorContainer::getAllPaths()
{
    return VFilePath;
}
void MyFInfoVectorContainer::clear()
{
    VFilePath.clear();
    VFilePath.squeeze();
    VExist.clear();
    VExist.squeeze();
    VLastModified.clear();
    VLastModified.squeeze();
}
