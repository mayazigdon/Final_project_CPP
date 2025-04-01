#pragma once
#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include <cstring>
#include <iostream>
#include "Date.h"
#include <ctime>



class Instrument
{
private:
    char* manufacturerName;
    int amount;
    int amountInUse;
    int numOfMusicians;
    Date lastTimetuned;

public:
    Instrument(const char* name, int amount);
    Instrument(const Instrument& other);
    Instrument(Instrument&& other)noexcept;

    const char* getManufacturerName(void) const;
    int getAmount(void) const;
    int getNumOfMusicians(void) const;
    void setNumOfMusicians(int value);
    Date getDateOfLastTreatment(void) const;
    void setDateOfLastTreatment(void);
    void setManufacturerName(const char* name);
    void setAmount(int value);
    const bool canAssignMusicians(void) const;
    void displayLastTunedDate(void) const;
    virtual bool tuneRequired(void) const = 0;
    virtual void tuneInstrument(void)  = 0;
    virtual void detuneInstrument(void) = 0;// used after a preformance of a concert
    virtual void displayTuningInfo(void) const = 0;
    virtual Instrument* clone(void) const = 0;
    virtual void play(void) const = 0;
    void operator ++(void);
    void operator --(void);
    virtual ~Instrument(void);
};
#endif// INSTRUMENT_H