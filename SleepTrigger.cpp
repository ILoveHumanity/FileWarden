#include "SleepTrigger.h"

SleepTrigger::SleepTrigger(int timeInterval_)
{
    timeInterval = timeInterval_;
}

SleepTrigger::~SleepTrigger()
{

}

void SleepTrigger::wait()
{
    QThread::sleep(timeInterval);
    return;
}
