#pragma once

#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    static int idGenerator; 
    int id;  
    char* name = nullptr;
    int experience = 0;

public:
    Person(const char* Name);
    Person(const Person& other); // copy
    Person(Person&& other) noexcept; // move
    Person& operator=(const Person& other); // assignment operator

    const int getExperience(void) const;
    void setExperience(const int number);
    char* getPersonName(void) const;
    const int getID(void) const { return id; };
    virtual void print(void) const = 0;
    void operator++(void);
    bool operator==(const Person& other) const;
    virtual ~Person(void);

};

#endif // PERSON_H
