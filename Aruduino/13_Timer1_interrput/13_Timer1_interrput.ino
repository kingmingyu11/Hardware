#include <TimerOne.h>
  
const int LED = 11;


void timerIsr(void){
 static unsigned long ms = 0;
 ms++;  
}


void setup() {
  // put your setup code here, to run once:
  pinMode(LED , OUTPUT);
  Timer.initialize(500000);
  Timer.attachInterrupt(timerIsr);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
}



