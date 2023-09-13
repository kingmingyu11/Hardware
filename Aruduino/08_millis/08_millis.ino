#include <PinChangeInterrupt.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterruptPins.h>
#include <PinChangeInterruptSettings.h>
unsigned long t1_prev = 0;
const unsigned long t1_delay = 300;

unsigned long t2_prev = 0;
const unsigned long t2_delay = 500;

const int SW_0 = 2, SW_1 = 3;
const int LED_0 = 10, LED_1 = 11;
int flag_0 = 0, flag_1 = 0;   // 0:OFF, 1:Toggle

void SW0_Pressed(){ // ISR
  // SW_0에 값에 따른 상태값(flag_0) 변경
  flag_0 = (flag_0 == 0)? 1:0;
}

void SW1_Pressed(){
  // SW_1에 값에 따른 상태값(flag_1) 변경
  flag_1 = (flag_1 == 0)? 1:0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW_0, INPUT);
  pinMode(SW_1, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);

  // attachInterrupt(digitalPinToInterrupt(SW_0), SW0_Pressed, RISING);
  // attachInterrupt(digitalPinToInterrupt(SW_1), SW1_Pressed, RISING);
  attachPCINT(digitalPinToPCINT(SW_0), SW0_Pressed, RISING);
  attachPCINT(digitalPinToPCINT(SW_1), SW1_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  // flag_0 값에 따른 동작 구현
  unsigned long t1_now = millis();
    if(t1_now - t1_prev >=t1_delay){
    t1_prev = t1_now;
    if(flag_0 == 0)  {
    digitalWrite(LED_0, LOW);
  }
  else{
    digitalWrite(LED_0, !digitalRead(LED_0)); // Toggle
         
  }


  }
  
  // flag_1 값에 따른 동작 구현
     unsigned long t2_now = millis();
  if(t2_now - t2_prev >=t2_delay){
    t2_prev = t2_now;
    if(flag_1 == 0)  {
    digitalWrite(LED_1, LOW);
  }
  else{
    digitalWrite(LED_1, !digitalRead(LED_1));
        
  }

  }
  
}