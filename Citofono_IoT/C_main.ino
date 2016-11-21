

const char* ssid     = "Vodafone-23361200";
const char* password = "224kzalkuxa6hp3";

//Accuracy settings
MQTT mqtt;
void setup() {
  
    pinMode(16, OUTPUT); // PRIMO BOTTONE 
    pinMode(5, OUTPUT); //SECONDO BOTTONE
    pinMode(4, OUTPUT); // TERZO BOTTONE
    digitalWrite(16, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  IPAddress _address = WiFi.localIP();
  Serial.println("WiFi connected \nIP address: "+_address.toString());  

  mqtt = MQTT();

}


void loop() {
 
 
  if (!client.connected()) {
    mqtt.reconnect();
  }
  client.loop();

}




