// 
// 
// 

#include "pwmShield.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void init_PWM(void) {
	pwm.begin();
	pwm.setPWMFreq(60);
	Wire.setClock(100000);
}

void set_PWM(int Nr, int dutyCycle) {
	pwm.setPin(Nr, 500, false);
}


