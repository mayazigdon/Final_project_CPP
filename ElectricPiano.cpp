#include "ElectricPiano.h"
#include "OrchestraExceptions.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ElectricPiano::ElectricPiano(const char* name, int amount, int numberOfTones, int volumeLevel)
    : Piano(name, amount, false)
{
    try {
        this->numberOfTones = numberOfTones;
        this->volumeLevel = volumeLevel;
        isPowerOn = false;
    }
    catch (const InvalidNameException&) {
        throw;
    }
}

ElectricPiano::ElectricPiano(const ElectricPiano& other)
    : Piano(other),
    numberOfTones(other.numberOfTones),
    volumeLevel(other.volumeLevel),
    isPowerOn(other.isPowerOn)
{
}

ElectricPiano::ElectricPiano(ElectricPiano&& other) noexcept
    : Piano(std::move(other)),
    numberOfTones(other.numberOfTones),
    volumeLevel(other.volumeLevel),
    isPowerOn(other.isPowerOn)
{
}

const int ElectricPiano::getVolume(void)
{
    return volumeLevel;
}

const int ElectricPiano::getNumberOfTones(void)
{
    return numberOfTones;
}

void ElectricPiano::setNumberOfTones(int number)
{
    numberOfTones = number;
}

void ElectricPiano::setVolume(int volumeLevel)
{
    this->volumeLevel = volumeLevel;
}

bool ElectricPiano::getIsPowerOn(void) const
{
    return isPowerOn;
}

ElectricPiano* ElectricPiano::clone() const
{
    return new ElectricPiano(*this);
}

void ElectricPiano::setIsPowerOn(bool powerStatus)
{
    isPowerOn = powerStatus;
}

void ElectricPiano::play(void) const
{
    if (!isPowerOn) {
        cout << "What a shame! It appears that the electrical plug for the Piano hasn't been connected. Nobody was able to hear him playing..." << endl << endl;
    }
    cout << " o     |~~~| " << endl;
    cout << "/\\_  _|   |  " << endl;
    cout << "\\__`[_    | " << endl;
    cout << "][ \\,/|___| " << endl << endl;

}

bool ElectricPiano::tuneRequired(void) const
{
    return !isPowerOn || volumeLevel < 50;
}

void ElectricPiano::tuneInstrument(void)
{
    setIsPowerOn(true);
    setVolume(rand() % 51 + 50);
}

void ElectricPiano::displayTuningInfo(void) const
{
    cout << "The " << this->getManufacturerName();
    if (!isPowerOn) {
        cout << " is not connected to the electricity";
        if (!(volumeLevel > 50)) {
            cout << ",\nand the volume is set to below 50%, it's hard to hear the playing";
        }
    }
    else if (!(volumeLevel > 50)) {
        cout << ", has its volume set to below 50%, it's hard to hear the playing";
    }
    cout << "." << endl;
    this->displayLastTunedDate();
}

void ElectricPiano::detuneInstrument(void)
{
    setIsPowerOn(false);
    setVolume(rand() % 50);
}

ElectricPiano::~ElectricPiano()
{
}
