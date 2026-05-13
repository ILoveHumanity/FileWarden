#include "SleepObservationTrigger.h"
#include <QThread>
#include <QMetaMethod>

SleepObservationTrigger::SleepObservationTrigger(unsigned int timeInterval) : timeInterval_(timeInterval)
{
}

void SleepObservationTrigger::start()
{
    // Пока есть подключенные к триггеру, каждые timeInterval_ инициирует сигнал
    while (isSignalConnected(QMetaMethod::fromSignal(&SleepObservationTrigger::doObservation))) {
        QThread::msleep(timeInterval_);
        emit doObservation();
    }
    return;
}

