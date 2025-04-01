#pragma once
#include <iostream>
#include "Instrument.h"
#include "Concert.h"
#include "musicPiece.h"
#include "Musician.h"
#include "Conductor.h"

class OrchestraFactory
{
public:
	static Instrument* createInstrument(void);
	static Concert* createConcert(void);
	static Musician* createMusician(void);
	static Conductor* createConductor(void);
	static MusicPiece* createMusicPiece(void);
};

