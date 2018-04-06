// pwmShield.h

#ifndef _PWMSHIELD_h
#define _PWMSHIELD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void init_PWM(void);

void set_PWM(int Nr, int dutyCycle);

#endif

