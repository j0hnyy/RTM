// pwmMotorControl.h

#ifndef _PWMMOTORCONTROL_h
#define _PWMMOTORCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#endif

void init_Pwm(void);