const int diFirePin = 5;

void setup() {
  pinMode(diFirePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (fire()) {
    Serial.println("Eld");
  }
}

bool fire(){
  if (digitalRead(diFirePin) == HIGH){
    return true;
  }else{
    return false;
  }
}
