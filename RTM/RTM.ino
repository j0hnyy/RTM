/*
 Name:		RTM.ino
 Created:	19.03.2018 12:52:26
 Author:	Jonas Frei, Jannik Giger, Martin Seeger
*/

// the setup function runs once when you press reset or power the board
#include <SD.h>
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include "setup_RTM.h"
void setup() {
	set_RTM();
	musicPlayer.playFullFile("track001.mp3");
}

// the loop function runs over and over again until power down or reset
void loop() {
	
}
