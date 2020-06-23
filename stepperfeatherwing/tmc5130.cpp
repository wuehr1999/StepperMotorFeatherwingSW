#include "tmc5130.h"

TMC5130::TMC5130(int csPin)
{
  this->csPin = csPin;
}

void TMC5130::begin()
{
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, LOW);

  sendSpiDataToTMC(0x01, 0x00000000, csPin, true); //read GSTAT
  sendSpiDataToTMC(0x01, 0x00000000, csPin, true); //read GSTAT
//  sendSpiDataToTMC(0x80, 0x00000000, csPin, true); //write EN_PWM_MODE
  sendSpiDataToTMC(0x80, 0x00000004, csPin, true); //write EN_PWM_MODE
//  sendSpiDataToTMC(0xEC, 0x000101D5, csPin, true); //write CHOPCONF
  sendSpiDataToTMC(0xEC, 0x000100C3, csPin, true); //write CHOPCONF
//  sendSpiDataToTMC(0x90, 0x00070603, csPin, true); //write IHOLD_IRUN: IHOLD=3, IRUN=6, IHOLDDELAY=7 
//  sendSpiDataToTMC(0x90, 0x00061F0A, csPin, true); //write IHOLD_IRUN: IHOLD=10, IRUN=31, IHOLDDELAY=6 
  sendSpiDataToTMC(0x90, 0x0006120A, csPin, true); //write IHOLD_IRUN: IHOLD=10, IRUN=18, IHOLDDELAY=6 
  sendSpiDataToTMC(0x91, 0x0000000A, csPin, true); //write TPOWERDOWN=10
  sendSpiDataToTMC(0x93, 0x000001F4, csPin, true); //write TPWM_THRS=500
//  sendSpiDataToTMC(0xF0, 0x00000000, csPin, true); //write PWMCONF
  sendSpiDataToTMC(0xF0, 0x000401C8, csPin, true); //write PWMCONF
  sendSpiDataToTMC(0xA4, 0x000003E8, csPin, true);  // write acceleration, was 0x03e8=1000
//  sendSpiDataToTMC(0xA4, 0x00000020, csPin, true);  // acceleration, was 0x03e8=1000
  sendSpiDataToTMC(0xA5, 0x000186A0, csPin, true);  //write V1
  sendSpiDataToTMC(0xA6, 0x00001338, csPin, true);  //write acceleration max=5000
//  sendSpiDataToTMC(0xA6, 0x0000C350, csPin, true);  //write acceleration max, was 0xC350=50000
//  sendSpiDataToTMC(0xA6, 0x00000100, csPin, true);  // acceleration max, was 0xC350=50000
//  sendSpiDataToTMC(0xA7, 0x000186A0, csPin, true);  //write VMAX
  sendSpiDataToTMC(0xA8, 0x000002BC, csPin, true);  //write DMAX=700
  sendSpiDataToTMC(0xAA, 0x00000578, csPin, true);  //write D1
  sendSpiDataToTMC(0xAB, 0x0000000A, csPin, true);  //write VSTOP
//  sendSpiDataToTMC(0xA0, 0x00000000, csPin, true);  //write RAMPMODE=0
  sendSpiDataToTMC(0xA0, 0x00000001, csPin, true);  //write RAMPMODE=1
  sendSpiDataToTMC(0xA1, 0x00000000, csPin, true);
  sendSpiDataToTMC(0xAD, 0x00000000, csPin, true);
  sendSpiDataToTMC(0x01, 0x00000000, csPin, true); //read GSTAT
  sendSpiDataToTMC(0x01, 0x00000000, csPin, true); //read GSTAT
  sendSpiDataToTMC(0x6F, 0x00000000, csPin, true); //read DRV_STATUS
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

void TMC5130::speed(unsigned long speed)
{
//  sendSpiDataToTMC(0x21, 0x00000000, csPin, true);
  sendSpiDataToTMC(0xA7, speed, csPin, true);
}
