#include "Subscriber.h"
#include "OrchestraExceptions.h"
#include <iostream>
using namespace std;

int Subscriber::subscriptionNumgenerator = 1;

Subscriber::Subscriber(const char* name) :Person(name) {
	yearsOfSubscribed=0;
	pricePaidPerMonth=0;
	subscriptionNumber = subscriptionNumgenerator;
	subscriptionNumber++;
	bool isPremium=false;
}
Subscriber:: Subscriber(const Subscriber& other) : Person(other) {
	yearsOfSubscribed = other.yearsOfSubscribed;
	pricePaidPerMonth = other.pricePaidPerMonth;
	isPremium = other.isPremium;
	subscriptionNumber = other.subscriptionNumber;
}
Subscriber::Subscriber(Subscriber&& other) noexcept : Person(move(other))
{
	yearsOfSubscribed = other.yearsOfSubscribed;
	pricePaidPerMonth = other.pricePaidPerMonth;
	isPremium = other.isPremium;
	subscriptionNumber = other.subscriptionNumber;
}
void Subscriber:: updatePrices(int newPrice) {
	pricePaidPerMonth = newPrice;
}
void Subscriber::operator++(void) {
	yearsOfSubscribed++;
}
Subscriber& Subscriber:: operator=(const Subscriber& other) {
	if (this != &other)
	{
		Person::operator=(other);
		yearsOfSubscribed = other.yearsOfSubscribed;
		pricePaidPerMonth = other.pricePaidPerMonth;
		isPremium = other.isPremium;
	}
	return *this;
}


Subscriber:: ~Subscriber(void) { }


