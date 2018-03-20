// Setup the Feather M0 pinmodes etc..
// 
// 

#include "setup_RTM.h"

#define VS1053_RESET   -1     // VS1053 reset pin (not used!)
#define VS1053_CS       6     // VS1053 chip select pin (output)
#define VS1053_DCS     10     // VS1053 Data/command select pin (output)
#define CARDCS          5     // Card chip select pin
// DREQ should be an Int pin *if possible* (not possible on 32u4)
#define VS1053_DREQ     9     // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(VS1053_RESET, VS1053_CS, VS1053_DCS, VS1053_DREQ, CARDCS);

int set_Audio(void) {
	if (!musicPlayer.begin()) {
		return -1;
	}
	musicPlayer.sineTest(0x44, 500);	    // Make a tone to indicate VS1053 is working
	if (!SD.begin(CARDCS)) {
		return -1;
	}
	// Set volume for left, right channels. lower numbers == louder volume!
	musicPlayer.setVolume(10, 10);
	musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int

	return 0;
}