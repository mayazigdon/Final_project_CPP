#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

class OrchestraExceptions : public exception {
public:
    virtual void show(void) const;
};

class InvalidNameException : public OrchestraExceptions {
public:
    void show(void) const override;
};

class ObjectExistsException : public OrchestraExceptions {
public:
    void show(void) const override;
};

class ObjectNotExistsException : public OrchestraExceptions {
public:
    void show(void) const override;
};

class MaxCapacityException : public OrchestraExceptions {
public:
    void show(void) const override;
};

class NoSuitableValuesException : public OrchestraExceptions {
public:
    void show(void) const override;
};