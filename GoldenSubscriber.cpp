#include "GoldenSubscriber.h"
#include "Subscriber.h"
#include "OrchestraExceptions.h"
#include "Person.h"
#include "VipDinner.h"

GoldenSubscriber::GoldenSubscriber(const char* name) : dinner(), Subscriber(name) {
	pricePaidPerMonth = 600;
	enteranceBackStageTime->setHours((rand() % 10) + 6);// between 6-10
	enteranceBackStageTime->setMinutes((rand() % 59) + 1);//between 1-59
	savedSeatNumber = (rand() % MAX_SEATS_IN_SECTION) + 1;/// randomSeat
	setsArea = _strdup("VIP zone");
	isPremium = true;
}
GoldenSubscriber::GoldenSubscriber(const GoldenSubscriber& other) :dinner(other.dinner), Subscriber(other) {
	savedSeatNumber = other.savedSeatNumber;
	enteranceBackStageTime = other.enteranceBackStageTime;
}
GoldenSubscriber::GoldenSubscriber(GoldenSubscriber&& other) noexcept :dinner(other.dinner), Subscriber(move(other)) {
	savedSeatNumber = other.savedSeatNumber;
	enteranceBackStageTime = other.enteranceBackStageTime;
}
GoldenSubscriber& GoldenSubscriber::operator=(const GoldenSubscriber& other) {
	if (this != &other)
	{
		dinner = other.dinner; // using opertor= of dinner
		savedSeatNumber = other.savedSeatNumber;
		enteranceBackStageTime = other.enteranceBackStageTime;
	}
	return *this;
}
void GoldenSubscriber::print(void) const {
	cout << "Golden subscriber" << endl;
	cout << "name:" << getPersonName() << endl;
	cout << "subsription number: " << subscriptionNumber << endl;
	cout << "seats area" << *setsArea << endl;
	cout << "seat number:" << savedSeatNumber;
	dinner.print();
	cout << "entrance time backstage is :";
	enteranceBackStageTime->print();
}
void GoldenSubscriber::chooseDinner(int meal, int side, int drink, int dessert) {
	dinner.setDinner(meal, side, drink, dessert);
}
GoldenSubscriber:: ~GoldenSubscriber(void) {
	delete[]setsArea;
}
void GoldenSubscriber::showDinner(void) const {
	dinner.print();
}
void GoldenSubscriber::showPrivalges(void) const {
	cout << "as a silver subscriber you get to seat at the VIP area" << endl;
	cout << "also you entiteld for a 3 course meal and drinks!"<< endl;
	cout << "a free entrance for the backstage of orchestra!" << endl;
	cout << " and you will get a saved seat for each concert!" << endl;
	cout << "cost per month:" + pricePaidPerMonth;

}