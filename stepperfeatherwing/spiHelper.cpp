#include "spiHelper.h"

void setupSpiForTMC()
{
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setDataMode(SPI_MODE3);
  SPI.begin();

  Serial.begin(9600);
}

void sendSpiDataToTMC(unsigned long address, unsigned long datagram, int csPin, bool sendSerial)
{
  delay(100);
  uint8_t stat;
  unsigned long data;

  digitalWrite(csPin,LOW);
  delayMicroseconds(10);

  stat = SPI.transfer(address);

  data |= SPI.transfer((datagram >> 24) & 0xff);
  data <<= 8;
  data |= SPI.transfer((datagram >> 16) & 0xff);
  data <<= 8;
  data |= SPI.transfer((datagram >> 8) & 0xff);
  data <<= 8;
  data |= SPI.transfer((datagram) & 0xff);
  digitalWrite(csPin,HIGH);

  if(sendSerial)
  {
     Serial.print("Received: ");
     char tmp[16];
     uint16_t LSB = data & 0xffff;
     uint16_t MSB = data >> 16;
     sprintf(tmp, "0x%.2X%.4X%.4X", stat, MSB, LSB);
     Serial.print(tmp);
     Serial.print(" from register: ");
     Serial.println(address,HEX);
  }
}
