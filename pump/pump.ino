const int pumpPin = 4;


void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(pumpPin, HIGH);
  digitalWrite(13, HIGH);
}
