#ifndef ONEWIRE_H_
#define ONEWIRE_H_

#define F_CPU 1000000UL

#include <util/delay.h>
#include <avr/io.h>

#define DELAY_A                 6
#define DELAY_B                 64
#define DELAY_C                 60
#define DELAY_D                 10
#define DELAY_E                 9
#define DELAY_F                 55
#define DELAY_G                 0
#define DELAY_H                 480
#define DELAY_I                 70
#define DELAY_J                 410

#define MSBit                   0x80
#define LSBit                   0x01

#define OWI_DDR                 DDRB
#define OWI_PIN                 PINB
#define OWI_BUS                 PB3
#define OWI_RELEASE_BUS         OWI_DDR &= ~(1 << OWI_BUS)
#define OWI_PULL_BUS_LOW        OWI_DDR |= (1 << OWI_BUS)

class OWI
{
    public:
        OWI();
        void reset();
        void writeBit0();
        void writeBit1();
        unsigned char readBit();
        void sendByte(unsigned char data);
        unsigned char receiveByte();

};

extern OWI OneWire;

#endif /* ONEWIRE_H_ */