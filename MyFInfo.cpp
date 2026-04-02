#include "MyFInfo.h"

MyFInfo::MyFInfo(QString filePath_, bool exist_, QDateTime lastUpdated_)
{
    filePath = filePath_;
    exist = exist_;
    lastUpdated = lastUpdated_;
}
MyFInfo::~MyFInfo()
{

}
MyFInfo::MyFInfo(const MyFInfo& a)
{
    filePath = a.filePath;
    exist = a.exist;
    lastUpdated = a.lastUpdated;
}
MyFInfo& MyFInfo::operator = (const MyFInfo& a)
{
    if (this != &a) {
        filePath = a.filePath;
        exist = a.exist;
        lastUpdated = a.lastUpdated;
    }
    return *this;
}
QString MyFInfo::getFilePath() const
{
    return filePath;
}
bool MyFInfo::getExist() const
{
    return exist;
}
QDateTime MyFInfo::getLastUpdated() const
{
    return lastUpdated;
}
bool MyFInfo::isNull()
{
    return filePath.isNull() && !exist && lastUpdated.isNull();
}
