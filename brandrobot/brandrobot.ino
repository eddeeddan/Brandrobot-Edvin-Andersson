/*
* Name: brandrobot
* Author: Edvin Andersson
* Date: 2026-02-06
* Description:
*/

// Including librarys
#include <Servo.h>

// Init pin constants
const int servo1Pin = 2;
const int servo2Pin = 3;
const int pumpPin = 4;
const int diFirePin = 5;
const int anFirePin = A5;

// Construct objects
Servo servo1;
Servo servo2;

//Init global variables for servo movement
int angle1 = 90;
int direction1 = 1;
const int min1 = 0;
const int max1 = 180;
int angle2 = 90;
int direction2 = 1;

// Init global variables for fire detection
int lastFireValue1 = 1023;
int lastFireValue2 = 1023;

void setup() {
  // Init hardware
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  pinMode(pumpPin, OUTPUT);
  pinMode(diFirePin, INPUT);
  pinMode(anFirePin, INPUT);

  // Init communication
  Serial.begin(9600);

  startUp();
}

void loop() {
  if (fire()) {
    pinPoint1();
    pinPoint2();
    pumpOn();
  }
  else {
    scan();
    pumpOff();
  }
}

/*
// This function sets the servos to their start position and turns the pump off
// Parameters: Void
// Returns: Void
*/
void startUp() {
  Serial.println("Startar");

  servo1.write(angle1);
  servo2.write(angle2);

  digitalWrite(pumpPin, LOW);

  delay(1000);
}

/*
// This function checks the digital values from the flame senor to see if there is a fire nearby
// Parameters: Void
// Returns: Usally false, true if fire is detected
*/
bool fire(){
  Serial.println(analogRead(anFirePin));
  if (digitalRead(diFirePin) == HIGH){
    Serial.println("Eld");
    return true;
  }else{
    return false;
  }
}

/*
// This function moves servo1 back and forth to scan the area
// Parameters: Void
// Returns: Void
*/
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

/*
// This function turns the pump on
// Parameters: Void
// Returns: Void
*/
void pumpOn() {
  digitalWrite(pumpPin, HIGH);
  Serial.println("Pumpar ");
}

/*
// This function turns off the pump
// Parameters: Void
// Returns: Void
*/
void pumpOff() {
  digitalWrite(pumpPin, LOW);
}

/*
// This function uses the analog values from the flame sensor to point servo 1 to where the fire is
// Parameters: Void
// Returns: Void
*/
void pinPoint1() {
  int fireValue1 = analogRead(anFirePin);

  angle1 += direction1;
  servo1.write(angle1);

  if (fireValue1 > lastFireValue1) {
    direction1 = -direction1;
  }

  lastFireValue1 = fireValue1;
}

/*
// This function is the same as pinPont 1 but moves servo 2 instead
// Parameters: Void
// Returns: Void
*/
void pinPoint2() {
  int fireValue2 = analogRead(anFirePin);

  angle2 += direction2;
  servo2.write(angle2);


  if (fireValue2 > lastFireValue2) {
    direction2 = -direction2;
  }

  lastFireValue2 = fireValue2;
}