#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(ipbutton,INPUT);           
  pinMode(LED,OUTPUT);  

  Serial.begin(9600);
  Wire.begin(8);

  Wire.onReceive(receieveEvent);
  Wire.onRequest(requestEvent);

  void requestEvent(){
    buttonvalue = digitalRead(buttonpin); 
    if (buttonvalue == HIGH)              
      {
        SlaveSend=1;
      }
    else
      {
       SlaveSend=0;
      }
    Wire.write(SlaveSend);
  }

  void receiveEvent(int howMany){
    SlaveReceieved = Wire.read();
  }  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Slavereceived==1)
   {
   digitalWrite(LED,HIGH); 
   Serial.println("Slave LED ON");
     }
  else
      {
  digitalWrite(LED,LOW);     
  Serial.println("Slave LED OFF");
      }
}
