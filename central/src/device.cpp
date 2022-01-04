#include "device.h"

Device device;

ISR(INT0_vect)
{
    device.payloadReceivedFlag = 1;
}

ISR(INT1_vect)
{
    device.colonBlinkFlag = 1;
}

void deviceInit()
{
    device.state = MAIN_MENU;
    /* encoder init */
    encoderInit();
    /* nRF24 init */
    nRF24.begin(PRX);
    /* RTC init */
    ds1307.SQWEon(SQW_1);
    getTime();
    getDate();
    /* display init */
    displayInit();
    /* interrupts init */
    EICRA |= (1 << ISC11) | (1 << ISC01);
    EIMSK |= (1 << INT1) | (1 << INT0);
    sei();  
}

void deviceControl()
{
    if(device.state == MAIN_MENU) 
    {
        if(device.colonBlinkFlag)
        {
            getTime();
            getDate();
            MAINcontrol();
        } 

        if(device.payloadReceivedFlag)
        {
            getTemperature();
            MAINcontrol();
        }

        if(device.encoderButtonFlag == ENCODER_BUTTON_PRESSED_TIME_LONG)
        {
            device.state = TDE_MENU;
            TDEcontrol();
        }
    } 
    else
    {
        getEncoderRotorState(); 
        if((device.encoderRotorFlag != ENCODER_ROTOR_STOPPED) || (device.encoderButtonFlag == ENCODER_BUTTON_PRESSED_TIME_SHORT))
        {
            if(device.state == TDE_MENU)
            {
                TDEcontrol();
            }
            else if(device.state == TS_MENU)
            {
                TScontrol();
            }
            else if(device.state == DS_MENU)
            {
                DScontrol();
            }        
        } 

        if(device.encoderButtonFlag == ENCODER_BUTTON_PRESSED_TIME_LONG)
        {
            device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_NO_PRESSED;
        }    
    } 

    if(menu.TSsaveFlag == TS_SAVE_FLAG_ON)
    {
        menu.TSsaveFlag = TS_SAVE_FLAG_OFF;
        setTime();
    }  

    if(menu.DSsaveFlag == DS_SAVE_FLAG_ON)
    {
        menu.DSsaveFlag = DS_SAVE_FLAG_OFF;
        setDate();
    }  
}

void getTime()
{
    ds1307.getTime();
    menu.hoursTens = (signed int)(ds1307.hours / 10);
    menu.hoursUnits = (signed int)(ds1307.hours - menu.hoursTens * 10);
    menu.minutesTens = (signed int)(ds1307.minutes / 10);
    menu.minutesUnits = (signed int)(ds1307.minutes - menu.minutesTens * 10);
}

void setTime()
{
    ds1307.hours = (unsigned char)(menu.hoursTens * 10 + menu.hoursUnits);
    ds1307.minutes = (unsigned char)(menu.minutesTens * 10 + menu.minutesUnits);
    ds1307.setTime();
}

void getDate()
{
    ds1307.getFullDate();
    menu.day = ds1307.day;
    menu.dateTens = (signed int)(ds1307.date / 10);
    menu.dateUnits = (signed int)(ds1307.date - menu.dateTens * 10);
    menu.monthTens = (signed int)(ds1307.month / 10);
    menu.monthUnits = (signed int)(ds1307.month - menu.monthTens * 10);
    menu.yearTens = (signed int)(ds1307.year / 10);
    menu.yearUnits = (signed int)(ds1307.year - menu.yearTens * 10);
}

void setDate()
{
    ds1307.day = (unsigned char)(menu.day);
    ds1307.date = (unsigned char)(menu.dateTens * 10 + menu.dateUnits);
    ds1307.month = (unsigned char)(menu.monthTens * 10 + menu.monthUnits);
    ds1307.year = (unsigned char)(menu.yearTens * 10 + menu.yearUnits);
    ds1307.setFullDate();
}

void getTemperature()
{
    nRF24.receive();   
    float currentTemperature = (nRF24.payload[1] << 8 | nRF24.payload[0])/16.0;

    if(currentTemperature < 0)
    {
        menu.temperatureSign = MINUS;
        currentTemperature *= -1.0;
    }  
    else
    {
        menu.temperatureSign = PLUS;
    }

    menu.temperatureTens = (signed int)(currentTemperature / 10.0);
    menu.temperatureUnits = (signed int)(currentTemperature - menu.temperatureTens * 10);
    signed int modeByTen = (signed int)(currentTemperature) * 10;
    signed int tempByTen = (signed int)(currentTemperature * 10);
    menu.temperatureFraction = tempByTen - modeByTen;
}