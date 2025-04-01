#pragma once
#include "Subscriber.h"
class SilverSubscriber :
    public Subscriber
{
private:
    enum Meal { chicken, steak, fish, lubster};
    const int MAX_SEATS_IN_SECTION = 300;
    bool isInterstedUpgrade;
    Meal theMealToday;
public:
    SilverSubscriber(const char* Name);
    SilverSubscriber(const SilverSubscriber& other); //cpoy
    SilverSubscriber(SilverSubscriber&& other) noexcept; //move
    SilverSubscriber& operator=(const SilverSubscriber& other); // assignment operator
    void print(void) const;
    virtual ~SilverSubscriber(void);
    bool getUpgradeIntrest() { return isInterstedUpgrade; };
    void setUpgradeInterest(bool update) { isInterstedUpgrade = update; };
    void chooseMeal(int choice);
    const char* getMeal(void)const;
    void showPrivalges(void) const;
    SilverSubscriber* clone() const { return new SilverSubscriber(*this); };
    const char* getType() { return "silver subscriber"; };
    void printMealMenu();
};

