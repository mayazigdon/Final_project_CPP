#pragma once
#include "Subscriber.h"
#include "Time.h"
#include"VipDinner.h"
class GoldenSubscriber :
    public Subscriber
{
private:
    VipDinner dinner; 
    Time* enteranceBackStageTime;
    const int MAX_SEATS_IN_SECTION = 100;

public:
    GoldenSubscriber(const char* Name);
    GoldenSubscriber(const GoldenSubscriber& other); //cpoy
    GoldenSubscriber(GoldenSubscriber&& other) noexcept; //move
    GoldenSubscriber& operator=(const GoldenSubscriber& other); // assignment operator
    void print(void) const;
    virtual ~GoldenSubscriber(void);
    void setEntranceTime(int minutes, int hours) { enteranceBackStageTime->setHours(hours), enteranceBackStageTime->setMinutes(minutes); };
    Time getEntranceTime(void) { return *enteranceBackStageTime; };
    void chooseDinner(int meal, int side, int drink, int dessert);
    void showDinner(void) const;
    void showPrivalges(void) const;
    VipDinner getDinner() { return dinner; };
    GoldenSubscriber* clone() const { return new GoldenSubscriber(*this); };
    const char* getType() { return "golden subscriber"; };
};


