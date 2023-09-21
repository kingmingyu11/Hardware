#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "DHT.h"
#define DHTPIN D4     
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  

char *topic_t = "Sensors/MyOffice/Indoor/Temp";
char *topic_h = "Sensors/MyOffice/Indoor/Humi";
char* server = "192.168.2.44"; 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WiFiClient wifiClient; 
PubSubClient client(server, 1883, wifiClient);

void setup()   {                
  if( !display.begin(SSD1306_SWITCHCAPVCC, 0x3C) ) { 
    Serial.println(F("OLED(SSD1306) allocation failed"));
    while(1) {}
  }
  display.clearDisplay();
 
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.println("Hello World!");
  display.println("This is a Phi board v1.0”");
  display.display();
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
