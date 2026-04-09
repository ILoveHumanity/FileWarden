#include "SleepObservationTrigger.h"
#include <QThread>

SleepObservationTrigger::SleepObservationTrigger(unsigned int timeInterval)
{
    timeInterval_ = timeInterval;
}
void SleepObservationTrigger::wait()
{
    QThread::msleep(timeInterval_);
    return;
}
