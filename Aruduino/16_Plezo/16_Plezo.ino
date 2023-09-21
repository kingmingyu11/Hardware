const int Yin = A1;
const int BUZZER = 10;
const int oct_4[8] = { 262, 294, 330, 349, 393, 440, 494, 523 };
void setup() {
  // put your setup code here, to run once:
  // tone(BUZZER, 262);
  // delay(3000);
  noTone(BUZZER);
}

void loop() {
  // put your main code here, to run repeatedly:
  int yVal = analogRead(Yin);

  Serial.println(yval)
  if (yVal < 100) {
    cnt++;
    if(cnt == 8) cnt =0;
    tone(BUZZER, oct_4[cnt]);
    delay(300);
  }
  else if (yVal>400&yval<600){
    noTone(BUZZER);
  }
  else if(yVal>900){
    cnt --;
    if(cnt ==-1) cnt = 7;
    tone(BUZZER, oct_4[cnt]);
    delay(300);
  }
}
