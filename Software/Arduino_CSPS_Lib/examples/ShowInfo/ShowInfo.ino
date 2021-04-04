/*!
 * Basic Information Display Demo
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

void DataRefresh();
void SerialRefresh();

unsigned long SecCount = 1000;

void setup()
{
  Serial.begin(115200);
  Wire.setClock(10000);
}

void loop()
{
  DataRefresh();
  SerialRefresh();
  delay(1000);
}

void DataRefresh()
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
}

void SerialRefresh()
{
  Serial.write(0x0c);
  Serial.println();
  Serial.println("|-----------------------|");
  Serial.println("| *** KCORES Power! *** |");
  Serial.println("|-----------------------|");
  Serial.println("|\t| In\t| Out\t|");
  Serial.println("|   U\t| " + String(VoltIn, 1) + "\t| " + String(VoltOut, 2) + "\t|");
  Serial.println("|   I\t| " + String(CurrentIn, 1) + "\t| " + String(CurrentOut, 1) + "\t|");
  Serial.println("|   P\t| " + String(PowerIn, 1) + "\t| " + String(PowerOut, 1) + "\t|");
  Serial.println("|-----------------------|");
  Serial.println("| Temp1\t|     " + String(Temp1, 1) + "\t|");
  Serial.println("| Temp2\t|     " + String(Temp2, 1) + "\t|");
  Serial.println("| Fan\t|     " + String(FanSpeed, 0) + "\t|");
  Serial.println("|-----------------------|");
  Serial.println("| AlphaArea        v0.1 |");
  Serial.println("|-----------------------|");
}
