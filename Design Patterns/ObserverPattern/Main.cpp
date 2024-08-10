#include "Subject.h"

int main()
{
    Subject *sub1 = new Subject;
    Observer *ob1 = new Observer();
    sub1->AddObserver(ob1);
    sub1->Notify();
    return 0;
}