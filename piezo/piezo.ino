int sensorLow = 1023;
int sensorHigh = 0;

void setup()
{
	Serial.begin(9600);

	digitalWrite(13, HIGH);

	//Calibrate the min / max values based on the current environment
	while (millis() < 10000) {

		//This is for the tone pitch
		auto sensorValue = analogRead(A0);
		if (sensorValue < sensorLow) {
			sensorLow = sensorValue;
		}
		if (sensorValue > sensorHigh) {
			sensorHigh = sensorValue;
		}
	}

	digitalWrite(13, LOW);
}

void loop()
{
	auto lightSensorValue1 = analogRead(A0);

	int pitch = map(lightSensorValue1, sensorLow, sensorHigh, 50, 4000);

	tone(8, pitch, 20);

	delay(10);
}
