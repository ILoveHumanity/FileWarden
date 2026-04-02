#include "MyFInfoVectorContainer.h"

MyFInfoVectorContainer::MyFInfoVectorContainer()
{
    VFilePath = QVector<QString>();
    VExist = QVector<bool>();
    VLastUpdated = QVector<QDateTime>();
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
    return MyFInfo(VFilePath[i], VExist[i], VLastUpdated[i]);
}
void MyFInfoVectorContainer::setNewData(const QVector<MyFInfo>& newData)
{
    VFilePath.clear();
    VFilePath.squeeze();
    VExist.clear();
    VExist.squeeze();
    VLastUpdated.clear();
    VLastUpdated.squeeze();
    for (int i = 0; i < newData.size(); ++i){
        VFilePath.append(newData[i].getFilePath());
        VExist.append(newData[i].getExist());
        VLastUpdated.append(newData[i].getLastUpdated());
    }
}
