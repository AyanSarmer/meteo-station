#include "I2C_S.h"

I2C_S I2C;

I2C_S::I2C_S()
{
    SDA_HIGH;
    SCL_HIGH;
}

void I2C_S::start()
{
    SDA_LOW;
    SCL_LOW;
    DELAY;
}

void I2C_S::restart()
{
    SDA_HIGH;
    SCL_HIGH;
    DELAY;
    SDA_LOW;
    SCL_LOW;
    DELAY;
}

void I2C_S::stop()
{
    SCL_LOW;
    SDA_LOW;
    SCL_HIGH;
    SDA_HIGH;
    DELAY;
}

bool I2C_S::writeByte(unsigned char data)
{
    bool ack;
    
    for(int bitNum = 0; bitNum < 8; bitNum++)
    {
        if(data & MSBit)
        {
            SDA_HIGH;
        }
        else
        {
            SDA_LOW;
        }
        SCL_HIGH;
        DELAY;
        SCL_LOW;
        DELAY;
        data <<= 1;
    }
    SDA_HIGH;
    SCL_HIGH;
    DELAY;
    if(I2C_PIN & (NACK << SDA))
    {
        ack = NACK;
    }
    else
    {
        ack = ACK;
    }
    SCL_LOW;

    return ack;
}

unsigned char I2C_S::readByte(bool ack)
{
    unsigned char data;

    SDA_HIGH;
    for(int bitNum = 0; bitNum < 8; bitNum++)
    {
        data <<= 1;
        SCL_HIGH;
        DELAY;
        if(I2C_PIN & (1 << SDA))
        {
            data |= LSBit;
        }
        SCL_LOW;
        DELAY;  
    } 
    if(ack == ACK)
    {
        SDA_LOW;
    }
    else if(ack == NACK)
    {
        SDA_HIGH;
    }
    SCL_HIGH;
    DELAY;
    SCL_LOW;

    return data;
}
