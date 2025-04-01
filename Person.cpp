#include "Person.h"
#include <iostream>
#include <ctime>
#include "OrchestraExceptions.h"

using namespace std;

int Person::idGenerator = 100;

Person::Person(const char* name)
{
    try {
        this->name = _strdup(name);
    }
    catch (bad_alloc&) {
        delete[] this->name;
        throw;
    }
    if (this->name[0] == '\0') {
        delete[] this->name;
        throw InvalidNameException();
    }
    id = idGenerator;
    idGenerator++;
}

Person::Person(const Person& other) // copy
{
    try {
        name = new char[strlen(other.name) + 1];
        memcpy(name, other.name, strlen(other.name));
        name[strlen(other.name)] = '\0';
        experience = other.experience;
        id = other.id;
    }
    catch (bad_alloc&) {
        delete[] this->name;
        throw;
    }
}

Person::Person(Person&& other) noexcept // move
{
    name = other.name;
    experience = other.experience;
    id = other.id;

    other.name = nullptr;
    other.experience = NULL;
    other.id = NULL;
}

const int Person::getExperience(void) const
{
    return experience;
}

void Person::setExperience(int num)
{
    experience = num;
}

char* Person::getPersonName(void) const
{
    return name;
}

Person::~Person(void)
{
    delete[] name;
}

void Person::operator++(void)
{
    experience++;
}

bool Person::operator==(const Person& other) const
{
    return (id == other.id);
}

Person& Person::operator=(const Person& other)
{
    if (this == &other) {
        return *this;
    }

    delete[] name;
    this->name = new char[strlen(other.name) + 1];
    memcpy(this->name, other.name, strlen(other.name));
    this->name[strlen(other.name)] = '\0';
    this->experience = other.experience;

    return *this;
}
