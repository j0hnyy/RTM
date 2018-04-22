// display.h

#ifndef _DISPLAY_h
#define _DISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

/* Call this function to set the display mode x:
	0 = Disp off
	2 = Picture with water
	3 = Picture without water
	4 = Brausetablette
	5 = Zäpfchen

	Optional: Strings 1-3, they will be displayed under the pictures on different lines, max 16 chars per line!
*/
void sendDataToDisp(int x, char* c1, char* c2, char* c3);
void sendDataToDisp(int x, char* c1, char* c2);
void sendDataToDisp(int x, char* c1);
void sendDataToDisp(int x);

/* Call this function to display the clock and set the time*/
void dispClock(void);

#endif

