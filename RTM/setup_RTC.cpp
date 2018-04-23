// Setup the Feather M0 pinmodes etc..
// 
// 

#include "setup_RTC.h"
#include <Wire.h>
#include "RTClib.h"



// Uhr-EinsteLLungen
RTC_PCF8523 rtc;
// Wochentage 
char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


void init_RTC() {

	if (!rtc.begin()) {
		Serial.println("Wartet auf RTC");
		while (1);
	}
	if (!rtc.initialized()) {	
		Serial.println("RTC is NOT running!");
		// Setzt Zeit und Datum
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
	}
}

DateTime get_Time_Date() {
	return rtc.now();
}

void print_Serial(DateTime now) {
	Serial.print(now.year(), DEC);
	Serial.print('/');
	Serial.print(now.month(), DEC);
	Serial.print('/');
	Serial.print(now.day(), DEC);
	Serial.print(" (");
	Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
	Serial.print(") ");
	Serial.print(now.hour(), DEC);
	Serial.print(':');
	Serial.print(now.minute(), DEC);
	Serial.print(':');
	Serial.print(now.second(), DEC);
	Serial.println();
}