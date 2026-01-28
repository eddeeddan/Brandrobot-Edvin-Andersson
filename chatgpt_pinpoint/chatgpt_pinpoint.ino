#include <Servo.h>

Servo servo1;

// Pinnar (ENLIGT DIN KOPPLING)
const int servoPin = 2;
const int flameDigitalPin = 10;
const int flameAnalogPin = A0;

// Servo-variabler
int angle1 = 90;
int direction1 = 1;

// Pinpoint-variabler
int lastFlameValue = 1023;
bool pinpointMode = false;

void setup() {
  servo1.attach(servoPin);
  pinMode(flameDigitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(flameDigitalPin) == HIGH) {
    pinpoint();
  } else {
    scan();
  }
}


void scan() {
  servo1.write(angle1);
  delay(20);
  if (angle1 >= 180) {
    direction1 = -1;
  } else if (angle1 <= 0) {
    direction1 = 1;
  }
  angle1 += direction1;
}

void pinpoint() {
  int currentFlameValue = analogRead(flameAnalogPin);

  // Bättre värde (lägre) → fortsätt samma håll
  if (currentFlameValue < lastFlameValue) {
    angle1 += direction1;
  } 
  // Sämre värde → byt riktning
  else {
    direction1 = -direction1;
    angle1 += direction1;
  }

  angle1 = constrain(angle1, 0, 180);

  servo1.write(angle1);
  delay(25);

  lastFlameValue = currentFlameValue;

  // Debug i Serial Monitor
  Serial.print("PINPOINT | Angle: ");
  Serial.print(angle1);
  Serial.print("  Flame: ");
  Serial.println(currentFlameValue);
}