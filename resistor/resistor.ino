int notes[] = { 262, 294, 330,349 };

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	int keyVal = analogRead(A0);
	Serial.println(keyVal);

	int note = -1;
	if (1023 == keyVal) {
		note = 0;
	}
	else if (keyVal >= 990 && keyVal <= 1010) {
		note = 1;
	}
	else if (keyVal >= 505 && keyVal <= 515) {
		note = 2;
	}
	else if (keyVal >= 5 && keyVal <= 100) {
		note = 3;
	}

	if (note >= 0) {
		tone(8, notes[note]);
	}
	else {
		noTone(8);
	}

	delay(50);
}
