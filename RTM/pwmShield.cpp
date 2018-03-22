// 
// 
// 

#include "pwmShield.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void init_Pwm(void) {
	Serial.begin(9600);
	pwm.begin();
	pwm.setPWMFreq(1600);
	Wire.setClock(400000);
	pwm.setPWM(1, 0, 4000);
}

void run_Pwm(void) {
	pwm.setPWM(1, 0, (5 + (4096 / 16) * 1) % 4096);
}


