/*
 Name:		RTM.ino
 Created:	19.03.2018 12:52:26
 Author:	Jonas Frei, Jannik Giger, Martin Seeger
*/

// the setup function runs once when you press reset or power the board
#include <SysCall.h>
#include <SdFatConfig.h>
#include <SdFat.h>
#include <MinimumSerial.h>
#include <FreeStack.h>
#include <BlockDriver.h>
#include "setup_LOGGER.h"
#include <RTClib.h>
#include "mediData.h"
#include "setup_RTC.h"
#include <stdio.h>
#include <string.h>



void setup() {

#if defined(ARDUINO_ARCH_SAMD) && (SERIAL_PORT_USBVIRTUAL)
#define Serial SERIAL_PORT_USBVIRTUAL
#endif

	while (!Serial);

	Serial.begin(9600);

	init_RTC();
	init_SD();

}

// Anzahl der Medikamente
const int maxMedi = 6;
// Medikament
MEDI medicament[maxMedi];

// the loop function runs over and over again until power down or reset
void loop() {

	print_Serial(get_Time_Date());

	Serial.println("set_medi");
	set_medi(medicament);

	Serial.println("Log time & medicament");
	SD_logger(get_Time_Date(),medicament);
	delay(10000);

}
