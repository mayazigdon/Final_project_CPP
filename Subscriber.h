#pragma once
#include "Person.h"

class Subscriber :public Person
{   
protected:
	static int subscriptionNumgenerator;
	int yearsOfSubscribed;
	int pricePaidPerMonth;
	int subscriptionNumber;
	int savedSeatNumber;
	char* setsArea = nullptr;
	bool isPremium; 

public:
	Subscriber(const char* Name);
	Subscriber(const Subscriber& other); //cpoy
	Subscriber(Subscriber&& other) noexcept; //
	
	int getAmountPaid() { return pricePaidPerMonth; };
	int getYearsSubsribed() { return yearsOfSubscribed; };
	void updatePrices(int newPrice);
	int getSubscriptionNum(){ return subscriptionNumber; };
	char* getSeatsArea() { return setsArea; };
	int getSavedSeatNum() { return savedSeatNumber; };
	void operator++(void);// update yearsOfsubscribed
	virtual Subscriber& operator=(const Subscriber& other); // assignment operator
	virtual void print(void) const= 0;
	virtual void showPrivalges (void) const = 0;
	virtual Subscriber* clone() const =0;
	virtual ~Subscriber(void);
	virtual const char* getType()=0;


};

