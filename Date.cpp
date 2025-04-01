#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

int Date::getYear(void) const
{
	return year;
}

int Date::getMonth(void) const
{
	return month;
}

int Date::getDay(void) const
{
	return day;
}

void Date::setYear(int year)
{
	this->year = year;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::print(void) const
{
	cout << day << "/" << month << "/" << year << " ";
}

bool Date::operator==(const Date& other) const
{
	return (other.getMonth() == month) && (other.getDay() == day) && (other.getYear() == year);
}
