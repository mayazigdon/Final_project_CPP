#include "Flute.h"
#include "OrchestraExceptions.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Flute::Flute(const char* name, int amount, bool hasKeys) : Instrument(name, amount)
{
    try {
        this->hasKeys = hasKeys;
        isBlocked = false;
    }
    catch (const InvalidNameException&) {
        throw;
    }
}

Flute::Flute(const Flute& other)
    : Instrument(other), hasKeys(other.hasKeys), isBlocked(other.isBlocked)
{
}

Flute::Flute(Flute&& other) noexcept
    : Instrument(std::move(other)), hasKeys(other.hasKeys), isBlocked(other.isBlocked)
{
}

bool Flute::getHasKeys(void) const
{
    return hasKeys;
}

void Flute::setHasKeys(bool isTrue)
{
    hasKeys = isTrue;
}

bool Flute::getIsBlocked(void) const
{
    return isBlocked;
}

void Flute::setIsBlocked(bool isTrue)
{
    isBlocked = isTrue;
}

Flute* Flute::clone() const {
    return new Flute(*this);
}

void Flute::play(void) const
{
    cout << "  ~0___" << endl;
    cout << "  \\/ /" << endl;
    cout << "  |" << endl;
    cout << " / \\" << endl;
    cout << " /  \\" << endl;
    cout << " ~  ~\n" << endl;
}

Flute::~Flute(void)
{
}

bool Flute::tuneRequired(void) const
{
    return isBlocked;
}

void Flute::tuneInstrument(void)
{
    setIsBlocked(false);
}

void Flute::displayTuningInfo(void) const
{
    cout << "Our " << this->getManufacturerName() << " is blocked, seems that something got stuck there." << endl;
    this->displayLastTunedDate();
}

void Flute::detuneInstrument(void)
{
    setIsBlocked(true);
}
