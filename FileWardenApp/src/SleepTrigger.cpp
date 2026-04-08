#include "SleepTrigger.h"

SleepTrigger::SleepTrigger(unsigned int timeInterval_)
{
    timeInterval = timeInterval_;
}

SleepTrigger::~SleepTrigger()
{

}

void SleepTrigger::wait()
{
    QThread::msleep(timeInterval);
    return;
}
