#pragma once
#ifndef CONCERT_H
#define CONCERT_H

#include "MusicPiece.h"
#include "Time.h"
#include "Date.h"

class Concert
{
private:
    MusicPiece** playList;
    int numOfMusicPieces;
    const int MAX_MUSIC_PIECES = 6;
    Time time;
    Date date;

public:
    Concert(int hour, int minute, int year, int month, int day);
    void addMusicPiece(const MusicPiece& musicPiece);
    void removeMusicPiece(int index);
    void setTime(int hour, int minute);
    void setDate(int year, int month, int day);
    const Time getTime(void) const;
    const Date getDate(void) const;
    Concert* clone(void) const;
    const int calcDuration(void) const;
    void printList(void) const;
    void printConcertInfo(void) const;

    bool operator==(const Concert& other) const;
    void operator++(void);
    void operator--(void);

    ~Concert(void);
};

#endif // CONCERT_H
