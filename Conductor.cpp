#include "Conductor.h"
#include "OrchestraExceptions.h"
#include <iostream>
#include <ctime>

using namespace std;

Conductor::Conductor(const char* Name, int type) : Person(Name)
{
    try {
        setStyleType(type);
    }
    catch (const InvalidNameException&) {
        throw;
    }
    catch (bad_alloc&) {
        throw;
    }
}

Conductor::Conductor(const Conductor& other) : Person(other)
{
    type = other.type;
}

Conductor::Conductor(Conductor&& other) noexcept : Person(other)
{
    type = other.type;
}

const char* Conductor::getStyleType(void) const
{
    switch (type)
    {
    case Classic:
        return "Classic";
    case Romantic:
        return "Romantic";
    case Modern:
        return "Modern";
    case Jazz:
        return "Jazz";
    default:
        return "Classic - Default";
    }
}

void Conductor::setStyleType(int type)
{
    switch (type) {
    case 1:
        this->type = Conductor::Classic;
        break;
    case 2:
        this->type = Conductor::Romantic;
        break;
    case 3:
        this->type = Conductor::Modern;
        break;
    case 4:
        this->type = Conductor::Jazz;
        break;
    default:
        this->type = Conductor::Classic;
        break;
    }
}

MusicPiece* Conductor::compose(const char* name, int minDuration, int maxDuration) const
{
    MusicPiece* freshlyComposed = new MusicPiece(name, getPersonName(), 2023, minDuration);
    int duration = minDuration + rand() % (maxDuration - minDuration);
    freshlyComposed->setMusicPieceLength(duration);
    return freshlyComposed;
}

void Conductor::print(void) const
{
    cout << "Conductor Name: " << getPersonName();
    cout << ", Experience: " << getExperience() << " concerts";
    cout << ", Style: " << getStyleType() << endl;
}

const Conductor& Conductor::operator=(const Conductor& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        type = other.type;
    }
    return *this;
}

Conductor::~Conductor()
{
    //we dont have any dynamic allocation here but his parent has...
}
