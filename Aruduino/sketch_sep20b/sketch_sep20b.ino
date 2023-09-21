void setup() {
  pinMode(USER_LED, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nWiFi Connected");
 
  while ( !client.connect(clientId, userId, userPw) ){ 
    Serial.print("*");
    delay(1000);
  }
  Serial.println("\nConnected to broker");
  Serial.print("Subscribing! topic = ");
  Serial.println(topicSub);
  client.subscribe(topicSub);
  void loop() {
  client.loop();

  char buf[20];
  String strLuxValue =  String( lightMeter.readLightLevel() );
  strLuxValue.toCharArray(buf, strLuxValue.length() );
  client.publish(topicPub, buf);
  Serial.println(String(topicPub) + " : " + buf);

  delay(7000);
}