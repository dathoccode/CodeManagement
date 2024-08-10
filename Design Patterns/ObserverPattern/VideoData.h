#include "Header.h"
#include "Subject.h"

class VideoData : public Subject
{
private:
    string _title;
    string _URL;
    string _description;
public:
    string GetTitle()
    {
        return this->_title;
    }
    void SetTitle(string title)
    {
        this->_title = title;
        void VideoDataChanged();
    }
    string GetURL() 
    {
        return this->_URL;
    }
    void SetURL(string URL)
    {
        this->_URL = URL;
        void VideoDataChanged();
    }
    string GetDescription() 
    {
        return this->_description;
    }
    void SetDescription(string description)
    {
        this->_description = description;
        void VideoDataChanged();
    }
    void VideoDataChanged()
    {
        this->Notify();
    }




};

