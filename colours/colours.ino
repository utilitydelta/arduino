const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A2;
const int blueSensorPin = A1;

void setup()
{
	Serial.begin(9600);

	pinMode(greenLEDPin, OUTPUT);
	pinMode(redLEDPin, OUTPUT);
	pinMode(blueLEDPin, OUTPUT);
}

void loop()
{
	auto redSensorValue = analogRead(redSensorPin);
	delay(5);
	auto greenSensorValue = analogRead(greenSensorPin);
	delay(5);
	auto blueSensorValue = analogRead(blueSensorPin);
	delay(5);

	analogWrite(redLEDPin, redSensorValue / 4.0);
	analogWrite(greenLEDPin, greenSensorValue / 4.0);
	analogWrite(blueLEDPin, blueSensorValue / 4.0);

}
