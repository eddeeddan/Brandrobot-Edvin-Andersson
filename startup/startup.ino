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

void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  pinMode(pumpPin, OUTPUT);
  pinMode(diFirePin, INPUT);
  pinMode(anFirePin, INPUT);

  startUp();
}

void loop() {
}

void startUp() {
  servo1.write(90);
  servo2.write(90);

  digitalWrite(pumpPin, LOW);
}
