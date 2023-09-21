const int Xin = A0;
const int Yin = A1;
const int KEYin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(KEYin,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
   
  int xVal = analogRead(Xin);
  int yVal = analogRead(Yin);
  int buttonVal = digitalRead(KEYin);
f
  Serial.print("X = ");
  Serial.println(xVal,DEC);
  
  Serial.print("Button is ");
  if(buttonVal == HIGH){
    Serial.println("not pressed");
    else{
      Serial.println("pressed")
    }
  }

}
