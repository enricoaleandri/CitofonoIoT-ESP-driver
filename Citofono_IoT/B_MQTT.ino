#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
   
WiFiClient espClient;
PubSubClient client(espClient);


  void mqttCallback(char* topic, byte* payload, unsigned int length) {
    Serial.println("Message FROM ["+String(topic)+"]");
    

     String str_payload = "";
     for (int i=0;i<length;i++) {str_payload+= (char)payload[i];}

    Serial.println(str_payload);
    
    //delay(2000);
     //
      // Step 1: Reserve memory space
      //
      StaticJsonBuffer<200> jsonBuffer;
      
      //
      // Step 2: Deserialize the JSON string
      //
      JsonObject& root = jsonBuffer.parseObject(str_payload);
      const int event = root["event"];


     switch(event)
     {
        case 1:{ 
          Trigger::triggerPrimoBottone();
          break;
        }
        case 2:{
          Trigger::triggerSecondoBottone();
          break;
        }
        case 3 : {
          Trigger::triggerTerzoBottone();
          break;
        }
     }

  }
  

class MQTT{
  public:
  
  const char* mqtt_server = "m20.cloudmqtt.com"; // heroku app custom mosquito
  char msg[100];
  char inData[80];
  
  MQTT(){
    client.setServer(mqtt_server, 11181);
    client.setCallback(mqttCallback);
  }
  void setup(){}
  void mqttLog(String message){

        String stringMessage = "{'message':' "+message+"'}";
        char mex[stringMessage.length()]; 
        stringMessage.toCharArray(mex,stringMessage.length());
        client.publish("Enric-IoT-button-server-log", mex);
  }
  void reconnect() {
    // Loop until we're reconnected
    while (!client.connected()) {
      // Attempt to connect
      if (client.connect(mqtt_server,"kjmlqogz","PMHIJ5JGoY2g")) { // credential
        // Once connected, publish an announcement...
        
        Serial.println("MQTT connecter");
        this->mqttLog("Citofono Connesso");
        Serial.println("LOG BACK SENDED connecter");
        // ... and resubscribe
        client.subscribe("Enric-IoT-button-client");
      } else {
        Serial.println("failed, rc=");
        //printText(String(client.state()));
        //printText(" try again in 5 seconds");
        // Wait 5 seconds before retrying
        delay(5000);
      }
    }
  }
};
