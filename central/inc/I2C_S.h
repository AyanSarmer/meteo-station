#ifndef I2C_S_H_
#define I2C_S_H_

#define F_CPU                   16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "pinout.h"

#define I2C_DELAY_MAX           1
#define MSBit                   0x80     
#define LSBit			        0x01
#define ACK				        0
#define NACK			        1        

#define SCL_HIGH                I2C_DDR &= ~(1 << SCL)
#define SCL_LOW                 I2C_DDR |=  (1 << SCL)
#define SDA_HIGH                I2C_DDR &= ~(1 << SDA)
#define SDA_LOW                 I2C_DDR |=  (1 << SDA)

#define DELAY_VALUE             2
#define DELAY                   _delay_us(DELAY_VALUE)

class I2C_S
{
    public:
        I2C_S();
        void start();
        void restart();
        void stop();
        bool writeByte(unsigned char data);
        unsigned char readByte(bool ack);
};

extern I2C_S I2C;

#endif /* I2C_S_H_ */