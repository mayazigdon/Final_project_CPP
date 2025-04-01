#include "Orchestra.h"
#include "OrchestraExceptions.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Orchestra* Orchestra::instance = nullptr;

Orchestra::Orchestra(const char* name, const char* location, const Conductor& orchestraConductor, int maxNumOfInstruments, int maxNumOfMusicians, int maxNumOfConcerts, int maxNumOfMusicPieces)
    : conductor(orchestraConductor), name(nullptr), Address(nullptr), numOfInstruments(0), numOfMusicians(0), numOfConcerts(0), numOfMusicPieces(0)
{
    try {
        this->name = _strdup(name);
        this->Address = _strdup(location);
    }
    catch (bad_alloc&) {
        delete[] this->name;
        delete[] this->Address;
        throw;
    }

    if (this->name[0] == '\0' || this->Address[0] == '\0') {
        delete[] this->name;
        delete[] this->Address;
        throw InvalidNameException();
    }

    this->maxNumOfInstruments = maxNumOfInstruments;
    this->maxNumOfMusicians = maxNumOfMusicians;
    this->maxNumOfConcerts = maxNumOfConcerts;
    this->maxNumOfMusicPieces = maxNumOfMusicPieces;
    this->musicians = new Musician * [maxNumOfMusicians];
    this->instruments = new Instrument * [maxNumOfInstruments];
    this->concertsList = new Concert * [maxNumOfConcerts];
    this->musicPiecesList = new MusicPiece * [maxNumOfMusicPieces];
}

Orchestra* Orchestra::getInstance(void)
{
    if (instance == nullptr) {
        try {
            instance = new Orchestra("Vienna Philharmonic Orchestra", "Verein der Wiener 12 1010 Vienna, Austria", Conductor("Arturo Toscanini", 2), 20, 30, 15, 30);
        }
        catch (exception& ex) {
            cout << "Exception occurred during Orchestra creation: " << ex.what() << endl;
            delete instance;
            instance = nullptr;
        }
    }
    return instance;
}

const char* Orchestra::getName(void) const
{
    return  this->name;
}

const char* Orchestra::getLocation(void) const
{
    return  this->Address;
}

int Orchestra::getNumOfInstruments(void) const
{
    return  this->numOfInstruments;
}

int Orchestra::getNumOfMusicians(void) const
{
    return  this->numOfMusicians;
}

int Orchestra::getNumOfConcerts(void) const
{
    return  this->numOfConcerts;
}

int Orchestra::getNumOfMusicPiece(void) const
{
    return numOfMusicPieces;
}

Instrument* Orchestra::getInstrumentAtIndex(const int index) const
{
    if (index >= 0 && index < numOfInstruments) {
        return this->instruments[index];
    }
    else {
        throw ObjectNotExistsException();
    }
}

void Orchestra::setName(const char* orchestraName)
{
    delete[] this->name;
    this->name = _strdup(name);
}

void Orchestra::setLocation(const char* orchestraLocation)
{
    memcpy(this->Address, orchestraLocation, sizeof(Address) - 1);
    this->Address[sizeof(Address) - 1] = '\0';
}

void Orchestra::setConductor(const Conductor& other)
{
    conductor = other;
    cout << "Please meet our new conductor:" << endl;
    conductor.print();
}

void Orchestra::addInstrument(const Instrument& instrument)
{
    if (numOfInstruments == maxNumOfInstruments) {
        throw MaxCapacityException();
    }else
        instruments[numOfInstruments++] = instrument.clone();

}

void Orchestra::addMusician(const Musician& musician)
{
    if (numOfMusicians == maxNumOfMusicians) {
        throw MaxCapacityException();
    }else
        musicians[numOfMusicians++] = musician.clone();

}

void Orchestra::addMusicPiece(const MusicPiece& musicPiece)
{
    if (numOfMusicPieces == maxNumOfMusicPieces) {
        throw MaxCapacityException();
    }else
        musicPiecesList[numOfMusicPieces++] = musicPiece.clone();
}

void Orchestra::addConcert(const Concert& concert)
{
    if (numOfConcerts == maxNumOfConcerts) {
        throw MaxCapacityException();
    }
    if (numOfMusicPieces == 0) {
        throw NoSuitableValuesException();
    }
    for (size_t i = 0; i < numOfConcerts; i++)
    {
        if (*concertsList[i]==concert) {
            throw ObjectExistsException();
        }
    }
      concertsList[numOfConcerts++] = concert.clone();
}

void Orchestra::removeConcert(int indexToRemove)
{
    if (indexToRemove < numOfConcerts) {

        Concert** concertsLists = new Concert * [(numOfConcerts) - 1];

        for (int i = 0, x = 0; i < (numOfConcerts); i++, x++)
        {
            if (i == indexToRemove) {
                x--;
            }
            else {
                concertsLists[x] = this->concertsList[i];
            }
        }
        delete this->concertsList[indexToRemove];
        delete[] this->concertsList;
        this->numOfConcerts--;
        this->concertsList = concertsLists;
    }
}

