#pragma once
#ifndef FLUTE_H
#define FLUTE_H

#include "Instrument.h"

class Flute : public Instrument
{
private:
	bool hasKeys; // for example a clarinet, is to be considered as a flute but has keys
	bool isBlocked;

public:
	Flute(const char* name, int amount, bool hasKeys);
	Flute(const Flute& other);
	Flute(Flute&& other) noexcept;

	bool getHasKeys(void) const;
	void setHasKeys(bool isTrue);

	bool getIsBlocked(void) const;
	void setIsBlocked(bool isTrue);

	void play(void) const override;
	Flute* clone(void) const;

	virtual ~Flute(void);

	// Inherited via Instrument
	virtual bool tuneRequired(void) const override;
	virtual void tuneInstrument(void) override;
	virtual void displayTuningInfo(void) const override;
	virtual void detuneInstrument(void) override;
};

#endif // FLUTE_H
