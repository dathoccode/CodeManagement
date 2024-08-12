#include <iostream>
#include <list>

using namespace std;


class ObserverInterface
{
public:
    virtual void Update() = 0;
    friend class Subject;
    
};

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
        cout << "observer added" << endl;
    }
    void RemoveObserver (ObserverInterface* observer) override
    {
        _observers.remove(observer);
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

class VideoData : public Subject
{
private:
    string _title;
    string _URL;
    string _description;

public:
    VideoData() 
    {
    }
    VideoData(string title, string URL, string description)
    {
        this->_title = title;
        this->_URL = URL;
        this->_description = description;
    }
    string GetTitle()
    {
        return this->_title;
    }
    void SetTitle(string title)
    {
        this->_title = title;
        this->VideoDataChanged();
    }
    string GetURL()
    {
        return this->_URL;
    }
    void SetURL(string URL)
    {
        this->_URL = URL;
        this->VideoDataChanged();
    }
    string GetDescription()
    {
        return this->_description;
    }
    void SetDescription(string description)
    {
        this->_description = description;
        this->VideoDataChanged();
    }
    void VideoDataChanged()
    {
        this->Notify();
    }
};


class Observer : public ObserverInterface
{
private:
    Subject *_subject;
    int _observerID;
    static int _observerCounter;
public:
    Observer()
    {
        _observerID = ++_observerCounter;

    }
    void Update() override
    {
        cout << _observerID << " notified for data change: " << endl;
    }

};

int Observer :: _observerCounter = 0;

int main()
{
    VideoData *video = new VideoData("hongngoc", "yt/hngocne", "this is for her");
    video->AddObserver(new Observer());
    video->SetTitle("new title");
    return 0;
}


