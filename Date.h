#pragma once
#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int year = 2023, int month = 6, int day = 20);

    int getYear(void) const;
    int getMonth(void) const;
    int getDay(void) const;

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    void print(void) const;
    bool operator==(const Date& other) const;
};

#endif // DATE_H
