#include "DS1307.h"

unsigned char seconds, minutes, hours, day, date, month, year, control;

DS1307 ds1307;

DS1307::DS1307()
{  
    On();
}

unsigned char DS1307::decToBcd(unsigned char val)
{
    return ((val/10*16) + (val%10));
}

unsigned char DS1307::bcdToDec(unsigned char val)
{
    return ((val/16*10) + (val%16));
}

void DS1307::SQWEon(unsigned char frequency)
{
    switch(frequency)
    {
        case SQW_1:
            control = (1 << SQWE);
        break;

        case SQW_4:
            control = (1 << SQWE) | (1 << RS0);
        break;

        case SQW_8:
            control = (1 << SQWE) | (1 << RS1);
        break;

        case SQW_32:
            control = (1 << SQWE) | (1 << RS1) | (1 << RS0);
        break;

        default:
        break;
    }
    
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_CONTROL);
    I2C.writeByte(control);
    I2C.stop();
}

void DS1307::SQWEoff()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_CONTROL);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    control = I2C.readByte(NACK);
    I2C.stop();
    control &= ~(1 << SQWE);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_CONTROL);
    I2C.writeByte(control);
    I2C.stop();
}   

void DS1307::On()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    seconds = I2C.readByte(NACK);
    I2C.stop();
    seconds &= ~(1 << CH);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.writeByte(seconds);
    I2C.stop();
}

void DS1307::Off()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    seconds = I2C.readByte(NACK);
    I2C.stop();
    seconds |= (1 << CH);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.writeByte(seconds);
    I2C.stop();
}

void DS1307::setSeconds()
{
    seconds = decToBcd(seconds);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.writeByte(seconds);
    I2C.stop();
}

void DS1307::setMinutes()
{
    minutes = decToBcd(minutes);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_MINUTES);
    I2C.writeByte(minutes);
    I2C.stop();
}

void DS1307::setHours()
{
    hours = decToBcd(hours);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_HOURS);
    I2C.writeByte(hours);
    I2C.stop();
}

void DS1307::setDay()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_DAY);
    I2C.writeByte(day);
    I2C.stop();
}

void DS1307::setDate()
{
    date = decToBcd(date);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_DATE);
    I2C.writeByte(date);
    I2C.stop();
}

void DS1307::setMonth()
{
    month = decToBcd(month);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_MONTH);
    I2C.writeByte(month);
    I2C.stop();
}

void DS1307::setYear()
{
    year = decToBcd(year);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_YEAR);
    I2C.writeByte(year);
    I2C.stop();
}

void DS1307::setControl()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_CONTROL);
    I2C.writeByte(control);
    I2C.stop();
}

void DS1307::setTime()
{
    seconds = decToBcd(seconds);
    minutes = decToBcd(minutes);
    hours = decToBcd(hours);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.writeByte(seconds);
    I2C.writeByte(minutes);
    I2C.writeByte(hours);
    I2C.stop();
}

void DS1307::setFullDate()
{
    date = decToBcd(date);
    month = decToBcd(month);
    year = decToBcd(year);
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_DAY);
    I2C.writeByte(day);
    I2C.writeByte(date);
    I2C.writeByte(month);
    I2C.writeByte(year);
    I2C.stop();
}

void DS1307::getFullDate()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_DAY);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    day = I2C.readByte(ACK);
    date = I2C.readByte(ACK);
    month = I2C.readByte(ACK);
    year = I2C.readByte(NACK);
    I2C.stop();
    date = bcdToDec(date); 
    month = bcdToDec(month);   
    year = bcdToDec(year);
}

void DS1307::getSeconds()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    seconds = I2C.readByte(NACK);
    I2C.stop();
    seconds = bcdToDec(seconds & 0x7f);
}

void DS1307::getMinutes()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_MINUTES);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    minutes = I2C.readByte(NACK);
    I2C.stop();
    minutes = bcdToDec(minutes);
}

void DS1307::getHours()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_HOURS);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    hours = I2C.readByte(NACK);
    I2C.stop();
    hours = bcdToDec(hours & 0x3f);
}

void DS1307::getDay()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_DAY);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    day = I2C.readByte(NACK);
    I2C.stop();
}

void DS1307::getMonth()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_MONTH);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    month = I2C.readByte(NACK);
    I2C.stop();
    month = bcdToDec(month);
}

void DS1307::getYear()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_YEAR);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    year = I2C.readByte(NACK);
    I2C.stop();
    year = bcdToDec(year);
}

void DS1307::getControl()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_CONTROL);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    control = I2C.readByte(NACK);
    I2C.stop();       
}

void DS1307::getTime()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_SECONDS);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    seconds = I2C.readByte(ACK); 
    minutes = I2C.readByte(ACK); 
    hours = I2C.readByte(NACK); 
    I2C.stop(); 
    seconds = bcdToDec(seconds & 0x7f); 
    minutes = bcdToDec(minutes);
    hours = bcdToDec(hours & 0x3f);
}

void DS1307::getDate()
{
    I2C.start();
    I2C.writeByte(DS1307_ADDRESS_WRITE);
    I2C.writeByte(DS1307_DAY);
    I2C.restart();
    I2C.writeByte(DS1307_ADDRESS_READ);
    day = I2C.readByte(ACK); 
    date = I2C.readByte(ACK); 
    month = I2C.readByte(ACK);  
    year = I2C.readByte(NACK); 
    I2C.stop();  
    date = bcdToDec(date); 
}
