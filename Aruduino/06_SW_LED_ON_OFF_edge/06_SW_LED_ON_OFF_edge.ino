const int SW1 = 2;
const int SW2 = 3;
const int LED1 = 10;
const int LED2 = 11;
int flag1 = 0;   // 0:OFF, 1:ON
int flag2 = 0;

int pre_sw0 = 0, cur_sw0=0;
int pre_sw1 = 0, cur_sw1=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cur_sw0 = digitalRead(SW1);
  int cur_sw1 = digitalRead(SW2);

  if((pre_sw0 == 0) && (cur_sw0 == 1)){
    if(flag1 == 0){
      digitalWrite(LED1, HIGH);
      flag1 = 1; 
    }
    else{
      digitalWrite(LED1, LOW);
      flag1 = 0;
    }
    //delay(300);
  }
  if((pre_sw1 == 0) && (cur_sw1 == 1)){
    if(flag2 == 0){
      digitalWrite(LED2, HIGH);
      flag2 = 1; 
    }
    else{
      digitalWrite(LED2, LOW);
      flag2 = 0;
    }
    //delay(300);
  }
  
  pre_sw0=cur_sw0;
  pre_sw1=cur_sw1;

}
