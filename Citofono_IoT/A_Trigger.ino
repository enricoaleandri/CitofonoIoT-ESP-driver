

class Trigger{
public:

  Trigger(){
   
  }

  void setup(){
  }

  

  static void triggerPIN(int pin){
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW );
    String mex ="Evento su pin ";
    mex+=pin;
    mex+= " eseguito";
    Serial.println(mex);
  }
  static void triggerPrimoBottone(){
    Trigger::triggerPIN(16);
  }
  
  static void triggerSecondoBottone(){
    Trigger::triggerPIN(5);
    
  }
  
  static void triggerTerzoBottone(){
    Trigger::triggerPIN(4);
    
  }
};


