#include "Arduino.h"
#include "BUSI2CIMPLEMENT.h"

TI2CBUS *i2cMaster;
S_GPIOPIN i2cSet = {25, 26};

unsigned char ADR = 0x77;
unsigned char REG = 0x55;
unsigned char DataWrire[3] = {0xAA, 0xFF, 0x55};
unsigned char DataRead[3] = { 0, };

void setup()
{
  Serial.begin(115200);
  i2cMaster = new TI2CBUS(&i2cSet);

  i2cMaster->WriteFrame(ADR, REG, DataWrire, sizeof(DataWrire));
  i2cMaster->ReadFrame(ADR, REG, DataRead, sizeof(DataRead));

}

void loop()
{
  delay(1500);
  i2cMaster->WriteFrame(ADR, REG, DataWrire, sizeof(DataWrire));
  i2cMaster->ReadFrame(ADR, REG, DataRead, sizeof(DataRead));

}