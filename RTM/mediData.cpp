// mediData.cpp
// @ Jannik Giger
// 

#include "mediData.h"
#include <stdlib.h>
#include <stdio.h>
#include <SdFat.h>
#include <string.h>
#include <SPI.h>

const uint8_t chipSelect = 10;
SdFat sd;
ArduinoOutStream cout(Serial);

void set_medi(MEDI *mediToset) {

	if (!sd.begin(chipSelect, SPI_HALF_SPEED)) sd.initErrorHalt();

	const int lineBufferSize = 70;
	char buffer[lineBufferSize];

	ifstream sdin("copyToSD.txt");
	int line_number = 0;

		Serial.println( "set Medi:");
		while (sdin.getline(buffer, lineBufferSize, '\n') || sdin.gcount()) {
			int count = sdin.gcount();
			cout << "\n\nLine: " << line_number << "\n";
			if (sdin.fail()) {
				cout << "Partial long line";
				sdin.clear(sdin.rdstate() & ~ios_base::failbit);
			}
			else if (sdin.eof()) {
				cout << "Partial finel line";
			}
			else {
				count--;
				cout << "Line " << ++line_number;
			}

			cout << " (" << count << " chars): " << buffer << endl;
		
			char tempBuffer[lineBufferSize] = {};
			int copyCount = 0;
			
			while (copyCount < count){
				tempBuffer[copyCount] = buffer[copyCount];
				copyCount++;
			}
			cout << "set mdi\n" << line_number;
			mediToset[line_number-1].name = strtok(tempBuffer, "\t;\n");
			mediToset[line_number - 1].dayTime[0] = atoi(strtok(NULL, "\t;\n"));
			mediToset[line_number - 1].dayTime[1] = atoi(strtok(NULL, "\t;\n"));
			mediToset[line_number - 1].dayTime[2] = atoi(strtok(NULL, "\t;\n"));
			mediToset[line_number - 1].dayTime[3] = atoi(strtok(NULL, "\t;\n"));
			mediToset[line_number - 1].amount = 30;
			int daycount = 0;
			while (daycount < 7) {
				mediToset[line_number - 1].day[daycount] = atoi(strtok(NULL, "\t;\n"));
				daycount++;
			}

			mediToset[line_number - 1].containerNr = line_number;

		}
		cout << "\n Done! \n\n\n";
		/*cout << "Medi: \n";
		for (int i = 0; i < 6; i++) {
			Serial.println('\n');
			Serial.print("Name:	");
			Serial.println(mediToset[i].name);
			Serial.print("amount:	");
			Serial.println(mediToset[i].amount);
			Serial.print("containerNr:	");
			Serial.println(mediToset[i].containerNr);
			Serial.print("day:	");
			Serial.print(mediToset[i].day[0]);
			Serial.print(mediToset[i].day[1]);
			Serial.print(mediToset[i].day[2]);
			Serial.print(mediToset[i].day[3]);
			Serial.print(mediToset[i].day[4]);
			Serial.print(mediToset[i].day[5]);
			Serial.println(mediToset[i].day[6]);
			Serial.print("dayTime:	");
			Serial.print(mediToset[i].dayTime[0]);
			Serial.print(mediToset[i].dayTime[1]);
			Serial.print(mediToset[i].dayTime[2]);
			Serial.println(mediToset[i].dayTime[3]);*/
		}





