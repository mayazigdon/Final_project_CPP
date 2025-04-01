#pragma once
#include <iostream>
#include "Orchestra.h"

void Help(void);
void displayOrchestra(void);
void addData(void);
void addConcert(void);
void addSoloMusician(void);
void playConcert(void);
void composeMusicPiece(void);
void checkAndTuneInstrument(void);
void changeConductor(void);
void removeConcert(void);
void assignInstrument(void);
void adjustConcertData(Concert* concert);//sub function of addConcert
void subscibersEditor();
void chooseVipMeal(GoldenSubscriber* g);
void editPremiumSubscribersPreferences(int index);