#include "BUSI2CIMPLEMENT.h"

TI2CBUS::TI2CBUS (S_GPIOPIN *p) : pins (p)
{
	Serial.println("I2C_CONSTR");
	Hard_Init ();
}


void TI2CBUS::Hard_Init ()
{
	Serial.println("I2C_INIT_PIN");
	pinMode(pins->SCLpin, OUTPUT);
	pinMode(pins->SDApin, OUTPUT);
	I2C_INIT ();		

}

void TI2CBUS::I2C_INIT()
{
	Serial.println("I2C_INIT");
	digitalWrite(pins->SCLpin, HIGH);
	digitalWrite(pins->SDApin, HIGH);
}



void TI2CBUS::I2C_SDA_1 ()
{
	// Serial.println("SDA_1");
	digitalWrite(pins->SDApin, HIGH);
}



void TI2CBUS::I2C_SDA_0 ()
{
	// Serial.println("SDA_0");
	digitalWrite(pins->SDApin, LOW);
}



void TI2CBUS::I2C_SCK_1 ()
{
	// Serial.println("SCK_0");
	digitalWrite(pins->SCLpin, HIGH);
}



void TI2CBUS::I2C_SCK_0 ()
{
	// Serial.println("SCK_0");
	digitalWrite(pins->SCLpin, LOW);
}



void TI2CBUS::I2C_SDA_OUT ()
{
	I2C_SDA_1 ();
}



void TI2CBUS::I2C_SDA_IN ()
{
	I2C_SDA_1 ();
}



bool TI2CBUS::I2C_SDA_READ ()
{
	bool rv = false;
	pinMode(pins->SDApin, INPUT);
	if (digitalRead(pins->SDApin)) rv = true;	
	pinMode(pins->SDApin, OUTPUT);		// GPIO_ReadInputDataBit(PORTPIN, SDA_PIN) == Bit_SET)
	return rv;
}



bool TI2CBUS::I2C_SCL_READ ()
{
	bool rv = false;
	pinMode(pins->SCLpin, INPUT);
	if (digitalRead(pins->SCLpin)) rv = true;	
	pinMode(pins->SCLpin, OUTPUT);		// GPIO_ReadInputDataBit(PORTPIN, SDA_PIN) == Bit_SET)
	return rv;
}

	

