/*
 Name:		Led_test.ino
 Created:	19.03.2018 15:49:51
 Author:	janni
*/

// the setup function runs once when you press reset or power the board
void setup() {

	pinMode(13, OUTPUT);

}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(13, HIGH);
	delay(100);
	digitalWrite(13, LOW);
	delay(100);
}
