//"LED_ON" =on
//"LED_ON" = off
unsigned int LED=13;
const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
   unsigned int val = Serial.readBytes(readData,dataBytes);
  Serial.print(val);
  for(int i = 0 ; i<val ; i++){
    Serial.print(readData[i]);
  }

  // switch(readData){
  //    case 'n':
  //    digitalWrite(LED,HIGH); braek;
  //    case 'f':
  //    digitalWrite(LED,LOW); braek;
  //    default : break;
  // }
  }
  
}
