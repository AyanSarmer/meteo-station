#ifndef DS18B20_H_
#define DS18B20_H_

#include "OneWire.h"

#define SKIP_ROM            0xCC
#define READ_SCRATCH_PAD    0xBE
#define CONVERT_T           0x44

#define CONVERT_DELAY       750

#define MINUS               1
#define PLUS                0

#define SIGN_BITS           0xf8

class DS18B20
{
    public:
        float readTemperature();
    public:
        unsigned char data[2];
        unsigned char temperatureSign;
};

extern DS18B20 ds18b20;

#endif /* DS18B20_H_ */