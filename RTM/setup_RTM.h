// setup_RTM.h

#ifndef _SETUP_RTM_h
#define _SETUP_RTM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void set_RTC(void);

#endif

