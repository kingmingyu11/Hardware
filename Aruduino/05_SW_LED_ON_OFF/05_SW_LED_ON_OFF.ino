const int SW1 = 2;
const int SW2 = 3;
const int LED1 = 10;
const int LED2 = 11;
int flag1 = 0;   // 0:OFF, 1:ON
int flag2 = 0;

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
  int val1 = digitalRead(SW1);
  int val2 = digitalRead(SW2);
  if(val1 == 1){
    if(flag1 == 0){
      digitalWrite(LED1, HIGH);
      flag1 = 1;
    }
    else{
      digitalWrite(LED1, LOW);
      flag1 = 0;
    }
    delay(300);
  }
  if(val2 == 1){
    if(flag2 == 0){
      digitalWrite(LED2, HIGH);
      flag2 = 1;
    }
    else{
      digitalWrite(LED2, LOW);
      flag2 = 0;
    }
    delay(300);
  }
}
