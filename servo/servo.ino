#include <servo.h>

Servo myServo;

void setup()
{
	myServo.attach(9);

	Serial.begin(9600);
}

void loop()
{
	auto voltage = analogRead(A0);
	Serial.println(voltage);
	auto angle = map(voltage, 0, 1023, 0, 165);
	Serial.println(angle);
	myServo.write(angle);

	delay(15);
}
