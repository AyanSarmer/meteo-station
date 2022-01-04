#include "SPI.h"

SPI_S SPI;

SPI_S::SPI_S()
{
    SPI_DDR |= (1 << MOSI) | (1 << SCK);      
}

unsigned char SPI_S::byte(unsigned char data)
{
    for(uint8_t counter = 8; counter; counter--)
    {
        if (data & MSBit)
            MOSI_HIGH;
        else
            MOSI_LOW;
        data <<= 1;
        SCK_HIGH; 
        SCK_LOW; 
    }
    return data;    
}