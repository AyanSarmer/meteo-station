#include "device.h"

void deviceInit()
{
    nRF24.begin(PTX);  
    sleepInit(); 
    transmitTemperature(); 
    sleepOn();
}

void deviceControl()
{
    if(wdtCounter == WDT_COUNTER_MAX)
    {
        wdtCounter = 0;
        transmitTemperature();
    } 
    sleepOn();
}

void transmitTemperature()
{
    ds18b20.readTemperature();
    nRF24.payload[0] = ds18b20.data[0];   
    nRF24.payload[1] = ds18b20.data[1]; 
    nRF24.powerUp();   
    nRF24.trasmit();
    nRF24.powerDown();
    nRF24.flushStatus();     
}