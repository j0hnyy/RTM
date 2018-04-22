/*
 Name:		RTM.ino
 Created:	19.03.2018 12:52:26
 Author:	Jonas Frei, Jannik Giger, Martin Seeger
*/

// the setup function runs once when you press reset or power the board
#include "display.h"
#include "dcMotorControll.h"
#include "tc3.h"
#include "pwmShield.h"
#include "audio.h"

#define LED_PIN 13
bool isLEDOn = false;

void setup() {
	initAudio();
	play_Track("track001.mp3");

	init_PWM();
	set_PWM(1, 0);

	pinMode(LED_PIN, OUTPUT);
	startTimer(10);
}

// the loop function runs over and over again until power down or reset
void loop() {
	
}

// callback function from timer 3
void TC3_Handler() {
	TcCount16* TC = (TcCount16*)TC3;
	// If this interrupt is due to the compare register matching the timer count
	// we toggle the LED.
	if (TC->INTFLAG.bit.MC0 == 1) {
		TC->INTFLAG.bit.MC0 = 1;
		// Write callback here!!!
		digitalWrite(LED_PIN, isLEDOn);
		isLEDOn = !isLEDOn;
	}
}