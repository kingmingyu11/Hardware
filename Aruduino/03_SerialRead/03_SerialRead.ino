const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char userInput = Serial.read();
  Serial.print(userInput);
  Serial.print('\n');

  switch(userInput){
     case 'n':
     digitalWrite(LED,HIGH); braek;
     case 'f':
     digitalWrite(LED,LOW); braek;
     default : break;
  }
  }
  
}
