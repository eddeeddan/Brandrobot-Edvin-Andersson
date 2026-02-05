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

  startUp();
  
}

void loop() {
  if (fire()) {
    pinPoint();
    pinPoint2();
    pumpOn();
  }
  else {
    scan();
    pumpOff();
  }
}

void startUp() {
  Serial.println("Startar");

  servo1.write(angle1);
  servo2.write(angle2);

  digitalWrite(pumpPin, LOW);

  delay(500);
}

bool fire(){
  Serial.println(analogRead(anFirePin));
  if (digitalRead(diFirePin) == HIGH){
    Serial.println("Eld");
    return true;
  }else{
    return false;
  }
}

void scan() {
  Serial.println("Scannar");
  servo1.write(angle1);
  delay(10);
  if (angle1 >= max1) {
    direction1 = -direction1;
  } else if (angle1 <= min1) {
    direction1 = -direction1;
  }
  angle1 += direction1;
}

void pumpOn() {
  digitalWrite(pumpPin, HIGH);
  Serial.println("Pumpar ");
}

void pumpOff() {
  digitalWrite(pumpPin, LOW);
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

void pinPoint2() {
  int fireValue2 = analogRead(anFirePin);

  angle2 += direction2;
  servo2.write(angle2);


  if (fireValue2 > lastFireValue2) {
    direction2 = -direction2;
  }

  lastFireValue2 = fireValue2;
}