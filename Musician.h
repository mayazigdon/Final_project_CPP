#pragma once

#ifndef MUSICIAN_H
#define MUSICIAN_H
#include "Person.h"
#include "InstrumentPlayer.h"

class Musician : public Person , public InstrumentPlayer
{

private:
	bool soloPlayer;

public:
	Musician(const char* Name,bool soloPlayer);
	Musician(const Musician& other);//copy
	Musician(Musician&& other)noexcept;//move

	const bool getIsSoloPlayer(void) const;
	Musician* clone(void) const;

	void setSoloPlayer(bool isSolo);
	Musician& operator=(const Musician& other);

    void print(void)const override;
	virtual ~Musician(void);
	virtual void playInstrument(void) const override;
};

#endif // MUSICIAN_H
