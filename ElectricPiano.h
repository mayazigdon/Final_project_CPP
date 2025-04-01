#pragma once
#ifndef ELECTRICPIANO_H
#define ELECTRICPIANO_H

#include "Instrument.h"
#include "Piano.h"

class ElectricPiano : public Piano
{
private:
    int numberOfTones;
    int volumeLevel;
    bool isPowerOn = false;

public:
    ElectricPiano(const char* name, int amount, int numberOfTones, int volumeLevel);
    ElectricPiano(const ElectricPiano& other);
    ElectricPiano(ElectricPiano&& other) noexcept;

    const int getVolume(void);
    const int getNumberOfTones(void);

    void setNumberOfTones(int number);
    void setVolume(int volumeLevel);

    bool getIsPowerOn(void) const;
    void setIsPowerOn(bool volumeLevel);

    void play(void) const override;
    ElectricPiano* clone(void) const;

    bool tuneRequired(void) const override;
    void tuneInstrument(void) override;
    void displayTuningInfo(void) const override;
    virtual void detuneInstrument(void) override;

    virtual ~ElectricPiano(void);
};

#endif // ELECTRICPIANO_H

