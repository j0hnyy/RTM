// tc3.h

#ifndef _TC3_h
#define _TC3_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// call this function to start the timer 3 with the desired frequency in Hz
void startTimer(int frequencyHz);

#endif

