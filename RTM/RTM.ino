/*
 Name:		RTM.ino
 Created:	19.03.2018 12:52:26
 Author:	Jonas Frei, Jannik Giger, Martin Seeger
*/

// the setup function runs once when you press reset or power the board
#include "audio.h"
#include "setup_RTM.h"
void setup() {
	initAudio();
	play_Track("track002.mp3");
}

// the loop function runs over and over again until power down or reset
void loop() {
	
}
