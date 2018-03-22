// 
// 
// 

#include "pwmShield.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void init_Pwm(void) {
	pwm.begin();
	pwm.setPWMFreq(1000);
	Wire.setClock(400000);
}

void run_Pwm(void) {
	pwm.setPin(0, 2000, false);
}


