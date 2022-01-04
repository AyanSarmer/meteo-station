#include "OneWire.h"

OWI OneWire;

OWI::OWI()
{
    OWI_RELEASE_BUS;
    _delay_us(DELAY_H);
}

void OWI::reset()
{
    OWI_PULL_BUS_LOW;
    _delay_us(DELAY_H);  
    OWI_RELEASE_BUS;
    _delay_us(DELAY_I);  
    _delay_us(DELAY_J);
}

void OWI::writeBit0()
{
    OWI_PULL_BUS_LOW;
    _delay_us(DELAY_C);
    OWI_RELEASE_BUS;
    _delay_us(DELAY_D);  
}

void OWI::writeBit1()
{
    OWI_PULL_BUS_LOW;
    _delay_us(DELAY_A);
    OWI_RELEASE_BUS;
    _delay_us(DELAY_B);    
}

unsigned char OWI::readBit()
{
    uint32_t bitsRead = 0;
    OWI_PULL_BUS_LOW;
    _delay_us(DELAY_A);  
    OWI_RELEASE_BUS;
    _delay_us(DELAY_E);  
    if(OWI_PIN & (1 << OWI_BUS)) 
        bitsRead = 1;  
    _delay_us(DELAY_F);  
    return bitsRead;
}

void OWI::sendByte(unsigned char data)
{
    unsigned char temp, currentBit;

    for (currentBit = 0; currentBit < 8; currentBit++) 
    {
        temp = data & 0x01;
        if (temp) 
        {
            writeBit1();
        } 
        else 
        {
            writeBit0();
        }
        data >>= 1;
    }  
}

unsigned char OWI::receiveByte()
{
    unsigned char data, currentBit;  

    for (currentBit = 0; currentBit < 8; currentBit++) 
    {  
        data >>= 1;
        if (readBit()) 
        {
        data |= MSBit;
        }
    }
    return data;    
}