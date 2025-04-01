#pragma once

#include <iostream>

void cleanBuffer(void);
void receiveAlphaChar(char* ptr);
void receiveCharSequence(char*& saveHere);
int* receiveIntArray(const int maxValue, const int arraySize, int* trueSize);
bool checkIfValueExists(int* array, const int arraySize, const int value);
bool reciveBoolValue(void);
int receiveIndexInRange(const int min, const int max);
