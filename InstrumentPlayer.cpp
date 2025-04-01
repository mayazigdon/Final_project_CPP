#include "InstrumentPlayer.h"
#include <iostream>

using namespace std;


InstrumentPlayer::InstrumentPlayer(void)
{
    numOfInstruments = 0;
    instruments = new Instrument * [MAX_COUNT];
}

InstrumentPlayer::InstrumentPlayer(const InstrumentPlayer& other) // copy
{
    numOfInstruments = other.numOfInstruments;
    instruments = new Instrument * [MAX_COUNT];
    for (int i = 0; i < numOfInstruments; i++)
    {
        instruments[i] = other.instruments[i];
    }
}

InstrumentPlayer::InstrumentPlayer(InstrumentPlayer&& other) noexcept // move
{
    numOfInstruments = other.numOfInstruments;
    instruments = other.instruments;
    other.instruments = nullptr;
    other.numOfInstruments = 0;
}

const int InstrumentPlayer::getNumOfInstruments(void) const
{
    return numOfInstruments;
}

const int InstrumentPlayer::getMaxCount(void) const
{
    return MAX_COUNT;
}

const Instrument* InstrumentPlayer::getInstrument(const int index) const
{
    return instruments[index];
}

void InstrumentPlayer::addInstrument(Instrument* instrument)
{
    instruments[numOfInstruments] = instrument;
    numOfInstruments++;
    int value = instrument->getNumOfMusicians() + 1;
    instrument->setNumOfMusicians(value);
}

const void InstrumentPlayer::displayInstruments(void) const
{
    char x = 'a';
    for (size_t i = 0; i < this->getNumOfInstruments(); i++)
    {
        cout << "   " << x << ". " << instruments[i]->getManufacturerName() << ".\n";
        ++x;
    }
}

const bool InstrumentPlayer::doesInstrumentBeenAdded(const Instrument* instrument) const
{
    for (size_t i = 0; i < numOfInstruments; i++)
    {
        if (instruments[i] == instrument) {
            return true;
        }
    }
    return false;
}

const bool InstrumentPlayer::hasReachedMaxInstruments(void) const
{
    return numOfInstruments== MAX_COUNT;
}

InstrumentPlayer::~InstrumentPlayer()
{
    delete[] instruments;
}

InstrumentPlayer& InstrumentPlayer::operator=(const InstrumentPlayer& other) // =
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < numOfInstruments; i++)
    {
        delete instruments[i];
    }

    numOfInstruments = other.numOfInstruments;
    for (int i = 0; i < numOfInstruments; i++)
    {
        instruments[i] = other.instruments[i];
    }

    return *this;
}
