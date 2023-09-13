const int LED[4] = {11,10,9,6};


void setup() {
  // put your setup code here, to run once:
  // analogWrite(LED_0, 25);
  // analogWrite(LED_1, 100);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i <=255;i++){
    analogWrite(LED[0],i);
    delay(2);
  }
    analogWrite(LED[0],0);

  for(int i = 0; i <=255;i++){
    analogWrite(LED[1],i);
    delay(2);
  }
    analogWrite(LED[1],0);

  for(int i = 0; i <=255;i++){
    analogWrite(LED[2],i);
    delay(2);
  }
    analogWrite(LED[2],0);

  for(int i = 0; i <=255;i++){
    analogWrite(LED[3],i);
    delay(2);
  }
    analogWrite(LED[3],0);

}
