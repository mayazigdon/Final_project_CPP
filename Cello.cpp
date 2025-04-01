#include "Cello.h"
#include "OrchestraExceptions.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Cello::Cello(const char* name, int amount, bool hasEndStick) : Instrument(name, amount)
{
    try {
        this->hasEndStick = hasEndStick;
    }
    catch (const InvalidNameException&) {
        throw;
    }
}

Cello::Cello(const Cello& other) : Instrument(other), numberOfStrings(other.numberOfStrings), hasEndStick(other.hasEndStick)
{
}

Cello::Cello(Cello&& other) noexcept : Instrument(std::move(other)), numberOfStrings(other.numberOfStrings), hasEndStick(other.hasEndStick)
{
}

int Cello::getNumberOfStrings(void) const
{
    return numberOfStrings;
}

void Cello::setNumberOfStrings(int Number)
{
    numberOfStrings = Number;
}

bool Cello::getHasEndStick(void) const
{
    return hasEndStick;
}

void Cello::setHasEndStick(bool isTrue)
{
    hasEndStick = isTrue;
}

void Cello::play(void) const
{
    cout << "     O @  " << endl;
    cout << "    _|/_   " << endl;
    cout << "   /( )_\\  " << endl;
    cout << " ;/_)_(_  " << endl;
    cout << "  _(   )   " << endl;
    cout << "  /  /  /  " << endl << endl;
}

bool Cello::tuneRequired(void) const
{
    return numberOfStrings != DEFULT_STRINGS || hasEndStick != true;
}

void Cello::tuneInstrument(void)
{
    setHasEndStick(true);
    setNumberOfStrings(DEFULT_STRINGS);
}

Cello* Cello::clone(void) const
{
    return new Cello(*this);
}

void Cello::displayTuningInfo(void) const
{
    if (hasEndStick) {
        cout << "The " << this->getManufacturerName() << " should have " << DEFULT_STRINGS << " strings, but ours have " << numberOfStrings << "." << endl;
    }
    else {
        if (numberOfStrings == DEFULT_STRINGS) {
            cout << "The " << this->getManufacturerName() << " should have a support stick." << endl;
        }
        else {
            cout << "The " << this->getManufacturerName() << " should have " << DEFULT_STRINGS << " strings and a support stick, but ours have " << numberOfStrings << "." << endl;
        }
    }
    this->displayLastTunedDate();
}

void Cello::detuneInstrument(void)
{
    setNumberOfStrings(rand() % DEFULT_STRINGS);
    setHasEndStick(false);

}

Cello::~Cello(void)
{
    //no allocated memory here, only at his parent.
}
