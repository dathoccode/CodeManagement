#include "Header.h"
#include "Subject.h"

class VideoData : public Subject
{
private:
    string _title;
    string _URL;
    string _description;
public:
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
        VideoDataChanged("Title changed");
    }
    string GetURL() 
    {
        return this->_URL;
    }
    void SetURL(string URL)
    {
        this->_URL = URL;
        VideoDataChanged("URL changed");
    }
    string GetDescription() 
    {
        return this->_description;
    }
    void SetDescription(string description)
    {
        this->_description = description;
        VideoDataChanged("description changed");
    }
    void VideoDataChanged(string message)
    {
        this->Notify(message);
    }




};