void Orchestra::createAutoConcert(int Duration)
{
    if (numOfConcerts == maxNumOfConcerts) {
        throw MaxCapacityException();
    }
    else if (numOfMusicPieces == 0) {
        throw NoSuitableValuesException();
    }
    else {
        int hour = rand() % 11 + 12;
        int minute = (rand() % 4) * 15;
        int year = 2023;
        int month = rand() % 6 + 7;
        int day = rand() % 28 + 1;
        int numToAdd = rand() % (numOfMusicPieces / 4) + 1;
        Concert* concert = new Concert(hour, minute, year, month, day);
        int nuberOfPieces = numOfMusicPieces - 1;
        do {
            concert->addMusicPiece(*musicPiecesList[nuberOfPieces]);
            nuberOfPieces--;
            Duration -= musicPiecesList[nuberOfPieces]->getMusicPieceLength();
        } while (Duration > 0 && nuberOfPieces > 0);
        concertsList[numOfConcerts] = concert->clone();;
        delete concert;
        numOfConcerts++;
    }
}

void Orchestra::addMusicPiecesToAddedConcert(const int* array, const int arraySize)
{
    if (arraySize > 0)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            if (musicPiecesList[array[i]] == nullptr) {
                throw ObjectNotExistsException();
            }
            else {
                concertsList[numOfConcerts - 1]->addMusicPiece(*musicPiecesList[array[i]]);
            }
        }
    }
}
  
void Orchestra::makeSoloMusician(int index)
{
    if (this->musicians[index]==nullptr)
    {
        throw ObjectNotExistsException();
    }
    else {
        this->musicians[index]->setSoloPlayer(true);
        cout << "Done !, Here is the new information regarding our new solo player." << endl;
        this->musicians[index]->print();
        cout << endl;
    }
}

void Orchestra::compose(const char* name, int min, int max)
{
    try {
        MusicPiece* composed = conductor.compose(name, min, max);
        addMusicPiece(*composed);
        cout << "The following piece has been added to our orchestra: " << endl;
        musicPiecesList[numOfMusicPieces - 1]->print();
        cout << endl;
        delete composed;
    }
    catch (MaxCapacityException()) {
        throw; 
    }
    catch (...) {
        throw;
    }
}

void Orchestra::displaySoloMusicians(void) const
{
    if (musicians == nullptr) {
        throw ObjectNotExistsException();
    }
    else {
        cout << "The following musicans are qualified to play solo:" << endl;
        for (int i = 0, j = 1; i < numOfMusicians; i++)
        {
            if (musicians[i]->getIsSoloPlayer()) {
                cout << j << " ";
                musicians[i]->print();
                j++;
            }
        }
    }
    
}

const int Orchestra::assignInstrument(int instrument, int musician)
{
    if (numOfMusicians == 0 || numOfInstruments == 0) {
        throw NoSuitableValuesException();
    }
    if (instruments[instrument]->canAssignMusicians()) {
        return 1;
    }
    else if (musicians[musician]->doesInstrumentBeenAdded(instruments[instrument])) {
        return 2;
    }
    else if (musicians[musician]->hasReachedMaxInstruments()) {
        return 3;
    }
    else {
        musicians[musician]->addInstrument(instruments[instrument]);
        return 4;
    }
}
void Orchestra::displaySubsribersList() {
    for (int i = 0; i < numOfSubscribers; i++) {
        if (subscribersList[i])// check not nullptr
            subscribersList[i]->print();
    }
}

void Orchestra::displayBasicOrchestra(void) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    cout << "The name of our orchestra is: " << name << endl;
    cout << "We are located at: " << Address << endl;
    cout << "There are total of " << numOfMusicians << " musicians which are instructed by the great conductor " << conductor.getPersonName() << endl;
    cout << "Our orchestra is trained to perform " << numOfMusicPieces << " musical masterpieces with " << numOfInstruments << " different instruments" << endl;
    cout << "and we would like to proudly invite you to vist a least one of our " << numOfConcerts << " future concerts" << endl << endl;
}

void Orchestra::displayOrchestraMembers(void) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    else {
        cout << "There are total of " << numOfMusicians << " musicians which are instructed by the great conductor " << conductor.getPersonName() << "\n";
        displayAllMusicians();
    }
   
}

void Orchestra::displayConcertList(void) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    else {
        if (numOfConcerts == 0) {
            throw ObjectNotExistsException();
        }
        else {
            cout << "We have " << numOfConcerts << " scheduled concerts. Here are the complete details:" << "\n\n";
            for (size_t i = 0; i < numOfConcerts; i++)
            {
                cout << i + 1 << ")";
                concertsList[i]->printConcertInfo();
            }
        }
    }
}

void Orchestra::displayMusicPiecesList(void) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    else {
        for (int i = 0; i < numOfMusicPieces; i++)
        {
            cout << i + 1 << ". ";
            musicPiecesList[i]->print();
        }
    }
}

void Orchestra::displayAllMusicians(void) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    else {
        for (int i = 0; i < numOfMusicians; i++)
        {
            cout << i + 1 << ". ";
            musicians[i]->print();
        }
    }
    cout << endl;
}

