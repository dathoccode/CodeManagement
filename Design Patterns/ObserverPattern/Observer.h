#pragma once
#include "Header.h"
#include "Subject.h"

class ObserverInterface
{
private:
public:
    virtual void Update() = 0;
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
    void Update() override
    {
        cout << _observerID << " notified for: " << endl;
    }

};

int Observer :: _observerCounter = 0;

