#include "OrchestraExceptions.h"

void OrchestraExceptions::show(void) const {
    cout << "General Error, Please contact the system manager." << endl;
}

void InvalidNameException::show() const {
    cout << "The name cannot be empty. Please provide a valid name." << endl << "The object hasn't been created." << endl;
}

void ObjectExistsException::show() const {
    cout << "The system already has an object with the provided value." << endl;
}

void ObjectNotExistsException::show() const {
    cout << "The operation could not be performed because the object does not exist." << endl << "Please contact the system manager." << endl;
}

void MaxCapacityException::show() const {
    cout << "The operation cannot be completed as the system has reached its maximum capacity." << endl << "Please contact the system manager." << endl;
}

void NoSuitableValuesException::show(void) const
{
    cout << "The operation cannot be performed as the system lacks the necessary information." << endl;
}
