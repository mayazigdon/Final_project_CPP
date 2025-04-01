#include "SilverSubscriber.h"
#include "Subscriber.h"
#include "OrchestraExceptions.h"
#include "Person.h"
#include <iostream>

SilverSubscriber::SilverSubscriber(const char* name) :Subscriber(name) {
	pricePaidPerMonth = 300;
	savedSeatNumber = (rand() % MAX_SEATS_IN_SECTION) + 1;/// randomSeat
	setsArea = _strdup("balconi");
	isPremium = true;
	isInterstedUpgrade = false; // false by defalult ,theres a check of that
	theMealToday = chicken; // default
}
SilverSubscriber::SilverSubscriber(const SilverSubscriber& other) :Subscriber(other) {
	savedSeatNumber = other.savedSeatNumber;
	isInterstedUpgrade = other.isInterstedUpgrade;
	theMealToday = other.theMealToday;
}
SilverSubscriber::SilverSubscriber(SilverSubscriber&& other) noexcept :Subscriber(move(other)) {
	savedSeatNumber = other.savedSeatNumber;
	isInterstedUpgrade = other.isInterstedUpgrade;
	theMealToday = other.theMealToday;
}
SilverSubscriber& SilverSubscriber:: operator=(const SilverSubscriber& other) {
	if (this != &other)
	{
		savedSeatNumber = other.savedSeatNumber;
		isInterstedUpgrade = other.isInterstedUpgrade;
		theMealToday = other.theMealToday;
	}
	return *this;
}
void SilverSubscriber::print(void) const {
	cout << "silver subscriber" << endl;
	cout << "name:" << getPersonName() << endl;
	cout << "subsription number: " << subscriptionNumber << endl;
	cout << "seats area" << *setsArea << endl;
	cout << "seat number:" << savedSeatNumber;
	cout << "yummm.. im having a " << getMeal() << "today!";
}

void SilverSubscriber::chooseMeal(int choice) {
    switch (choice) {
    case 1:
        this->theMealToday = chicken;
        break;
    case 2:
        this->theMealToday = steak;
        break;
    case 3:
        this->theMealToday = fish;
        break;
    case 4:
        this->theMealToday = lubster;
        break;
    default:
        this->theMealToday = chicken;
        break;
    }
}
const char* SilverSubscriber::getMeal (void)const {
    switch (theMealToday)
    {
    case chicken:
        return "Chicken";
    case steak:
        return "Steak";
    case fish:
        return "Fish";
    case lubster:
        return "Lubster";
    default:
        return "Chicken - Default";
    }
}
SilverSubscriber:: ~SilverSubscriber(void) {
	delete[]setsArea;
}
void SilverSubscriber::showPrivalges(void) const {
    cout << "as a silver subscriber you get to seat at the balconi area" << endl;
    cout << "also you entiteld for a simple meal wich include main course only";
    cout << " and you will get a saved seat for each concert!" << endl;
    cout << "cost per month:" + pricePaidPerMonth;

}
void SilverSubscriber::printMealMenu() {
    cout << "welcome to silver subscriber's meal menu!" << endl;
    cout << "chicken.....................................1"<<endl;
    cout << "steak.......................................2"<<endl;
    cout << "fish........................................3" << endl;
    cout << "lubster.....................................4" << endl;
}
