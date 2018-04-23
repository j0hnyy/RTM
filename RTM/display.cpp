// display.cpp
// Author: Jonas Frei
// includes all functions related to communicate with the Arduino uno and display pictures and text

#include "display.h"
#include <Wire.h>
#include <RTClib.h>


void sendDataToDisp(int x, char* c1, char* c2, char* c3) {
	Wire.beginTransmission(8);	// transmit to device #8
	Wire.write(x);              // sends one byte
	Wire.write(c1);				// send line 1
	Wire.write(";");			// send delimiter
	Wire.write(c2);				// send line 2 
	Wire.write(";");			// send delimiter
	Wire.write(c3);				// send line 3
	Wire.endTransmission();		// stop transmitting
}

void sendDataToDisp(int x, char* c1, char* c2) {
	Wire.beginTransmission(8);	// transmit to device #8
	Wire.write(x);              // sends one byte
	Wire.write(c1);				// send line 1
	Wire.write(";");			// send delimiter
	Wire.write(c2);				// send line 2
	Wire.write("; ");			// send delimiter
	Wire.endTransmission();		// stop transmitting
}

void sendDataToDisp(int x, char* c1) {
	Wire.beginTransmission(8);	// transmit to device #8
	Wire.write(x);              // sends one byte
	Wire.write(c1);				// send line 1
	Wire.write("; ");			// send delimiter
	Wire.write("; ");			// send delimiter
	Wire.endTransmission();		// stop transmitting
}

void sendDataToDisp(int x) {
	Wire.beginTransmission(8);	// transmit to device #8
	Wire.write(x);              // sends one byte
	Wire.endTransmission();		// stop transmitting
}

void dispClock(void) {
	Wire.beginTransmission(8);	// transmit to device #8
	Wire.write(1);				// send one byte
	Wire.write(hour());         // send current time
	Wire.write(minute());		// send current time
	Wire.write(second());		// send current time
	Wire.endTransmission();		// stop transmitting
}