void Orchestra::displayAllInstruments(void) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    if (numOfInstruments == 0) {
        throw ObjectNotExistsException();
    }
    else {
        cout << "Our inventory currently includes the following instruments:" << endl;
        for (int i = 0; i < numOfInstruments; i++)
        {
            cout << i + 1 << ". " << instruments[i]->getManufacturerName() << " (In quantity of: " << instruments[i]->getAmount();
            cout << ", Musicians Assigned: " << instruments[i]->getNumOfMusicians() << ")" << endl;
        }
        cout << endl;

    }

}

void Orchestra::displaySingleConcert(int index) const
{
    concertsList[index]->printConcertInfo();
}

void Orchestra::playConcert(int indexToPlay) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    else {
        bool isTuned = true;
        for (size_t i = 0; i < numOfMusicians; i++)
        {
            ++(*musicians[i]);
        }
        ++const_cast<Conductor&>(conductor);
        cout << endl;
        cout << "\nThe concert took place at: " << name << endl;
        cout << "The event details are:" << endl;
        concertsList[indexToPlay]->printConcertInfo();
        if (checkInstrumentsTuning()) {
            cout << "It seems that some of the instruments are not tuned. We can't allow this mistake to happen again. Please check it next time." << endl << endl;
        }
        int randomMusician = rand() % numOfMusicians;
        while (!musicians[randomMusician]->getIsSoloPlayer()) {
            randomMusician = rand() % numOfMusicians;
        }
        musicians[randomMusician]->playInstrument();
        bool detuneInstrument = (rand() % 2 == 0);
        if (detuneInstrument) {
            instruments[rand() % numOfInstruments]->detuneInstrument();
            cout << "Don't forget to check the instruments before the next concert:" << endl << endl;
        }
    }
}

bool Orchestra::checkInstrumentsTuning(void) const
{
    if (getInstance() == nullptr) {
        throw ObjectNotExistsException();
    }
    else {
        for (size_t i = 0; i < numOfInstruments; i++)
        {
            if (instruments[i]->tuneRequired()) {
                return true;
            }
        }
        return false;
    }
}

void Orchestra::addsubscriber(const Subscriber& s) {
    subscribersList[numOfSubscribers++] = s.clone();
}
void Orchestra::unSubscribe(int index) {
    subscribersList[index] = nullptr;
}
bool Orchestra::checkupgrade(int index) {
        if (subscribersList[index]){ // check not null {
            if (subscribersList[index]->getType() == "silver subscriber") {
                SilverSubscriber* temp = dynamic_cast<SilverSubscriber*>(subscribersList[index]);
                return temp->getUpgradeIntrest();
            }
            if (subscribersList[index]->getType() == "simple subscriber") {
                SimpleSubscriber* temp = dynamic_cast<SimpleSubscriber*>(subscribersList[index]);
                return temp->getUpgradeIntrest();
            }    
        }
        return false;
}

void Orchestra::upgrade(int index) {
    if (checkupgrade(index)) {
        Subscriber* temp = subscribersList[index]->clone();
        subscribersList[index] = nullptr;
        if (subscribersList[index]->getType() == "silver subscriber") {
            SilverSubscriber* temp1 = dynamic_cast<SilverSubscriber*>(temp);
            subscribersList[index] = new SilverSubscriber(*temp1);
        }
        if (subscribersList[index]->getType() == "simple subscriber") {
            SimpleSubscriber* temp1 = dynamic_cast<SimpleSubscriber*>(temp);
            subscribersList[index] = new SimpleSubscriber(*temp1);
        }  
    }
}

void Orchestra::dispalaySubsriptionPrivalges() {
    SimpleSubscriber* temp; 
    temp->showPrivalges();
    SilverSubscriber* temp1;
    temp1->showPrivalges();
    GoldenSubscriber* temp2;
    temp2->showPrivalges();
}
Orchestra::~Orchestra(void)
{
    if (instance == this) {
        instance = nullptr;
    }
    delete[] name;
    delete[] Address;
    for (int i = 0; i < numOfInstruments; i++) {
        delete instruments[i];
    }
    delete[] instruments;

    for (int i = 0; i < numOfMusicians; i++) {
        delete musicians[i];
    }
    delete[] musicians;

    for (int i = 0; i < numOfMusicPieces; i++) {
        delete musicPiecesList[i];
    }
    delete[] musicPiecesList;

    for (int i = 0; i < numOfConcerts; i++) {
        delete concertsList[i];
    }
    delete[] concertsList;
}

int Orchestra::getSubsciberBySubscriptionNum(int num) {
    for (int i = 0; i < numOfSubscribers; i++) {
        if (subscribersList[i]->getSubscriptionNum() == num)
            return i;
    }
    return 0;
}

void Orchestra::displaySpecificSubscriber(int index) {
    subscribersList[index]->print();
}

void Orchestra::destroyInstance(void)
{
    delete instance;
    instance = nullptr;
}