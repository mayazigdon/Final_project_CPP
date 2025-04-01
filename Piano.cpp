#include "Piano.h"
#include "OrchestraExceptions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Piano::Piano(const char* name, int amount, bool isGrandPiano) : Instrument(name, amount)
{
    try {
        numberOfKeys = DEFULT_KEYS;
        this->isGrandPiano = isGrandPiano;
    }
    catch (const InvalidNameException&) {
        throw;
    }
}

Piano::Piano(const Piano& other)
    : Instrument(other), numberOfKeys(other.numberOfKeys), isGrandPiano(other.isGrandPiano)
{
}

Piano::Piano(Piano&& other) noexcept
    : Instrument(std::move(other)), numberOfKeys(other.numberOfKeys), isGrandPiano(other.isGrandPiano)
{
}

int Piano::getNumberOfKeys(void) const
{
    return numberOfKeys;
}

void Piano::setNumberOfKeys(const int number)
{
    numberOfKeys = number;
}

void Piano::play(void) const
{
    cout << "  o    _______________" << endl;
    cout << " /\\_  _|             |" << endl;
    cout << "_\\__`[_______________|" << endl;
    cout << "] [ \\, ][         ][" << endl << endl;
}

Piano* Piano::clone() const
{
    return new Piano(*this);
}

Piano::~Piano()
{
}

bool Piano::tuneRequired(void) const
{
    return numberOfKeys != DEFULT_KEYS;
}

void Piano::tuneInstrument(void)
{
    setNumberOfKeys(DEFULT_KEYS);
}

void Piano::displayTuningInfo(void) const
{
    cout << "Our " << this->getManufacturerName() << " has " << numberOfKeys << " keys instead of " << DEFULT_KEYS << endl;
    this->displayLastTunedDate();
}

void Piano::detuneInstrument(void)
{
    setNumberOfKeys(rand() % DEFULT_KEYS);

}


