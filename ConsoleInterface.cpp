#include "ConsoleInterface.h"
#include "OrchestraFactory.h"
#include "OrchestraExceptions.h"
#include "Utilities.h"
#include "Orchestra.h"

using namespace std;


void Help(void)
{
	cout << "Press H/h - for help" << endl;
	cout << "Press D/d - in order to display the Orchestra's data" << endl; //has sub options of different types of displays
	cout << "Press A/a - in order to add a new concert/instrument/musician/music piece" << endl; //has sub options of different types of adds
	cout << "Press R/r - in order to remove a concert" << endl;
	cout << "Press I/i - in order to assign an instrument to a musician." << endl;;
	cout << "Press C/c - in order to compose a new music piece by the conductor." << endl;
	cout << "Press N/n - in order to set a new conductor for the orchestra." << endl;
	cout << "Press T/t - in order to check the tuning of the instruments." << endl; //has sub option to tune them as well
	cout << "Press S/s - in order to qualify one of the musician a solo player." << endl;//has sub options of musicians
	cout << "Press P/p - in order to play a concert." << endl; //has sub options of concerts
	cout << "Press M/m - in order to subscribe to our orchestra." << endl;// has sub options of subscribe
	cout << "Press Q/q - in order to Quit" << endl << endl;
}

void addSoloMusician(void)
{
	try {
	Orchestra::getInstance()->displayAllMusicians();
	cout << "Please enter the number of the musician you choose to play solo" << endl;
	int index = receiveIndexInRange(1, Orchestra::getInstance()->getNumOfMusicians());
	Orchestra::getInstance()->makeSoloMusician(index);
	}catch (ObjectNotExistsException e) {
		e.show();
		cout << "No musicians are found in the system." << endl;
	}
}

void playConcert(void)
{
	try {
	Orchestra::getInstance()->displayConcertList();
	cout << "Please enter the number of the concert you wish to be performed." << endl;
	int index = receiveIndexInRange(1, Orchestra::getInstance()->getNumOfConcerts());
	Orchestra::getInstance()->playConcert(index);
	}catch (ObjectNotExistsException e) {
		e.show();
		cout << "No concerts are available in the system." << endl;
	}
}

void checkAndTuneInstrument(void)
{
	if (Orchestra::getInstance()->checkInstrumentsTuning())
	{
		cout << "It seems that some instruments are in need of tuning. Here is the full info:" << endl << endl;
		bool saidNoOnce = false;
		for (int i = 0; i < Orchestra::getInstance()->getNumOfInstruments(); i++)
		{
			if (Orchestra::getInstance()->getInstrumentAtIndex(i)->tuneRequired())
			{
				Orchestra::getInstance()->getInstrumentAtIndex(i)->displayTuningInfo();
				cout << "Would you like to tune it?." << endl;
				cout << "Please note that if the instrument is not tuned, the available number of instruments will be decreased." << endl;
				bool opt = reciveBoolValue();
				if (opt)
				{
					Orchestra::getInstance()->getInstrumentAtIndex(i)->tuneInstrument();
					++(*(Orchestra::getInstance()->getInstrumentAtIndex(i)));
				}
				else
				{
					if (!saidNoOnce)
					{
						--(*(Orchestra::getInstance()->getInstrumentAtIndex(i)));
						cout << "Friendly advice - bring some earplugs to the concert, the music is going to be painful..." << endl << endl;
						saidNoOnce = true;
					}
				}
			}
		}
	}
	else
	{
		cout << "All the instruments are tuned. Excellent!" << endl;
	}
}

void removeConcert(void)
{
	int indexToRemove{};
	try {
		Orchestra::getInstance()->displayConcertList();
		cout << "Please enter the concert you would like to remove." << endl;
		indexToRemove = receiveIndexInRange(1, Orchestra::getInstance()->getNumOfConcerts());
		Orchestra::getInstance()->removeConcert(indexToRemove);
		cout << "Removed !" << endl;
	}
	catch (ObjectNotExistsException e) {
		e.show();
		cout << "No concerts found in the system." << endl;
	}
}

void assignInstrument(void)
{
	try {
		int indexOfMusician{}, returnValue{}, indexOfInstrument{};
		Orchestra::getInstance()->displayAllInstruments();
		cout << "Please select the instrument you would like to assign:" << endl;

		indexOfInstrument = receiveIndexInRange(1, Orchestra::getInstance()->getNumOfInstruments());
		cout << "Please select the musician you wish to assign the instrument:" << endl;
		Orchestra::getInstance()->displayAllMusicians();
		indexOfMusician = receiveIndexInRange(1, Orchestra::getInstance()->getNumOfMusicians());
		returnValue = Orchestra::getInstance()->assignInstrument(indexOfInstrument, indexOfMusician);
		switch (returnValue)
		{
		case 1:
			cout << "The number of assigned musicians cannot exceed the available quantity." << endl << endl;
			break;
		case 2:
			cout << "The following musician is already assigned to the instrument." << endl << endl;
			break;
		case 3:
			cout << "Each musician cannot be assigned to more than 3 instruments." << endl << endl;
			break;
		case 4:
			cout << "Done!." << endl << endl;
			break;
		};
	}
	catch (ObjectNotExistsException) {
		cout << "Please ensure that the system has both instruments and musicians available." << endl << endl;
	}
}

