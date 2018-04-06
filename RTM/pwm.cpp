// pwm.cpp
// author: Jonas Frei
// contains all functions related to the 8 channel pwm controller

#include "pwm.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void init_Pwm(void) {
	Serial.begin(9600);
	pwm.begin();
	pwm.setPWMFreq(1600);
	Wire.setClock(400000);
}

