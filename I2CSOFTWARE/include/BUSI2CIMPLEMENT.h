#pragma once
#include "I2CSOFTWARE.H"
#include "Arduino.h"

typedef struct
{
  uint8_t SDApin;
  uint8_t SCLpin;
} S_GPIOPIN;

class TI2CBUS : public TI2CIFACE{
	private:
		const S_GPIOPIN *pins;
	
	protected:
		virtual void I2C_INIT();
		virtual void I2C_SDA_1 ();
		virtual void I2C_SDA_0 ();
		virtual void I2C_SCK_1 ();
		virtual void I2C_SCK_0 ();
		virtual void I2C_SDA_OUT ();
		virtual void I2C_SDA_IN ();
		virtual bool I2C_SDA_READ ();
		virtual bool I2C_SCL_READ ();
		virtual void Hard_Init ();
	
	public:
		TI2CBUS (S_GPIOPIN *p);
		
};