void composeMusicPiece(void)
{
	char* pieceName{};
	int minDuration{}, maxDuration{};
	cout << "Please enter the name of the desired piece." << endl;
	receiveCharSequence(pieceName);
	cout << "Please enter the desired minimum duration for the piece." << endl;
	minDuration = receiveIndexInRange(1, 30);
	cout << "Please enter the desired maximum duration for the piece." << endl;
	maxDuration = receiveIndexInRange(40, 120);
	Orchestra::getInstance()->compose(pieceName, minDuration, maxDuration);
}

void changeConductor(void)
{
	Conductor* conductor = OrchestraFactory::createConductor();
	Orchestra::getInstance()->setConductor(*conductor);
	delete conductor;
}

void displayOrchestra(void)
{
	bool keepGoing = true;
	char display{};
	do
	{
		cout << "Press B/b - in order to display the orchestra basic information." << endl; // displays the name, address, conductor, and number of musicians and all instruments and their quantities
		cout << "Press S/s - in order to display all the solo playing musicians." << endl;
		cout << "Press C/c - in order to display all the planned concerts." << endl;
		cout << "Press M/m - in order to display the orchestra members (conductor & musicians)." << endl;
		cout << "Press O/o - in order to display all the instruments." << endl;
		cout << "Press X/x - in order to return backward." << endl << endl;
		receiveAlphaChar(&display);
		switch (display)
		{
		case 'B':
		case 'b':
			Orchestra::getInstance()->displayBasicOrchestra();
			break;
		case 'S':
		case 's':
			Orchestra::getInstance()->displaySoloMusicians();
			break;
		case 'C':
		case 'c':
			Orchestra::getInstance()->displayConcertList();
			break;
		case 'O':
		case 'o':
			Orchestra::getInstance()->displayAllInstruments();
			break;
		case 'M':
		case 'm':
			Orchestra::getInstance()->displayOrchestraMembers();
			break;
		case 'X':
		case 'x':
			keepGoing = false;
			break;
		default:
			cout << "Incorrect input, please try again." << endl << endl;
			break;
		}
	} while (keepGoing);
}

void addData(void)
{
	Instrument* instrument = nullptr;
	MusicPiece* newPiece = nullptr;
	Musician* newMusician = nullptr;
	bool keepGoing = true;
	char addData{};
	do
	{
		cout << "Press B/b - to add a new concert." << endl; // lets you choose if you want the process to be manual or automatic
		cout << "Press I/i - to add a new instrument." << endl; // lets you assign a musician as well
		cout << "Press P/p - to add a new music piece." << endl;
		cout << "Press M/m - to add a new musician." << endl;
		cout << "Press X/x - in order to return backward." << endl << endl; 
		receiveAlphaChar(&addData);
		switch (addData)
		{
		case 'B':
		case 'b':
			addConcert();
			break;
		case 'I':
		case 'i':
			instrument = OrchestraFactory::createInstrument();
			Orchestra::getInstance()->addInstrument(*instrument);
			cout << "The Instrument has been added successfully to our inventory!" << endl;
			delete instrument;
			break;
		case 'P':
		case 'p':
			newPiece = OrchestraFactory::createMusicPiece();
			Orchestra::getInstance()->addMusicPiece(*newPiece);
			cout << "The MusicPiece has been added successfully to our playlist!" << endl;
			delete newPiece;
			break;
		case 'M':
		case 'm':
			newMusician = OrchestraFactory::createMusician();
			Orchestra::getInstance()->addMusician(*newMusician);
			cout << "The Musician has been added successfully to our orchestra!" << endl;
			delete newMusician;
			break;
		case 'X':
		case 'x':
			keepGoing = false;
			break;
		default:
			cout << "Incorrect input, please try again." << endl << endl;
			break;
		}
	} while (keepGoing);
}

