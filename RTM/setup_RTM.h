// setup_RTM.h

#ifndef _SETUP_RTM_h
#define _SETUP_RTM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include <Wire.h>
	#include "RTClib.h"
#else
	#include "WProgram.h"


#endif

void init_RTC();
DateTime get_Time_Date();
void print_Serial(DateTime now);

#endif

