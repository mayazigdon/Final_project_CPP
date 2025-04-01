#include "SimpleSubscriber.h"
#include "Subscriber.h"
#include "OrchestraExceptions.h"
#include "Person.h"
#include <iostream>
SimpleSubscriber::SimpleSubscriber(const char* name) :Subscriber(name){
	pricePaidPerMonth = 150;
	savedSeatNumber = (rand()%MAX_SEATS_IN_SECTION)+1;/// randomSeat
	setsArea = _strdup("main floor");
	isPremium = false;
	isInterstedUpgrade=false; // false by defalult ,theres a check of that
}
SimpleSubscriber::SimpleSubscriber(const SimpleSubscriber& other):Subscriber(other) {
	savedSeatNumber = other.savedSeatNumber;
	isInterstedUpgrade = other.isInterstedUpgrade;
}
SimpleSubscriber::SimpleSubscriber(SimpleSubscriber&& other) noexcept :Subscriber(move(other)){
	savedSeatNumber = other.savedSeatNumber;
	isInterstedUpgrade = other.isInterstedUpgrade;
}
SimpleSubscriber& SimpleSubscriber:: operator=(const SimpleSubscriber& other){
	if (this != &other)
	{
		savedSeatNumber = other.savedSeatNumber;
		isInterstedUpgrade = other.isInterstedUpgrade;
	}
	return *this;
}

void SimpleSubscriber::print(void) const {
	cout << "simple subscriber" << endl;
	cout << "name:" << getPersonName()<<endl;
	cout << "subsription number: " << subscriptionNumber<<endl;
	cout << "seats area" << *setsArea << endl;
	cout << "seat number:" << savedSeatNumber;
}
SimpleSubscriber:: ~SimpleSubscriber(void) {
	delete[]setsArea;
}
void SimpleSubscriber::showPrivalges(void) const {
	cout << "as a simple subscriber you get to seat at the main floor area"<<endl;
	cout << " and you will get a saved seat for each concert!" << endl;
	cout << "cost per month:" + pricePaidPerMonth;
}