void addConcert(void)
{
	// sub function of addData
	cout << "Would you like to add the concert manually - Press Y/N." << endl; // lets the user choose the date, time, and music pieces
	char addConcert{}, tryAgain{};
	bool keepGoing = true;
	int size = 0, concertDuration = 0;
	int* musicPieces{};
	Concert* concert = nullptr;
	do
	{
		receiveAlphaChar(&addConcert);
		switch (addConcert)
		{
		case 'Y':
		case 'y':
			concert = OrchestraFactory::createConcert();
			try {
				Orchestra::getInstance()->addConcert(*concert);
			}
			catch (MaxCapacityException e) {
				e.show();
			}
			catch (ObjectExistsException e) {
				e.show();
				cout << "It seems that our orchestra has a different performance at this date and time." << endl;
				cout << "Here are the details of the concert that you tried to add." << endl;
				concert->printConcertInfo();
				adjustConcertData(concert);
				try {
					Orchestra::getInstance()->addConcert(*concert);
				}
				catch (ObjectExistsException e) {
					delete concert;
					cout << "The concert was not added to the system." << endl;
					keepGoing = false;
					break;
				}
			}
			delete concert;
			cout << "Please select the desired music pieces for the concert - Max 6." << endl;
			Orchestra::getInstance()->displayMusicPiecesList();
			musicPieces = receiveIntArray(Orchestra::getInstance()->getNumOfMusicPiece(), 6, &size);
			if (size > 0) {
				Orchestra::getInstance()->addMusicPiecesToAddedConcert(musicPieces, size);
				cout << "Done! Below is the updated schedule, including our new concert." << endl;
				Orchestra::getInstance()->displayConcertList();
			}
			else {
				Orchestra::getInstance()->removeConcert(Orchestra::getInstance()->getNumOfConcerts() - 1);
				cout << "The concert cannot be added without a playlist." << endl;
			}
			delete[] musicPieces;
			keepGoing = false;
			break;
		case 'N':
		case 'n':
			try {
				cout << "Please enter the minimal duration for the concert." << endl;
				concertDuration = receiveIndexInRange(30, 120);
				Orchestra::getInstance()->createAutoConcert(concertDuration);
				keepGoing = false;
			}
			catch (NoSuitableValuesException e) {
				e.show();
				cout << "The concert cannot be added to the system. Please ensure that the orchestra has music pieces available." << endl;
				keepGoing = false;
				break;
			}
			cout << "Done! Below is the updated schedule, including our new concert." << endl;
			Orchestra::getInstance()->displayConcertList();;
			break;
		default:
			cout << "Incorrect input, please try again." << endl<< endl;
			break;
		};
	} while (keepGoing);
}

void adjustConcertData(Concert* concert)
{
	cout << "Would you like to change the time or date of the concert and try again?" << endl;
	if (reciveBoolValue()) {
		cout << "Would you like to change the date?" << endl;
		if (reciveBoolValue()) {
			int month, day, year;
			year = concert->getDate().getYear();
			cout << "Please enter the new month at which the concert will take place:" << endl;
			month = receiveIndexInRange(1, 12)+1;
			cout << "Please enter the day:" << endl;
			day = receiveIndexInRange(1, 29)+1;
			concert->setDate(year, month, day);
		}
		cout << "Would you like to change the time?" << endl;
		if (reciveBoolValue()) {
			char decreaseOrincrease{};
			cout << "Press + to increase the hour, - to decrease the hour, or 'x' to exit: " << endl;
			while (decreaseOrincrease != 'x' && decreaseOrincrease != 'X') {
				cin >> decreaseOrincrease;
				cleanBuffer();
				if (decreaseOrincrease == '-') {
					--(*concert);
					cout << "The new time is: ";
					concert->getTime().print();
					cout  << endl;
				}
				else if (decreaseOrincrease == '+') {
					++(*concert);
					cout << "The new time is: ";
					concert->getTime().print();
					cout  << endl;
				}
				else if (decreaseOrincrease != 'x' && decreaseOrincrease != 'X') {
					cout << "Incorect input, please try again" << endl << endl;
				}
			}
		}
	}
}
int chooseSubscription() {
	int choice;
	cout << "please choose index of one of the following options: " << endl;
	cout << "simple program..............................1" << endl;
	cout << "silver program..............................2" << endl;
	cout << "gold program................................3 " << endl;
	cin >> choice;
	return choice;
}
void chooseVipMeal(GoldenSubscriber* g) {
	cout << "good evening! please choose from menu below" << endl;
	g->getDinner().printMenu();
	cout << "please choose main course (please enter index)" << endl;
	int index;
	cin >> index;
	g->getDinner().chooseMeal(index);
	cout << "please choose side dish (please enter index)" << endl;
	cin >> index;
	g->getDinner().chooseSideDish(index);
	cout << "please choose a drink (please enter index)" << endl;
	cin >> index;
	g->getDinner().chooseDrink(index);
	cout << "please choose a dessert (please enter index)" << endl;
	cin >> index;
	g->getDinner().chooseDessert(index);
}


