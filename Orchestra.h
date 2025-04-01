#pragma once
#ifndef ORCHESTRA_H
#define ORCHESTRA_H

#include "Instrument.h"
#include "Conductor.h"
#include "Musician.h"
#include "musicPiece.h"
#include "Concert.h"
#include "Subscriber.h"
#include "SimpleSubscriber.h"
#include "GoldenSubscriber.h"
#include "SilverSubscriber.h"

class Orchestra
{
private:
    char* name;
    char* Address;
    int maxNumOfInstruments = 0;
    int maxNumOfMusicians = 0;
    int maxNumOfConcerts = 0;
    int maxNumOfMusicPieces = 0;
    int numOfInstruments;
    int numOfMusicians;
    int numOfConcerts;
    int numOfMusicPieces;
    int numOfSubscribers;
    const int MAX_SUBSCRIBERS = 900;

    Instrument** instruments;
    Musician** musicians;
    MusicPiece** musicPiecesList;
    Concert** concertsList;
    Subscriber** subscribersList;
    Conductor conductor;

    Orchestra(const char* name, const char* location, const Conductor& orchestraConductor, int maxNumOfInstruments, int maxNumOfMusicians, int maxNumOfConcerts, int maxNumOfMusicPieces);
    Orchestra(const Orchestra& other) = delete;
    Orchestra& operator=(const Orchestra& other) = delete;
    static Orchestra* instance;

public:
    static Orchestra* getInstance(void); // singleton
    const char* getName(void) const;
    const char* getLocation(void) const;
    int getNumOfInstruments(void) const;
    int getNumOfMusicians(void) const;
    int getNumOfConcerts(void) const;
    int getNumOfMusicPiece(void) const;
    Instrument* getInstrumentAtIndex(const int index) const;
    void setName(const char* orchestraName);
    void setLocation(const char* orchestraLocation);
    void setConductor(const Conductor&);
    void addInstrument(const Instrument& instrument);
    void addMusician(const Musician& musician);
    void addMusicPiece(const MusicPiece& musicPiece);
    void addConcert(const Concert& concert);
    void removeConcert(const int indexToRemove);
    void createAutoConcert(const int Duration);
    void addMusicPiecesToAddedConcert(const int* array, const int arraySize);
    const int assignInstrument(const int instrument, const int musician);
    void makeSoloMusician(const int index);
    void displayBasicOrchestra(void) const;
    void displayOrchestraMembers(void) const;
    void displaySoloMusicians(void) const;
    void displayConcertList(void) const;
    void displayMusicPiecesList(void) const;
    void displayAllMusicians(void) const;
    void displayAllInstruments(void) const;
    void displaySingleConcert(const int index) const;
    void compose(const char* name, const int min, const int max);
    void playConcert(const int indexToPlay) const;
    bool checkInstrumentsTuning(void) const;
    void addsubscriber(const Subscriber& s);
    void unSubscribe(int index);
    bool checkupgrade(int index);
    void upgrade(int index);
    void dispalaySubsriptionPrivalges();
    //void editPremiumSubscribersPreferences(int index);
    Subscriber* getSubscriberBYIndex(int index) { return subscribersList[index]; };
    void displaySubsribersList();
    int getSubsciberBySubscriptionNum(int num);
    void displaySpecificSubscriber(int index);
    ~Orchestra(void);
    void destroyInstance(void);
};

#endif // ORCHESTRA_H