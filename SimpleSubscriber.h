#pragma once
#include "Person.h"
#include "Subscriber.h"
class SimpleSubscriber :
    public Subscriber
{
private:
    const int MAX_SEATS_IN_SECTION = 500;
    bool isInterstedUpgrade;
public:
    SimpleSubscriber(const char* Name);
    SimpleSubscriber(const SimpleSubscriber& other); //cpoy
    SimpleSubscriber(SimpleSubscriber&& other) noexcept; //move
    SimpleSubscriber& operator=(const SimpleSubscriber& other); // assignment operator
    void print(void) const;
    virtual ~SimpleSubscriber(void);
    bool getUpgradeIntrest() { return isInterstedUpgrade; };
    void setUpgradeInterest(bool update) { isInterstedUpgrade = update; };
    void showPrivalges(void) const;
    SimpleSubscriber* clone() const { return new SimpleSubscriber(*this); };
    const char* getType() { return "simple subscriber"; };
};





