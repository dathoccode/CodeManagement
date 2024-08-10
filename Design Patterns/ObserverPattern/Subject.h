#pragma once
#include "Header.h"
#include "Observer.h"


class SubjectInterface
{
public:
    virtual void AddObserver(ObserverInterface* observer) = 0;
    virtual void RemoveObserver(ObserverInterface* observer) = 0;
    virtual void Notify() = 0;

};


class Subject : public SubjectInterface
{
private:
    list<ObserverInterface*> _observers;


public:
    void AddObserver (ObserverInterface* observer) override
    {
        _observers.push_back(observer);
    }
    void RemoveObserver (ObserverInterface* observer) override
    {
        _observers.push_back(observer);
    }
    void Notify() override
    {
        if(_observers.empty()) return;
        list<ObserverInterface*>::iterator it = _observers.begin();
        while (it != _observers.end())
        {
            (*it)->Update();
            it++;

        }
        
    }
};

