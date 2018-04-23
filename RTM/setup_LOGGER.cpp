// 
// 
// 

#include "setup_LOGGER.h"
#include <SPI.h>
#include <SD.h>


// set up variables using the SD utility library functions:
Sd2Card card;
SdFile root;
const int chipSelect = 10;

// Log file base name.  Must be six characters or less.
File myFile;

void init_SD() {

	// we'll use the initialization code from the utility libraries
	// since we're just testing if the card is working!
	if (!SD.begin(chipSelect)) {
		Serial.println("initialization failed!");
		while (1);
	}
	Serial.println("initialization done.");

}

void SD_logger(DateTime date_Time, MEDI *medi) {

	// so you have to close this one before opening another.
	myFile = SD.open("LOGGFILE.TXT", FILE_WRITE);

	// if the file opened okay, write to it:
	if (myFile) {
		Serial.print("Log...");
		myFile.print("Log, ");
		myFile.print(date_Time.day(), DEC);
		myFile.print('/');
		myFile.print(date_Time.month(), DEC);
		myFile.print('/');
		myFile.print(date_Time.year(), DEC);
		myFile.print(' ');
		myFile.print(date_Time.hour(), DEC);
		myFile.print(':');
		myFile.print(date_Time.minute(), DEC);
		myFile.println('\n');
		
		for (int i = 0; i < 6; i++) {
			myFile.print("Medikament: \t");
			myFile.println(medi[i].name);
			myFile.print("Anzahl: \t");
			myFile.println(medi[i].amount);
			myFile.print("Container: \t");
			myFile.println(medi[i].containerNr);
			myFile.println('\n');
		}
		myFile.println('\n');
		// close the file:
		myFile.close();
		Serial.println("done.");
	}

	else {
		// if the file didn't open, print an error:
		Serial.println("error opening test.txt");
	}


}






