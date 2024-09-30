#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(ipbutton,INPUT);                
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  Wire.requestFrom(8,1);
  byte MasterReceive = Wire.read();
  
  buttonValue = digitalRead(ipbutton);
  if (buttonValue == HIGH){
    MasterSend = 1;
  }
  else{
    MasterSend = 0;
  }

  Wire.beginTransmission(8);
  Wire.write(MasterSend);
  Wire.endTransmission();

  if (MasteReceive == 1){
    digitalWrite(LED, HIGH);
    Serial.println("Master LED On");
  }
  else{
    digitalWrite(LED,LOW);
    Serial.println("Master LED Off");
  }
  


}
