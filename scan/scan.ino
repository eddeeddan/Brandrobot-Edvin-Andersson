#include <Servo.h>

const int servo1Pin = 2;
const int servo2Pin = 3;

Servo servo1;
Servo servo2;

int angle1 = 90;
int direction1 = 1;

void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
}

void loop() {
  scan();
}

void scan() {
  servo1.write(angle1);
  delay(20);
  if (angle1 >= 180) {
    direction1 = -1;
  } else if (angle1 <= 0) {
    direction1 = 1;
  }
  angle1 = angle1 + direction1;
}