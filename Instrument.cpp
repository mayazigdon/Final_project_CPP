#include "Instrument.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include "OrchestraExceptions.h"

using namespace std;

Instrument::Instrument(const char* name, int amount)
    : numOfMusicians(0), amount(amount), amountInUse(amount)
{
    manufacturerName = new char[strlen(name) + 1];
    memcpy(manufacturerName, name, strlen(name));
    manufacturerName[strlen(name)] = '\0';
    if (this->manufacturerName[0] == '\0') {
        delete[] this->manufacturerName;
        throw InvalidNameException();
    }
}

Instrument::Instrument(const Instrument& other)
    : amount(other.amount), amountInUse(other.amountInUse),
    numOfMusicians(other.numOfMusicians), lastTimetuned(other.lastTimetuned)
{
    manufacturerName = new char[strlen(other.manufacturerName) + 1];
    memcpy(manufacturerName, other.manufacturerName, strlen(other.manufacturerName));
    manufacturerName[strlen(other.manufacturerName)] = '\0';
}

Instrument::Instrument(Instrument&& other) noexcept
    : manufacturerName(other.manufacturerName), amount(other.amount), amountInUse(other.amountInUse),
    numOfMusicians(other.numOfMusicians), lastTimetuned(other.lastTimetuned)
{
    other.manufacturerName = nullptr;
}

const char* Instrument::getManufacturerName(void) const
{
    return manufacturerName;
}

int Instrument::getAmount(void) const
{
    return amount;
}

int Instrument::getNumOfMusicians(void) const
{
    return numOfMusicians;
}

Date Instrument::getDateOfLastTreatment(void) const
{
    return lastTimetuned;
}

void Instrument::setDateOfLastTreatment(void)
{
    using namespace std::chrono;
    system_clock::time_point now = system_clock::now();
    time_t currentTime = system_clock::to_time_t(now);
    tm localTime;
    localtime_s(&localTime, &currentTime);
    lastTimetuned.setDay(localTime.tm_mday);
    lastTimetuned.setMonth(localTime.tm_mon + 1);
    lastTimetuned.setYear(localTime.tm_year + 1900);
}

void Instrument::setNumOfMusicians(int value)
{
    this->numOfMusicians = value;
}

void Instrument::setManufacturerName(const char* name)
{
    delete[] manufacturerName;
    manufacturerName = new char[strlen(name) + 1];
    memcpy(manufacturerName, name, strlen(name));
    manufacturerName[strlen(name)] = '\0';
}

void Instrument::setAmount(int value)
{
    amount = value;
}

void Instrument::displayLastTunedDate(void) const
{
    if (this->getAmount() > 1) {
        cout << "The last time the instruments were tuned was at: ";
    }
    else {
        cout << "The last time this instrument was tuned was at: ";
    }
    this->getDateOfLastTreatment().print();
    cout << ".\n";
    cout << "Currently, there are " << amountInUse << " instruments in use out of " << amount << "." << endl;
}

bool Instrument::tuneRequired(void) const
{
    return false;
}

const bool Instrument::canAssignMusicians(void) const
{
    return amount == numOfMusicians;
}

void Instrument::operator++()
{
    while (amountInUse < amount) {
        amountInUse++;
    }
}

void Instrument::operator--()
{
    if (amountInUse > 0) {
        amountInUse--;
    }
}

Instrument::~Instrument()
{
    delete[] manufacturerName;
}
