int switchState = LOW;

void setup()
{
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(2, INPUT);
}

void loop()
{
	switchState = digitalRead(2);

	if (switchState == LOW) {
		ready();
	}
	else {
		launch();
	}
}

void ready() {
	writeToPins(HIGH, LOW, LOW);
}

void launch() {
	writeToPins(LOW, HIGH, LOW);

	delay(1000);

	writeToPins(LOW, HIGH, HIGH);

	delay(1000);

	writeToPins(HIGH, HIGH, HIGH);

	delay(1000);
}

void writeToPins(int green1, int red1, int red2) {
	digitalWrite(3, green1);
	digitalWrite(5, red1);
	digitalWrite(4, red2);
}