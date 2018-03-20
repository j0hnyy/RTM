// audio.h

#ifndef _AUDIO_h
#define _AUDIO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// function prototypes
int initAudio(void);	// initialize the audio module

void play_Track(char* track);	// play a track from the SD card with the name "track"

void set_volume(int volume);	// set the volume

#endif

