#include "SPI.h"
#define SS 10
#define MOSI 11
#define MISO 12
#define SCLK 13


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte MasterSend, MasterRecieve;

  MasterSend = 1;
  digitalWrite(SS, LOW);

  MasterRecieve = SPI.transfer(MasterSend);
  Serial.print("MasterRecieve:")
  Serial.println(MasterRecieve)

  delay(1000)
}
