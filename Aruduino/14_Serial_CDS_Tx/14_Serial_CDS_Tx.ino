
const int LED = 11;

void setup() {
Serial.begin(115200);
pinMode(LED, OUTPUT);
digitalWrite(LED,LOW);
}

void loop() {
  if(Serial.available()){
    int var = Serial.parseInt();
    Serial.println(var);
    if(var >= 500){
      digitalWrite(LED,HIGH);
    }
  }
  else{
    digitalWrite(LED,LOW);
  }
}