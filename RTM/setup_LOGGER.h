// setup_LOGGER.h

#ifndef _SETUP_LOGGER_h
#define _SETUP_LOGGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include <RTClib.h>
	#include "mediData.h"

#else
	#include "WProgram.h"
#endif
void init_SD();
void SD_logger(DateTime date_Time, MEDI *medi);

#endif

