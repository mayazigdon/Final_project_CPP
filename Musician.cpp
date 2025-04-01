#include "Musician.h"
#include "OrchestraExceptions.h"
#include <iostream>

using namespace std;

Musician::Musician(const char* name, bool soloPlayer) : Person(name)
{
	try {
		this->soloPlayer = soloPlayer;
	}
	catch (const InvalidNameException&) {
		throw;
	}
	catch (bad_alloc&) {
		throw;
	}
}

Musician::Musician(const Musician& other) : Person(other), InstrumentPlayer(other)
{
	soloPlayer = other.soloPlayer;
}

Musician::Musician(Musician&& other) noexcept : Person(move(other)), InstrumentPlayer(other)
{
	soloPlayer = other.soloPlayer;
}

void Musician::playInstrument(void) const
{
	if (this->getNumOfInstruments() > 0) {
		int randomInstrument = rand() % this->getNumOfInstruments();
		cout << getPersonName() << " has performed a solo on: " << this->getInstrument(randomInstrument)->getManufacturerName() << endl;
		cout << "You can see the performance below:" << endl;
		this->getInstrument(randomInstrument)->play();
	}
}

const bool Musician::getIsSoloPlayer(void) const
{
	return soloPlayer;
}

void Musician::setSoloPlayer(bool isSolo)
{
	soloPlayer = isSolo;
}

void Musician::print(void) const
{
	cout << "Musician Name: " << getPersonName();
	cout << ", Played in: " << getExperience() << " concerts";
	cout << ", Qualified as Solo Player: " << (soloPlayer ? "Yes" : "No") << endl;
	if (this->getNumOfInstruments()) {
		cout << "   Can perform on the following instruments:" << endl;
		displayInstruments();
	}
	else {
		cout << "   This musician is still mastering his skills. Soon we will get him an instrument." << endl;
	}
}

Musician::~Musician(void)
{
	// We don't have any dynamic allocation here, but his parents do...
}

Musician* Musician::clone() const
{
	return new Musician(*this);
}

Musician& Musician::operator=(const Musician& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		InstrumentPlayer::operator=(other);
		soloPlayer = other.soloPlayer;
	}
	return *this;
}
