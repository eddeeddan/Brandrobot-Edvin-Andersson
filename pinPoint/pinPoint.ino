//Should not be used on its own except for debugging

#include <Servo.h>

const int servo1Pin = 2;
const int servo2Pin = 3;
const int pumpPin = 4;
const int diFirePin = 5;
const int anFirePin = A5;

Servo servo1;
Servo servo2;

int angle1 = 90;
int direction1 = 1;
const int min1 = 0;
const int max1 = 180;

int angle2 = 90;
int direction2 = 1;

int lastFireValue1 = 1023;
int lastFireValue2 = 1023;

void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  pinMode(pumpPin, OUTPUT);
  pinMode(diFirePin, INPUT);
  pinMode(anFirePin, INPUT);

  Serial.begin(9600);
}

void loop() {
  pinPoint();
}

void pinPoint() {
  int fireValue1 = analogRead(anFirePin);

  angle1 += direction1;
  servo1.write(angle1);

  if (fireValue1 > lastFireValue1) {
    direction1 = -direction1;
  }

  lastFireValue1 = fireValue1;
}