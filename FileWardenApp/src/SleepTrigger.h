#ifndef SleepTrigger_H
#define SleepTrigger_H
#pragma once

#include "IObservationTrigger.h"
#include <QThread>

class SleepTrigger : public IObservationTrigger
{
    unsigned int timeInterval;
public:
    SleepTrigger(unsigned int timeInterval_ = 100);
    ~SleepTrigger();
    void wait();
};

#endif // SleepTrigger_H
