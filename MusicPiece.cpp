#include "MusicPiece.h"
#include "OrchestraExceptions.h"
#include <iostream>

using namespace std;

MusicPiece::MusicPiece(const char* name, const char* composerName, int yearOfRelease, int lengthInMinutes)
{
    try {
        this->name = _strdup(name);
        this->composerName = _strdup(composerName);
    }
    catch (bad_alloc&) {
        delete[] this->name;
        delete[] this->composerName;
        throw;
    }
    if (this->name[0] == '\0' || this->composerName[0] == '\0') {
        delete[] this->name;
        delete[] this->composerName;
        throw InvalidNameException();
    }

    this->yearOfRelease = yearOfRelease;
    this->lengthInMinutes = lengthInMinutes;
}

MusicPiece::MusicPiece(const MusicPiece& other) //copy
{
    try {
        name = _strdup(other.name);
        composerName = _strdup(other.composerName);
    }
    catch (bad_alloc&) {
        delete[] this->name;
        delete[] this->composerName;
        throw;
    }
    yearOfRelease = other.yearOfRelease;
    lengthInMinutes = other.lengthInMinutes;
}

MusicPiece::MusicPiece(MusicPiece&& other) noexcept //move
{
    name = other.name;
    composerName = other.composerName;
    yearOfRelease = other.yearOfRelease;
    lengthInMinutes = other.lengthInMinutes;
    other.name = nullptr;
    other.composerName = nullptr;
    other.yearOfRelease = 0;
    other.lengthInMinutes = 0;
}

MusicPiece::~MusicPiece()
{
    delete[] name;
    delete[] composerName;
}

const char* MusicPiece::getMusicPieceName() const
{
    return name;
}

const char* MusicPiece::getMusicPieceComposerName() const
{
    return composerName;
}

int MusicPiece::getMusicPieceReleaseYear() const
{
    return yearOfRelease;
}

int MusicPiece::getMusicPieceLength() const
{
    return lengthInMinutes;
}

void MusicPiece::setMusicPieceName(const char* name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    memcpy(this->name, name, strlen(name));
}

void MusicPiece::setMusicPieceComposerName(const char* composerName)
{
    delete[] this->composerName;
    this->composerName = new char[strlen(composerName) + 1];
    memcpy(this->composerName, composerName, strlen(composerName));
}

void MusicPiece::setMusicPieceReleaseYear(int yearOfRelease)
{
    this->yearOfRelease = yearOfRelease;
}

void MusicPiece::setMusicPieceLength(int lengthInMinutes)
{
    this->lengthInMinutes = lengthInMinutes;
}

MusicPiece* MusicPiece::clone() const
{
    return new MusicPiece(*this);
}

void MusicPiece::print() const
{
    cout << this->name << ", By: " << this->composerName << ", Released at: " << this->yearOfRelease << ", Length: " << this->lengthInMinutes << " minutes" << "\n";
}

bool MusicPiece::operator ==(const MusicPiece& other) const
{
    return (other.getMusicPieceLength() == lengthInMinutes) && (other.getMusicPieceName() == name) && (other.composerName == composerName);
}

MusicPiece& MusicPiece::operator=(const MusicPiece& other)
{
    if (this != &other)
    {
        delete[] name;
        delete[] composerName;

        name = new char[strlen(other.name) + 1];
        memcpy(name, other.name, strlen(other.name));

        composerName = new char[strlen(other.composerName) + 1];
        memcpy(composerName, other.composerName, strlen(other.composerName));

        yearOfRelease = other.yearOfRelease;
        lengthInMinutes = other.lengthInMinutes;
    }
    return *this;
}
