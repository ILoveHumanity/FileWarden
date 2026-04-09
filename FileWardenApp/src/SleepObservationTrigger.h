#ifndef SleepObservationTrigger_H
#define SleepObservationTrigger_H
#pragma once

#include "IObservationTrigger.h"

class SleepObservationTrigger : public IObservationTrigger
{
public:
    SleepObservationTrigger(unsigned int timeInterval = 100);
    ~SleepObservationTrigger() = default;
    void wait();

private:
    unsigned int timeInterval_;

};

#endif // SleepObservationTrigger_H
