#pragma once
#include "Header.h"
#include "Observer.h"


class SubjectInterface
{
public:
    virtual void AddObserver(ObserverInterface* observer) = 0;
    virtual void RemoveObserver(ObserverInterface* observer) = 0;
    virtual void Notify(string message) = 0;

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
    void Notify(string message) override
    {
        if(_observers.empty()) return;
        list<ObserverInterface*>::iterator it = _observers.begin();
        while (it != _observers.end())
        {
            (*it)->Update(message);
            it++;

        }
        
    }
};

