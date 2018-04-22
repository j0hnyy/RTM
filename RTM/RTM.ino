/*
 Name:		RTM.ino
 Created:	19.03.2018 12:52:26
 Author:	Jonas Frei, Jannik Giger, Martin Seeger
*/

// the setup function runs once when you press reset or power the board
#include <Time.h>
#include <TimeLib.h>
#include <Wire.h>
#include "display.h"
#include "tc3.h"
#include "pwmShield.h"
#include "audio.h"

#define LED_PIN 13

void setup() {
	Wire.begin();			// Join I2C bus
	initAudio();
	play_Track("track001.mp3");
	init_PWM();
	set_PWM(1, 0);
	play_Track("track002.mp3");
	pinMode(LED_PIN, OUTPUT);
	startTimer(10);
	setTime(17, 36, 0, 1, 1, 2018);
}

// the loop function runs over and over again until power down or reset
void loop() {
	sendDataToDisp(0);
	delay(5000);
	dispClock();
	delay(5000);
	sendDataToDisp(3, "Test1", "Test2");
	delay(5000);
	sendDataToDisp(4, "Test", "Test4", "Test5");
	delay(5000);
}