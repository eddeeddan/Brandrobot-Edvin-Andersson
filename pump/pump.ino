const int pumpPin = 4;


void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  pumpOn();
  delay(1000);
  pumpOff();
  delay(1000);
}

void pumpOn() {
  digitalWrite(pumpPin, HIGH);
}

void pumpOff() {
  digitalWrite(pumpPin, LOW);
}