#include "SPI.h"
#define SS 10
#define MOSI 11
#define MISO 12
#define SCLK 13

boolean received;
byte slaveSend, slaveReceive;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  
  SPCR |= _BV(SPE);                   
  received = false;
  SPI.attachInterrupt();
}

ISR (SPI_STC_vect){
  slaveReceived = SPDR;         
  received = true;     
}

void loop() {
  // put your main code here, to run repeatedly:

  if (received){
    slaveSend = 0
    SPDR = slaveSend;
  }
  delay(1000)
}
