#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include "pinout.h"

#define MOSI_HIGH				SPI_PORT |= (1 << MOSI)
#define MOSI_LOW				SPI_PORT &= ~(1 << MOSI)
#define SCK_HIGH				SPI_PORT |= (1 << SCK)
#define SCK_LOW				    SPI_PORT &= ~(1 << SCK)

#define MSBit                   0x80
#define LSBit                   0x01

class SPI_S
{
    public:
        SPI_S();
        unsigned char byte(unsigned char data);
};

extern SPI_S SPI;

#endif /* SPI_H_ */