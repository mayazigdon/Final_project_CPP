#include "OrchestraFactory.h"
#include <iostream>
#include "Violin.h"
#include "Flute.h"
#include "Cello.h"
#include "Piano.h"
#include "Utilities.h"
#include "ElectricPiano.h"
#include "OrchestraExceptions.h"
using namespace std;

Instrument* OrchestraFactory::createInstrument()
{
	cout << "Please enter the instrument name: " << endl;
	char* manufacturerName{};
	receiveCharSequence(manufacturerName);
	cout << "Please enter the quantity of this instrument: " << endl;
	int quantity, volume, tones;
	quantity = receiveIndexInRange(1,20)+1;
	char instrumentType{};
	Instrument* instrument = nullptr;
	bool keepGoing = true, stick, hasKeys, grand;
	do {
		cout << "Press V/v - to add a new violin." << endl;
		cout << "Press C/c - to add a new cello." << endl;
		cout << "Press F/f - to add a new flute." << endl;
		cout << "Press P/p - to add a new piano." << endl;
		cout << "Press E/e - to add a new electric piano." << endl << endl;
		receiveAlphaChar(&instrumentType);
		switch (instrumentType) {
		case 'V':
		case 'v':
			try {
				instrument = new Violin(manufacturerName, quantity);
			}
			catch (const InvalidNameException& e) {
				cout << "The Violin instrument was not created." << endl;
				e.show();
			}
			keepGoing = false;
			break;
		case 'C':
		case 'c':
			cout << "Does the cello have a support stick?" << endl;
			stick = reciveBoolValue();
			try {
				instrument = new Cello(manufacturerName, quantity, stick);
			}
			catch (const InvalidNameException& e) {
				cout << "The Cello instrument was not created." << endl;
				e.show();
			}
			keepGoing = false;
			break;
		case 'F':
		case 'f':
			cout << "Does the flute have keys?" << endl;
			hasKeys = reciveBoolValue();
			try {
				instrument = new Flute(manufacturerName, quantity, hasKeys);
			}
			catch (const InvalidNameException& e) {
				cout << "The Flute instrument was not created." << endl;
				e.show();
			}
			keepGoing = false;
			break;
		case 'P':
		case 'p':
			cout << "Is it a grand piano?" << endl;
			grand = reciveBoolValue();
			try {
				instrument = new Piano(manufacturerName, quantity, grand);
			}
			catch (const InvalidNameException& e) {
				cout << "The Piano instrument was not created." << endl;
				e.show();
			}
			keepGoing = false;
			break;
		case 'E':
		case 'e':
			cout << "What is the volume level of the piano?" << endl;
			volume = receiveIndexInRange(0, 100);
			cout << "How many tones does the piano have?" << endl;
			tones = receiveIndexInRange(1, 10);
			try {
				instrument = new ElectricPiano(manufacturerName, quantity, tones, volume);
			}
			catch (const InvalidNameException& e) {
				cout << "The Electric Piano instrument was not created." << endl;
				e.show();
			}
			keepGoing = false;
			break;
		default:
			cout << "Invalid instrument type, please try again." << endl << endl;
			break;
		}
	} while (keepGoing);
	delete[] manufacturerName;
	return instrument;
}

Concert* OrchestraFactory::createConcert()
{
	Concert* concert = nullptr;
	int day = 1, month = 1, year = 2023, hour = 16, minutes = 0;
	cout << "Please choose the month for the concert:" << endl;
	month = receiveIndexInRange(1, 12) + 1;
	cout << "Please choose the day:" << endl;
	day = receiveIndexInRange(1, 29) + 1;
	cout << "Please choose the year:" << endl;
	year = receiveIndexInRange(2023, 2024) + 1;
	cout << "Please choose the hour:" << endl;
	hour = receiveIndexInRange(1, 24) + 1;
	concert = new Concert(hour, minutes, year, month, day);
	return concert;
}

Musician* OrchestraFactory::createMusician()
{
	Musician* musician = nullptr;
	try {
		cout << "Enter the musician's name: " << endl;
		char* name{};
		receiveCharSequence(name);
		bool isSolo{};
		cout << "Does the musician play solo? " << endl;
		isSolo = reciveBoolValue();
		musician = new Musician(name, isSolo);
		delete[] name;
		return musician;
	}
	catch (const InvalidNameException& e) {
		cout << "Failed to create the musician." << endl;
		e.show();
		return musician;
	}
	catch (bad_alloc& e) {
		cout << "Failed to create the object due to a system malfunction. Please contact the system manager." << endl;
		const char* errorMessage = e.what();
		cout << errorMessage;
	}
}

Conductor* OrchestraFactory::createConductor()
{
	Conductor* conductor = nullptr;
	try {
		char* conductorName{};
		int style{};
		cout << "Please enter the name of the conductor: " << endl;
		receiveCharSequence(conductorName);
		cout << "Please select the style for the conductor:" << endl;
		cout << "Enter the corresponding number for the desired style:" << endl;
		cout << "1. Classic" << endl;
		cout << "2. Romantic" << endl;
		cout << "3. Modern" << endl;
		cout << "4. Jazz" << endl;
		style = receiveIndexInRange(1, 4)+1;
		conductor = new Conductor(conductorName, style);
		delete[] conductorName;
		return conductor;
	}
	catch (const InvalidNameException& e) {
		cout << "Failed to create the Conductor." << endl;
		e.show();
		return conductor;
	}
	catch (bad_alloc& e) {
		cout << "The Object could not be created due to a system malfunction. Please contact the system manager." << endl;
		const char* errorMessage = e.what();
		cout << errorMessage;
	}
}

MusicPiece* OrchestraFactory::createMusicPiece()
{
	MusicPiece* musicPiece = nullptr;
	try {
		int yearOfRelease{}, lengthInMinutes{};
		char* composerName{}, * pieceName{};
		cout << "Enter the composer's name: " << endl;
		receiveCharSequence(composerName);
		cout << "Enter the release year of the piece: " << endl;
		yearOfRelease = receiveIndexInRange(1800, 2023);
		cout << "Enter the duration of the piece in minutes: " << endl;
		lengthInMinutes = receiveIndexInRange(30, 120);
		cout << "Enter the name of the piece: " << endl;
		receiveCharSequence(pieceName);
		musicPiece = new MusicPiece(pieceName, composerName, yearOfRelease, lengthInMinutes);
		delete[] composerName;
		delete[] pieceName;
		return musicPiece;
	}
	catch (const InvalidNameException& e) {
		cout << "Failed to create the MusicPiece." << endl;
		e.show();
		return musicPiece;
	}
	catch (bad_alloc& e) {
		cout << "Failed to create the object due to a system malfunction. Please contact the system manager." << endl;
		const char* errorMessage = e.what();
		cout << errorMessage;
	}
}
