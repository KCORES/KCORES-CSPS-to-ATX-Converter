/*!
 * @file KCORES_CSPS.cpp
 *
 * This is a library for the CSPS PMBUS
 * Written by AlphaArea
 *
 * GPL license, all text here must be included in any redistribution.
 *
 */

#include "KCORES_CSPS.h"

CSPS::CSPS(byte CSPS_addr)
{
  _CSPS_addr = CSPS_addr;
  _ROM_addr = CSPS_addr - 8;
  _CSPS_READ_CHECKSUM = false;
  Wire.begin();
}

CSPS::CSPS(byte CSPS_addr, byte ROM_addr)
{
  _CSPS_addr = CSPS_addr;
  _ROM_addr = ROM_addr;
  _CSPS_READ_CHECKSUM = false;
  Wire.begin();
}


CSPS::CSPS(byte CSPS_addr, byte ROM_addr, bool ENABLE_CHECKSUM)
{
  _CSPS_addr = CSPS_addr;
  _ROM_addr = ROM_addr;
  _CSPS_READ_CHECKSUM = ENABLE_CHECKSUM;
  Wire.begin();
}

String CSPS::getROM(byte addr, byte len)
{
  String rec;
  for (byte n = 0; n < len; n++)
    rec.concat((char)readROM(addr + n));
  return rec;
}

byte CSPS::readROM(byte dataAddr)
{
  byte rec = 0x00;
  Wire.beginTransmission(_ROM_addr);
  Wire.write(dataAddr);
  Wire.endTransmission();
  Wire.requestFrom(_ROM_addr, 1);
  if (Wire.available())
    rec = Wire.read();
  return rec;
}

// Calclate checksum read from PM BUS
uint8_t checksum(uint32_t data) {
    uint8_t cs = 0;
    cs += ((data & 0xFF0000) >> 16);
    cs += ((data & 0xFF00) >> 8);
    cs += (data & 0xFF);

    cs = ((0xFF - cs) + 1) & 0xFF;
    return cs;
}

uint32_t CSPS::readCSPSword(byte dataAddr)
{
  byte regCS = ((0xFF - (dataAddr + (_CSPS_addr << 1))) + 1) & 0xFF;
  uint32_t rec = 0xFFFF;
  Wire.beginTransmission(_CSPS_addr);
  Wire.write(dataAddr);
  Wire.write(regCS);
  Wire.endTransmission();
  Wire.requestFrom(_CSPS_addr, 3);
  if (Wire.available())
  {
    rec = Wire.read();
    rec |= Wire.read() << 8;
    rec |= Wire.read() << 16;

    if (_CSPS_READ_CHECKSUM) {
      uint8_t cs = checksum(rec);

      if (cs != 0) {
        // Output error to serial
        if (Serial) {
          Serial.printf("CSPS::readCSPSword() Missmatch checksum. addr: 0x%02x, chk: 0x%02x\n", dataAddr, cs);
        }
      }

      // Don't return checksum
      return rec & 0x00FFFF;
    }
    return rec;
  }
  else
    return 0;
}

void CSPS::writeCSPSword(byte dataAddr, unsigned int data)
{
  byte valLSB = lowByte(data),
       valMSB = highByte(data);
  uint8_t cs = (_CSPS_addr << 1) + dataAddr + valLSB + valMSB;
  uint8_t regCS = ((0xFF - cs) + 1) & 0xff;
  //the checksum is the 'secret sauce'
  //writeInts = [reg, valLSB, valMSB, regCS]; //write these 4 bytes to i2c
  Wire.beginTransmission(_CSPS_addr);
  Wire.write(dataAddr);
  Wire.write(valLSB);
  Wire.write(valMSB);
  Wire.write(regCS);
  Wire.endTransmission();
}
