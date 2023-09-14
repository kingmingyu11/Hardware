#include <TimerOne.h>

// 스위치는 인터럽트로 처리
const int LED = 10;
const int SW0 = 2; // 1Hz -> 10Hz -> 100Hz ->1kHz
const int SW1 = 3; // 초기값은 0%, 스위치를 누를 때마다 10%씩 증가

unsigned int state_hz = 0;    // 0:1Hz, 1:10Hz, 2:100Hz, 3:1kHz
unsigned int state_duty = 0;  // 0:0%, 1:10% ~ 10:100%

void SW0_Pressed(){
  if(state_hz == 0){
    Timer1.setPeriod(100000); // 10Hz
    state_hz = 1;
  }
  else if(state_hz == 1){
    Timer1.setPeriod(10000); // 100Hz
    state_hz = 2;
  }
  else if(state_hz == 2){
    Timer1.setPeriod(1000); // 1kHz
    state_hz = 3;
  }
  else if(state_hz == 3){
    Timer1.setPeriod(1000000); // 1Hz
    state_hz = 0;
  }
  Serial.println(state_hz);
}

void SW1_Pressed(){
  if(state_duty == 0){
    Timer1.setPwmDuty(LED, (1024/10)*1);    state_duty = 1;
  }
  else if(state_duty == 1){
    Timer1.setPwmDuty(LED, (1024/10)*2);    state_duty = 2;
  }
  else if(state_duty == 2){
    Timer1.setPwmDuty(LED, (1024/10)*3);    state_duty = 3;
  }
  else if(state_duty == 3){
    Timer1.setPwmDuty(LED, (1024/10)*4);    state_duty = 4;
  }
  else if(state_duty == 4){
    Timer1.setPwmDuty(LED, (1024/10)*5);    state_duty = 5;
  }
  else if(state_duty == 5){
    Timer1.setPwmDuty(LED, (1024/10)*6);    state_duty = 6;
  }
  else if(state_duty == 6){
    Timer1.setPwmDuty(LED, (1024/10)*7);    state_duty = 7;
  }
  else if(state_duty == 7){
    Timer1.setPwmDuty(LED, (1024/10)*8);    state_duty = 8;
  }
  else if(state_duty == 8){
    Timer1.setPwmDuty(LED, (1024/10)*9);    state_duty = 9;
  }
  else if(state_duty == 9){
    Timer1.setPwmDuty(LED, (1024/10)*10);    state_duty = 10;
  }
  else if(state_duty == 10){
    Timer1.setPwmDuty(LED, (1024/10)*0);    state_duty = 0;
  }
  Serial.println(state_duty);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Timer1.initialize(1000000);  // 1Hz
  Timer1.pwm(LED, 0);

  attachInterrupt(digitalPinToInterrupt(SW0), SW0_Pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(SW1), SW1_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}
