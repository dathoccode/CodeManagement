#pragma once
#include "Header.h"
#include "Subject.h"

class ObserverInterface
{
private:
public:
    virtual void Update(string message) = 0;
    friend class Subject;

};

class Observer : public ObserverInterface
{
private:
    int _observerID;
    static int _observerCounter;
public:
    Observer()
    {
        _observerID = ++_observerCounter;
    }
    void Update(string message) override
    {
        cout << _observerID << " notified for: " << message << endl;
    }

};

int Observer :: _observerCounter = 0;

