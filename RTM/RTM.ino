/*
 Name:		RTM.ino
 Created:	19.03.2018 12:52:26
 Author:	Jonas Frei, Jannik Giger, Martin Seeger
*/

// the setup function runs once when you press reset or power the board
#include "tc3.h"
#include "pwmShield.h"
#include "audio.h"
#include "setup_RTM.h"

#define LED_PIN 13

void setup() {
	initAudio();
	play_Track("track001.mp3");
	init_PWM();
	set_PWM(1, 0);
	play_Track("track002.mp3");
	pinMode(LED_PIN, OUTPUT);
	startTimer(10);
}

// the loop function runs over and over again until power down or reset
void loop() {
	
}