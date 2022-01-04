#include "DS18B20.h"

DS18B20 ds18b20;

float DS18B20::readTemperature()
{
    OneWire.reset();
    OneWire.sendByte(SKIP_ROM);
    OneWire.sendByte(CONVERT_T);
    _delay_ms(CONVERT_DELAY);

    OneWire.reset();
    OneWire.sendByte(SKIP_ROM);
    OneWire.sendByte(READ_SCRATCH_PAD);
    for(int i = 0; i < 2; i++)
    {
      data[i] = OneWire.receiveByte();
    }
    OneWire.reset();
  
    if(data[1] & SIGN_BITS)
    {
	    temperatureSign = MINUS;
    }
    else
    {
	    temperatureSign = PLUS; 
    }

    float temperature = (data[1] << 8 | data[0])/16.0;

    return temperature;
}