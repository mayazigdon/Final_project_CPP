#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int hours, int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}

int Time::getHours(void) const
{
	return hours;
}

int Time::getMinutes(void) const
{
	return minutes;
}

void Time::setHours(int hours)
{
	this->hours = hours;
}

void Time::setMinutes(int minutes)
{
	this->minutes = minutes;
}

void Time::print(void) const
{
	if (hours < 10)
	{
		cout << "0" << hours;
	}
	else
	{
		cout << hours;
	}
	cout <<":";
	if (minutes < 10)
	{
		cout << "0" << minutes;
	}
	else
	{
		cout << minutes;
	}
}

bool Time::operator==(const Time& other)const
{
	return (other.getHours() == hours) && (other.getMinutes() == minutes);
}