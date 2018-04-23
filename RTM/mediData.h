// mediData.h

#ifndef _MEDIDATA_h
#define _MEDIDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


typedef struct {
	String name = "kein Medikament vorhanden";
	int day[7] = {};
	int dayTime[4] = {};
	int amount = 00;
	int containerNr = 0;
}MEDI;


void set_medi(MEDI *mediToset);

#endif
