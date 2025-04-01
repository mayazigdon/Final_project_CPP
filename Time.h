#pragma once
#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int hours;
	int minutes;

public:
	Time(int hours = 12, int minutes = 0);

	int getHours(void) const;
	int getMinutes(void) const;
	void setHours(const int hour);
	void setMinutes(const int minutes);
	bool operator==(const Time& other) const;
	void print(void) const;
};

#endif // TIME_H
