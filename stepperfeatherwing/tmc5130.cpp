#include "tmc5130.h"

TMC5130::TMC5130(int csPin)
{
  this->csPin = csPin;
}

void TMC5130::begin()
{
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, LOW);

  sendSpiDataToTMC(0x80, 0x00000000, csPin, true);
  sendSpiDataToTMC(0xEC, 0x000101D5, csPin, true);
  sendSpiDataToTMC(0x90, 0x00070603, csPin, true);
  sendSpiDataToTMC(0x91, 0x0000000A, csPin, true);
  sendSpiDataToTMC(0xF0, 0x00000000, csPin, true);
  sendSpiDataToTMC(0xA4, 0x000003E8, csPin, true);
  sendSpiDataToTMC(0xA5, 0x000186A0, csPin, true);
  sendSpiDataToTMC(0xA6, 0x0000C350, csPin, true);
  sendSpiDataToTMC(0xA7, 0x000186A0, csPin, true);
  sendSpiDataToTMC(0xAA, 0x00000578, csPin, true);
  sendSpiDataToTMC(0xAB, 0x0000000A, csPin, true);
  sendSpiDataToTMC(0xA0, 0x00000000, csPin, true);
  sendSpiDataToTMC(0xA1, 0x00000000, csPin, true);
  sendSpiDataToTMC(0xAD, 0x00000000, csPin, true);
}

void TMC5130::move(unsigned long steps, bool backwards)
{
  if(backwards)
  {
    sendSpiDataToTMC(0x21, steps, csPin, true);
    sendSpiDataToTMC(0xAD, 0x00000000, csPin, true);
  }
  else
  {
    sendSpiDataToTMC(0x21, 0x00000000, csPin, true);
    sendSpiDataToTMC(0xAD, steps, csPin, true);
  }
}