void editPremiumSubscribersPreferences(int index) {
	Subscriber* s = Orchestra::getInstance()->getSubscriberBYIndex(index);
	const char* type = s->getType();
	if (type == "simple subscriber")
		cout << " no preference to edit";
	if (type == "silver subscriber") {
		SilverSubscriber* temp = dynamic_cast<SilverSubscriber*>(s);
		cout << "lets choose dinner!" << endl;
		temp->printMealMenu();
		int choice;
		cin >> choice;
		temp->chooseMeal(choice);
	}
	if (type == "golden subscriber") {
		GoldenSubscriber* temp = dynamic_cast<GoldenSubscriber*>(s);
		cout << "lets choose dinner!" << endl;
		chooseVipMeal(temp);
		cout << "your entrance time backstage is set to: ";
		temp->getEntranceTime().print();
		cout << "would you like to change entrance time?(yes/no)" << endl;
		char* ans;
		int hours, minutes; 
		cin >> ans; 
		if (ans == "yes") {
			cout << "what is the desired hour? (between 6-8 only )" << endl;
			cin >> hours;
			cout << "minutes ? " << endl;
			cin >> minutes;
			temp->setEntranceTime(hours, minutes);
		}
	}
}
void subscibersEditor() {
	int choice2;
	int index=0;
	bool keepGoing = true;
	do
	{
		char choice{};
		cout << "Press A/a - to show privlages and costs of each subscription program" << endl;
		cout << "Press B/b - to add subscriber" << endl; 
		cout << "Press C/c - to upgrade subscriber " << endl; 
		cout << "Press D/d - edit subscription preferrnce of premium subscribers" << endl;
		cout << "Press E/e - to watch subsribers list" << endl;
		cout << "press F/f - to watch details of spesific subscriber"<< endl;
		cout << "press G/g - to unsubscribe " << endl;
		cout << "Press X/x - in order to return backward." << endl << endl;
		receiveAlphaChar(&choice);
		switch (choice)
		{
		case 'A':
		case 'a':
			Orchestra::getInstance()->dispalaySubsriptionPrivalges();
			break;
		case 'B':
		case 'b':
			char* name;
			cout << "please enter new Subscriber's name" << endl;
			cin >> name;
			cout << " what subscriprion program would you like to join?" << endl;
			choice2 = chooseSubscription();
			switch (choice2)
			{
			case 1: 
				SimpleSubscriber* newSub = new SimpleSubscriber(name);
				Orchestra::getInstance()->addsubscriber(*newSub);
				break;
			case 2:
				SilverSubscriber* newSub1 = new SilverSubscriber(name);
				Orchestra::getInstance()->addsubscriber(*newSub);
				break;
			case 3:
				GoldenSubscriber* newSub2 = new GoldenSubscriber(name);
				Orchestra::getInstance()->addsubscriber(*newSub);
				break;
			}
		case 'C':
		case 'c':
			Orchestra::getInstance()->displaySubsribersList();
			cout << "upgrade subscriber " << endl;
			cout << "please enter subscriber's subscriptionNumber: " << endl;
			int subscriptionNum;
			cin >> subscriptionNum;
			index=  Orchestra::getInstance()->getSubsciberBySubscriptionNum(subscriptionNum);
			if (!index)
				cout << "we havent found such user in our system...";
			else {
				Orchestra::getInstance()->upgrade(index);
				Orchestra::getInstance()->displaySpecificSubscriber(index);
			}
			break;
		case 'D':
		case 'd':
			Orchestra::getInstance()->displaySubsribersList();
			cout << "edit subscription preferrnce of premium subscribers:" << endl;
			cout << "please enter subscriber's subscriptionNumber: " << endl;
			 index = Orchestra::getInstance()->getSubsciberBySubscriptionNum(subscriptionNum);
			if (!index)
				cout << "we havent found such user in our system...";
			else
			{
				editPremiumSubscribersPreferences(index);
			}
			break;
		case 'E':
		case 'e':
			Orchestra::getInstance()->displaySubsribersList();
			break;
		case 'F':
		case 'f':
			cout << "to display spesific information of subscriber , please enter its subscription number " << endl;
			int num; 
			cin >> num; 
			 index=  Orchestra::getInstance()->getSubsciberBySubscriptionNum(num);
			if (!index)
				cout << " subscription number wasnt found in system" << endl;
			Subscriber* temp = Orchestra::getInstance()->getSubscriberBYIndex(index);
			temp->print();
			break;
		case 'G':
		case 'g':
			cout << "to unsubscribe please enter subscription number" << endl;
			 num;
			cin >> num;
			 index = Orchestra::getInstance()->getSubsciberBySubscriptionNum(num);
			if (!index)
				cout << " subscription number wasnt found in system" << endl;
			Orchestra::getInstance()->unSubscribe(index);
			keepGoing = false;
			break;
		case 'X':
		case 'x':
			keepGoing = false;
			break;
		default:
			cout << "Incorrect input, please try again." << endl << endl;
			break;
		}
	} while (keepGoing);
}