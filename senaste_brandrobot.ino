#include <Servo.h>

const int anFirePin = A0;
const int diFirePin = 5;
const int pumpPin = 6;
const int servoPin = 7;
Servo myServo;

int angle = 0;
int times = 1;

void setup() {
  pinMode(anFirePin, INPUT);
  pinMode(diFirePin, INPUT);
  pinMode(pumpPin, OUTPUT);
  myServo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(pumpPin, LOW);
  scan();
  Serial.println(analogRead(A0));

  if (digitalRead(diFirePin)==HIGH) {
    if (analogRead(anFirePin) < 40) {
      pump();
    }
  }
}

void pump() {
  if (digitalRead(diFirePin)==HIGH) {
    digitalWrite(pumpPin, HIGH);
    delay(500);
  }
}

void scan() {
  myServo.write(angle);
  delay(25);
  if (angle == 180) {
    times = -1;
  } else if (angle == 0) {
    times = 1;
  }
  angle = angle + (1 * times);
}