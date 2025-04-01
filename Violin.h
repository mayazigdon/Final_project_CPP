#pragma once
#ifndef VIOLIN_H
#define VIOLIN_H

#include "Instrument.h"

class Violin : public Instrument
{
private:
    const int DEFAULT_STRINGS = 4;
    int numberOfStrings = 4;

public:
    Violin(const char* name, int amount);
    Violin(const Violin& other);
    Violin(Violin&& other) noexcept;
    Violin* clone(void) const;

    int getNumberOfStrings(void) const;
    void setNumberOfStrings(const int Number);
    void play(void) const override;
    virtual ~Violin(void);

    // Inherited via Instrument
    virtual bool tuneRequired(void) const override;
    virtual void tuneInstrument(void) override;
    virtual void displayTuningInfo(void) const override;
    virtual void detuneInstrument(void) override;
};

#endif // VIOLIN_H
