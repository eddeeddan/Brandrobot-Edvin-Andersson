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

int angle2 = 90;
int direction2 = 1;

void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  pinMode(pumpPin, OUTPUT);
  pinMode(diFirePin, INPUT);
  pinMode(anFirePin, INPUT);

  Serial.begin(9600);

  startUp();
}

void loop() {
  if (fire()) {
    Serial.println("Eld");
    pinPoint();
    pumpOn();
  }
  else {
    scan();
    pumpOff();
  }
}

void startUp() {
  servo1.write(90);
  servo2.write(90);

  digitalWrite(pumpPin, LOW);
}

bool fire(){
  if (digitalRead(diFirePin) == HIGH){
    return true;
  }else{
    return false;
  }
}

void scan() {
  servo1.write(angle1);
  delay(10);
  if (angle1 >= 180) {
    direction1 = -1;
  } else if (angle1 <= 0) {
    direction1 = 1;
  }
  angle1 = angle1 + direction1;
}

void pumpOn() {
  digitalWrite(pumpPin, HIGH);
}

void pumpOff() {
  digitalWrite(pumpPin, LOW);
}

void pinPoint() {

}