#include "Header.h"

int main()
{
    BlackPinkConcertTicket *ticket = new BlackPinkConcertTicket();
    ticket->SetPrice(1000);
    cout << ticket->GetPromotedPrice();
    return 0;
}