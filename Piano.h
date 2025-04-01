#pragma once
#ifndef PIANO_H
#define PIANO_H

#include "Instrument.h"

class Piano :public Instrument
{

private:
	const int DEFULT_KEYS=88;

	int numberOfKeys;
	bool isGrandPiano;

public:
	Piano(const char* name, int amount, bool isGrandPiano);
	Piano(const Piano& other);
	Piano(Piano&& other) noexcept;
	Piano* clone(void) const;

	int getNumberOfKeys(void) const;
	void setNumberOfKeys(const int number);
	void play(void) const override;
	virtual ~Piano(void);

	// Inherited via Instrument
	virtual bool tuneRequired(void) const override;
	virtual void tuneInstrument(void) override;
	virtual void displayTuningInfo(void) const override;
	virtual void detuneInstrument(void) override;
};
#endif // PIANO_H
