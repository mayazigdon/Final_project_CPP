#pragma once

#ifndef CELLO_H
#define CELLO_H

#include "Instrument.h"

class Cello : public Instrument
{
private:
    const int DEFULT_STRINGS = 4;
    int numberOfStrings = 4;
    bool hasEndStick; // The stick that supports the cello (makes it higher)

public:
    Cello(const char* name, int amount, bool hasEndStick);
    Cello(const Cello& other);
    Cello(Cello&& other) noexcept;

    int getNumberOfStrings(void) const;
    void setNumberOfStrings(int Number);
    bool getHasEndStick(void) const;
    void setHasEndStick(bool isTrue);
    virtual ~Cello(void);
    Cello* clone(void) const;

    // Inherited via Instrument
    void play(void) const override;
    virtual bool tuneRequired(void) const override;
    virtual void tuneInstrument(void) override;
    virtual void displayTuningInfo(void) const override;
    virtual void detuneInstrument(void) override;
};

#endif // CELLO_H
