#include <iostream>

using namespace std;

class IPromoteStrategy
{
public:
    float virtual DoDiscount(float price)
    {
        cout << "default called" << endl;
        return -1;
    }
};

class Ticket
{
private:
    float _price;
    IPromoteStrategy *_promoteStrategy;
public:
    void SetIPromoteStrategy(IPromoteStrategy *strategy)
    {
        this->_promoteStrategy = strategy;
    }
    float GetPromotedPrice()
    {
        return _promoteStrategy->DoDiscount(_price);
    };
    void SetPrice(float price)
    {
        this->_price = price;
    }

};

class NoDiscountStrategy : public IPromoteStrategy
{
public:
    float DoDiscount(float price)
    {
        return price;
    }
};

class HalfDiscountStrategy : public IPromoteStrategy
{
public:
    float DoDiscount(float price)
    {
        return price / 2;
    }
};

class QuartDiscountStrategy : public IPromoteStrategy
{
public:
    float DoDiscount(float price)
    {
        return price / 4;
    }
};

class BlackPinkConcertTicket : public Ticket
{
public:
    BlackPinkConcertTicket()
    {
        this->SetIPromoteStrategy(new HalfDiscountStrategy());
    }
};

int main()
{
    BlackPinkConcertTicket *ticket = new BlackPinkConcertTicket();
    ticket->SetPrice(1000);
    cout << ticket->GetPromotedPrice();
    return 0;
}