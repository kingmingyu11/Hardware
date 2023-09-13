const int LED[4] = { 12, 11, 10, 9 };


void setup() {

  Serial.begin(115200);
  Serial.println(sizeof(LED));
  // put your setup code here, to run once:
  for (int i = 0; i < sizeof(LED) / sizeof(int); i++) {

    pinMode(LED[i], OUTPUT);
  }
}

void loop() {


  for (int j = 0; j< 999; j++) {
    for (int i = 0; i < sizeof(LED) / sizeof(int); i++) {
      digitalWrite(LED[i], HIGH);
      delayMicroseconds(999-j);
      digitalWrite(LED[i], LOW);
      delayMicroseconds(1+j);
      }
  }
    
  

//   for (int i = 0; i < 999; i++) {
//     for (int j = 0; j < (sizeof(LED) / sizeof(int)); j++) {
//       digitalWrite(LED[j], HIGH);
//     }
//     delayMicroseconds(999 - i);
//     for (int j = 0; j < (sizeof(LED) / sizeof(int)); j++) {
//       digitalWrite(LED[j], LOW);
//     }
//     delayMicroseconds(1+i);
//   }
// }

}



//  digitalWrite(LED_4, HIGH);
// delay(600);
// digitalWrite(LED_4, LOW);
// delay(600);





// put your main code here, to run repeatedly:
//  for(int i = 0 ; i <999;i++){
//         digitalWrite(LED,HIGH);
//         delayMicroseconds(999-i); //500ms
//         digitalWrite(LED,LOW);
//         delayMicroseconds(1+i); //500ms
//  }

//    for(int i = 0 ; i <999;i++){
//         digitalWrite(LED,HIGH);
//         delayMicroseconds(1+i); //500ms

//         digitalWrite(LED,LOW);
//         delayMicroseconds(999-i); //500ms
//  }
