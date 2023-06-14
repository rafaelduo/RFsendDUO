#include "RFsendDUO.h"
#include "Arduino.h"

//VARs Global
int i = 0;
int x = 1;


RFsendDUO::RFsendDUO(uint16_t enable_tx, uint16_t data_tx) : enable_tx_pin(enable_tx), data_tx_pin(data_tx){
	
}

/// Enable the pin for output.
void RFsendDUO::begin() {
#ifndef UNIT_TEST
  pinMode(enable_tx_pin, OUTPUT);
  pinMode(data_tx_pin, OUTPUT);
#endif
}



void RFsendDUO::send(const uint16_t buf[], const uint16_t len)
{
	digitalWrite(enable_tx_pin, HIGH);
	
	Serial.print("Send_RF: ");
    for (i = 0; i < len; i = i + 2) {
      digitalWrite(data_tx_pin, LOW);
      delayMicroseconds(buf[i]);
	  Serial.print(buf[i]);
	  Serial.print(";");

      digitalWrite(data_tx_pin, HIGH);
      delayMicroseconds(buf[x]);
	  Serial.print(buf[x]);
	  Serial.print(";");
      x = x + 2;
    }
	
    digitalWrite(data_tx_pin, LOW);
    digitalWrite(enable_tx_pin, LOW);
	
    x = 1;
    i = 0;
}