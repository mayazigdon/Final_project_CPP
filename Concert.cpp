#include "Concert.h"
#include "OrchestraExceptions.h"
#include <iostream>

using namespace std;

Concert::Concert(int hour, int minute, int year, int month, int day)
{
    numOfMusicPieces = 0;
    this->time = Time(hour, minute);
    this->date = Date(year, month, day);
    this->playList = new MusicPiece * [MAX_MUSIC_PIECES];
}

void Concert::addMusicPiece(const MusicPiece& musicPiece)
{
    if (numOfMusicPieces < MAX_MUSIC_PIECES)
    {
        playList[numOfMusicPieces] = musicPiece.clone();
        numOfMusicPieces++;
    }
}

void Concert::removeMusicPiece(int index)
{
    if (index >= 0 && index < numOfMusicPieces)
    {
        delete playList[index];
        for (int i = index; i < numOfMusicPieces; i++)
        {
            if (i < index) {
                playList[i] = playList[i];
            }
            else if (i > index) {
                playList[i-1] = playList[i];
            }
        }
        numOfMusicPieces--;
    }
    else
    {
        cout << "Invalid index. Cannot remove music piece." << endl;
    }
}

void Concert::setTime(int hour, int minutes)
{
    time.setHours(hour);
    time.setMinutes(minutes);
}

void Concert::setDate(int year, int month, int day)
{
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);
}

const Time Concert::getTime(void) const
{
    return time;
}

const Date Concert::getDate(void) const
{
    return date;
}

const int Concert::calcDuration(void) const
{
    int totalDuration = 0;
    for (int i = 0; i < numOfMusicPieces; i++)
    {
        totalDuration += playList[i]->getMusicPieceLength();
    }
    return totalDuration;
}

void Concert::printList(void) const
{
    cout << "Music Playlist:" << endl;
    for (int i = 0; i < numOfMusicPieces; i++)
    {
        cout << "   " << i + 1 << ". ";
        playList[i]->print();
    }
}

void Concert::printConcertInfo(void) const
{
    cout << "Date: ";
    date.print();
    cout << ", Time: ";
    time.print();
    cout << "  , Duration: " << calcDuration() << " minutes" << "\n";
    printList();
}

bool Concert::operator==(const Concert& other) const
{
    return (other.getDate() == date) && (other.getTime() == time);
}

void Concert::operator++()
{
    if(time.getHours() == 23) {
        time.setHours(0);
    }
    else {
        time.setHours(time.getHours() + 1);
        }
}

void Concert::operator--()
{
    if (time.getHours() == 0) {
        time.setHours(23);
    }
    else {
        time.setHours(time.getHours() - 1);
    }
}

Concert* Concert::clone() const
{
    Concert* clonedConcert = new Concert(time.getHours(), time.getMinutes(), date.getYear(), date.getMonth(), date.getDay());
    for (int i = 0; i < numOfMusicPieces; i++)
    {
        clonedConcert->addMusicPiece(*playList[i]);
    }
    return clonedConcert;
}

Concert::~Concert(void)
{
        for (int i = 0; i < numOfMusicPieces; i++) {
            delete playList[i];
        }
        delete[] playList;
}
