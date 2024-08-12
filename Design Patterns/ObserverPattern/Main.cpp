#include "VideoData.h"

int main()
{
    VideoData *ytVideo = new VideoData("hongngoc", "http", "video description");
    ytVideo->AddObserver(new Observer());
    ytVideo->AddObserver(new Observer());
    ytVideo->SetTitle("new title");
    
    return 0;
}