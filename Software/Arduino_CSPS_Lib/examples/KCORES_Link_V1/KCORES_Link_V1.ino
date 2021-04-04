/*!
 * Work with KCORES Link V0.0.1 https://github.com/KCORES/kcores-link
 *
 * Written by AlphaArea
 *
 * GPL license, all text here must be included in any redistribution.
 *
 */

#include "KCORES_CSPS.h"

CSPS PowerSupply_1(0x5F, 0x57);

float VoltIn, VoltOut,
    CurrentIn, CurrentOut,
    PowerIn, PowerOut,
    Temp1,
    Temp2,
    FanSpeed;

String OutputString;
uint8_t OutputLen = 0;

void setup()
{
  Serial.begin(115200);
  Wire.setClock(100000);
}

void loop()
{
  VoltIn = PowerSupply_1.getInputVoltage();
  VoltOut = PowerSupply_1.getOutputVoltage();
  CurrentIn = PowerSupply_1.getInputCurrent();
  CurrentOut = PowerSupply_1.getOutputCurrent();
  PowerIn = PowerSupply_1.getInputPower();
  PowerOut = PowerSupply_1.getOutputPower();
  Temp1 = PowerSupply_1.getTemp1();
  Temp2 = PowerSupply_1.getTemp2();
  FanSpeed = PowerSupply_1.getFanRPM();

  Serial.print(" ");
  OutputLen = 0;
  OutputString = String(VoltIn, 1) + ',' + String(CurrentIn, 2) + ',' + String(PowerIn, 1) + ',';
  OutputLen += OutputString.length();
  Serial.print(OutputString);

  OutputString = String(VoltOut, 2) + ',' + String(CurrentOut, 2) + ',' + String(PowerOut, 1) + ',';
  OutputLen += OutputString.length();
  Serial.print(OutputString);

  OutputString = String(Temp1, 1) + ',' + String(Temp2, 1) + ',' + String(FanSpeed, 0) + ',';
  OutputLen += OutputString.length();
  Serial.print(OutputString);
  Serial.print(",,");

  OutputLen = 59 - OutputLen;

  for (; OutputLen > 0; OutputLen--)
    Serial.print(" ");

  Serial.print("\n");

  delay(500);
}

void serialEvent()
{
  PowerSupply_1.setFanRPM(Serial.readStringUntil('\n').toInt());
}
