const auto sensorPin = A0;
auto baselineTemp = 0.0;

void setup()
{
	Serial.begin(9600);
	for (auto i = 2; i < 5; i++) {
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	baselineTemp = TempSensorToTemperature(analogRead(sensorPin));
}

void loop()
{
	auto temp = TempSensorToTemperature(analogRead(sensorPin));

	if (temp < baselineTemp) {
		writeToPins(LOW, LOW, LOW);
	}
	else if (temp > baselineTemp + 2) {
		writeToPins(HIGH, HIGH, HIGH);
	}
	else if (temp > baselineTemp + 1) {
		writeToPins(HIGH, HIGH, LOW);
	}
	else {
		writeToPins(HIGH, LOW, LOW);
	}
	delay(1000);
}

float TempSensorToTemperature(int sensorVal) {
	auto voltage = (sensorVal / 1024.0) * 5.0;
	return (voltage - 0.5) * 100;
}

void writeToPins(int green, int yellow, int red) {
	digitalWrite(2, green);
	digitalWrite(3, yellow);
	digitalWrite(4, red);
}