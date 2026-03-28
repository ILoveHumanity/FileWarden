#ifndef IObservationTrigger_H
#define IObservationTrigger_H
#pragma once

//#include <QString>

class IObservationTrigger
{
public:
    virtual ~IObservationTrigger() = default;
    virtual void wait() = 0;
};
#endif // IObservationTrigger_H
