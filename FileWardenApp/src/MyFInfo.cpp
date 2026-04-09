#include "MyFInfo.h"

MyFInfo::MyFInfo(QString filePath, bool exist, QDateTime lastModified)
{
    filePath_ = filePath;
    exist_ = exist;
    lastModified_ = lastModified;
}
MyFInfo::~MyFInfo()
{

}
MyFInfo::MyFInfo(const MyFInfo& a)
{
    filePath_ = a.filePath_;
    exist_ = a.exist_;
    lastModified_ = a.lastModified_;
}
MyFInfo& MyFInfo::operator = (const MyFInfo& a)
{
    if (this != &a) {
        filePath_ = a.filePath_;
        exist_ = a.exist_;
        lastModified_ = a.lastModified_;
    }
    return *this;
}
QString MyFInfo::getFilePath() const
{
    return filePath_;
}
bool MyFInfo::getExist() const
{
    return exist_;
}
QDateTime MyFInfo::getLastModified() const
{
    return lastModified_;
}
bool MyFInfo::isNull() const
{
    return filePath_.isNull() && !exist_ && lastModified_.isNull();
}
