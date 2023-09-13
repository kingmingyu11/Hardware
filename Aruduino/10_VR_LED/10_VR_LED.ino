const int LED[4]={3,5,6,9};
const int analogPin = A0;
//                                                                                                                                                                                                                                       const int ledPin_4 = 9;

void setup() {
  // put your setup code here, to run once:
for(int i = 0 ; i <4;i++){
  pinMode(LED[i],OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
    int VR_val = analogRead(analogPin);

    for(int i = 0 ; i <4; i++){
      if(VR_val >(1024/5*(1+i)))
    digitalWrite(LED[i],HIGH);

    else digitalWrite(LED[i],LOW);
    }
  
  
}
