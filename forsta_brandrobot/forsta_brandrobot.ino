#include <Servo.h>

const int anFirePin = A0;
const int diFirePin = 5;
const int pumpPin = 4;
const int servo1Pin = 2;
Servo servo1;

int angle = 0;
int times = 1;

void setup() {
  pinMode(anFirePin, INPUT);
  pinMode(diFirePin, INPUT);
  pinMode(pumpPin, OUTPUT);
  servo1.attach(servo1Pin);

  Serial.begin(9600);
}

void loop() {
  if (fire()) {
    pump();
  } else {
    scan();
  }
}

void pump() {
  if (digitalRead(diFirePin)==HIGH) {
    digitalWrite(pumpPin, HIGH);
    delay(500);
  }
}

void scan() {
  servo1.write(angle);
  delay(25);
  if (angle == 180) {
    times = -1;
  } else if (angle == 0) {
    times = 1;
  }
  angle = angle + (1 * times);
}

bool fire() {
  if (digitalRead(diFirePin)==HIGH) {
    return true;
  } else {
    return false;
  }
}