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
void MyFInfoVectorContainer::setNewData(const QVector<MyFInfo>& newData)
{
    VFilePath.clear();
    VFilePath.squeeze();
    VExist.clear();
    VExist.squeeze();
    VLastModified.clear();
    VLastModified.squeeze();
    for (int i = 0; i < newData.size(); ++i){
        VFilePath.append(newData[i].getFilePath());
        VExist.append(newData[i].getExist());
        VLastModified.append(newData[i].getLastModified());
    }
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
