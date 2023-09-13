#define Volt 5.0/1024.0

const int analogPin = A0;
char buf[50]; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(analogPin);
  //Serial.print(analogValue);
  sprintf(buf,"%d, %d V", analogValue, (int)(Volt*analogValue*1000));
  // Serial.print(", ");
  // Serial.print(Volt*analogValue);
  // Serial.println(" V");
  Serial.println(buf);


}

