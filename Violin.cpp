using namespace std;
#include "Violin.h"
#include "OrchestraExceptions.h"
#include <iostream>
#include <cstdlib> 


Violin::Violin(const char* name, int amount)
    : Instrument(name, amount)
{
    try {
         numberOfStrings = DEFAULT_STRINGS;
    }
    catch (const InvalidNameException&) {
        throw;
    }
}

Violin::Violin(const Violin& other)
    : Instrument(other), numberOfStrings(other.numberOfStrings)
{
}

Violin::Violin(Violin&& other) noexcept
    : Instrument(std::move(other)), numberOfStrings(other.numberOfStrings)
{
}

int Violin::getNumberOfStrings() const
{
    return numberOfStrings;
}

void Violin::setNumberOfStrings(int Number)
{
    numberOfStrings = Number;
}

void Violin::play() const
{
    cout << "    0 /" << endl;
    cout << "   /_oo-#= __" << endl;
    cout << "    | \\/  /_/" << endl;
    cout << "    |\\     |"<< endl;
    cout << "    / \\    |" << endl;
    cout << "   ~  ~   /|\\" << endl << endl;
}

Violin::~Violin()
{
}

Violin* Violin::clone(void) const {
    return new Violin(*this);
}

bool Violin::tuneRequired(void) const
{
    return numberOfStrings!= DEFAULT_STRINGS;
}

void Violin::tuneInstrument(void) 
{
    setNumberOfStrings(DEFAULT_STRINGS);
}

void Violin::displayTuningInfo(void) const
{

    cout << "The violins should have "<< DEFAULT_STRINGS <<" strings, but ours have "<< numberOfStrings <<"." << endl;
    this->displayLastTunedDate();
}

void Violin::detuneInstrument(void)
{
    setNumberOfStrings(rand() % DEFAULT_STRINGS);
}
