const int pumpPin = 4;
const int diFirePin = 5;

void setup() {
  pinMode(diFirePin, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pump();

  Serial.println(fire());


}

bool fire(){
  if (digitalRead(diFirePin) == HIGH){
    return true;
  }else{
    return false;
  }
}

void pump() {
  if (fire() == HIGH) {
    digitalWrite(pumpPin, HIGH);
  } else {
    digitalWrite(pumpPin, LOW);
  }
}
