#pragma once
#ifndef INSTRUMENT_PLAYER_H
#define INSTRUMENT_PLAYER_H
#include "Instrument.h"


class InstrumentPlayer
{
private:
    int numOfInstruments;
    Instrument** instruments;
    const int MAX_COUNT = 3;
public:
  InstrumentPlayer(void);
  InstrumentPlayer(const InstrumentPlayer& other); //copy
  InstrumentPlayer(InstrumentPlayer&& other)noexcept; //move

  const Instrument* getInstrument(const int index) const;
  const int getNumOfInstruments(void) const;
  const int getMaxCount(void) const;
  void addInstrument(Instrument* instrument);
  const void displayInstruments(void) const;
  const bool doesInstrumentBeenAdded(const Instrument* instrument) const;
  const bool hasReachedMaxInstruments(void) const;
  virtual void playInstrument(void)const = 0;
  virtual ~InstrumentPlayer(void);
  InstrumentPlayer& operator=(const InstrumentPlayer& other); //=
};
#endif // INSTRUMENT_PLAYER_H
