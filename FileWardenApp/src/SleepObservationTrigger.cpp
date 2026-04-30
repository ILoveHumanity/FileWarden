#include "SleepObservationTrigger.h"
#include <QThread>
#include <QMetaMethod>

SleepObservationTrigger::SleepObservationTrigger(unsigned int timeInterval) : timeInterval_(timeInterval)
{
}

void SleepObservationTrigger::start()
{
    while (isSignalConnected(QMetaMethod::fromSignal(&SleepObservationTrigger::doObservation))) {
        QThread::msleep(timeInterval_);
        emit doObservation();
    }
    return;
}

