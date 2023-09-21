// 파일 이름 : Phi_GetIPAddress.ino
#include <ESP8266WiFi.h>
#include <PubSubClient.h>



// ----- DHT11 ------------------------
#include "DHT.h"
#define DHTPIN D4     
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "RiatechB2G";
const char* password = "12345678";

const char* userId = "mqtt_phirippa";
const char* userPw = "1234";
const char* clientId = userId;

 char *topic_t = "Sensors/MyOffice/Indoor/Temp";
char *topic_h = "Sensors/MyOffice/Indoor/Humi";
char* server = "192.168.2.44"; 

WiFiClient wifiClient; 
PubSubClient client(server, 1883, wifiClient);

void setup() {
  Serial.begin(9600);
  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  // 해당 공유기에 접속 시도
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Connected");
  
  // 공유기로부터 할당 받은 "(사설)IP 주소" 출력
  Serial.print("Local IP address : ");
  Serial.println(WiFi.localIP());

   Serial.println("Connecting to broker");
  while ( !client.connect(clientId, userId, userPw) ){ 
    Serial.print("*");
    delay(1000);
  }
  Serial.println("\nConnected to broker");
  dht.begin();

}

void loop() {
  char buf[20];
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  String str = String(h);
  str.toCharArray(buf, str.length());
  client.publish(topic_h, buf);
  Serial.println(String(topic_h) + " : " + buf);
  
  str = String(t);
  str.toCharArray(buf, str.length());
  client.publish(topic_t, buf);
  Serial.println(String(topic_t)  + " : " + buf);
  delay(2000);
}