#include "Utilities.h"

using namespace std;

void receiveAlphaChar(char* toUpdate) {
	char charFromUser;
	bool keepAlive = true;
	do {
		cin >> charFromUser;
		cleanBuffer();
		if ((charFromUser >= 'a' && charFromUser <= 'z') || (charFromUser >= 'A' && charFromUser <= 'Z')) {
			keepAlive = false;
			*toUpdate = charFromUser;
		}
		else {
			cout << "Invalid input! Please enter a character from the alphabet" << endl;
		}
	} while (keepAlive);
}

int* receiveIntArray(int maxValue, int arraySize, int* trueSize)
{
	cout << "In order to stop, enter -1." << endl;
	int* array = new int[arraySize];
	int temp = 0, count = 0;
	bool keepGoing = true;
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = -1;
	};
	while (keepGoing) {
		temp = receiveIndexInRange(-1, maxValue);
		if ((count == arraySize - 1) || (temp < 0)) {
			keepGoing = false;
			array[count] = temp;
		}
		else if (checkIfValueExists(array, arraySize, temp)) {
			cout << "The entered value has already been used" << endl;
		}
		else {
			array[count] = temp;
			count++;
		}
	};
	*trueSize = count;
	return array;
}

void cleanBuffer() {
	int x;
	do {
		x = getchar();
	} while (x != EOF && x != '\n');
}

void receiveCharSequence(char*& saveHere) {
	char toReceive[50]{};
	bool keepAsking = true, hasNumbers = false;
	do {
		hasNumbers = false;
		cin.getline(toReceive, sizeof(toReceive));
		if (strlen(toReceive) == 0) {
			cout << "Invalid input! Please enter a non-empty string." << endl;
		}
		else {
			for (size_t i = 0; toReceive[i] != '\0'; i++)
			{
				if (isdigit(toReceive[i])) {
					hasNumbers = true;
				}
			}
			if (!hasNumbers) {
				keepAsking = false;
			}
			else {
				cout << "Invalid input! The character sequence should not contain numbers." << endl;
			}
		}
	} while (keepAsking);
	saveHere = new char[sizeof(toReceive) + 1];
	memcpy(saveHere, toReceive, sizeof(toReceive));
	saveHere[strlen(saveHere)] = '\0';
}

int receiveIndexInRange(int min, int max) {
	int tempValue{};
	bool keepAlive = true;

	do {
		if (cin >> tempValue) {
			if (tempValue > min - 1 && tempValue < max + 1) {
				keepAlive = false;
			}
			else {
				cout << "Please enter a number between " << min << " - " << max << endl;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cout << "Invalid input! Please enter a number between " << min << " - " << max << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (keepAlive);

	return tempValue - 1;
}

bool checkIfValueExists(int* array, int arraySize, int value) {
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] == value) {
			return true;
		}
	};
	return false;
}

bool reciveBoolValue(void) {
	cout << "Please press Y/N" << endl;
	bool isTrue, keepGoing = true;
	char getInput;
	do {
		receiveAlphaChar(&getInput);
		switch (getInput)
		{
		case 'Y':
		case 'y':
			isTrue = true;
			keepGoing = false;
			break;
		case 'N':
		case 'n':
			isTrue = false;
			keepGoing = false;
			break;
		default:
			cout << "Incorect input, please try again"<< endl;
			break;
		}
	} while (keepGoing);
	return isTrue;
}

