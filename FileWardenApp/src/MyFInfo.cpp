#include "MyFInfo.h"

MyFInfo::MyFInfo(QString filePath_, bool exist_, QDateTime lastModified_)
{
    filePath = filePath_;
    exist = exist_;
    lastModified = lastModified_;
}
MyFInfo::~MyFInfo()
{

}
MyFInfo::MyFInfo(const MyFInfo& a)
{
    filePath = a.filePath;
    exist = a.exist;
    lastModified = a.lastModified;
}
MyFInfo& MyFInfo::operator = (const MyFInfo& a)
{
    if (this != &a) {
        filePath = a.filePath;
        exist = a.exist;
        lastModified = a.lastModified;
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
QDateTime MyFInfo::getLastModified() const
{
    return lastModified;
}
bool MyFInfo::isNull()
{
    return filePath.isNull() && !exist && lastModified.isNull();
}
