#ifndef GLOBALS_H_
#define GLOBALS_H_

/* encoderButtonFlag states */
#define ENCODER_BUTTON_PRESSED_TIME_NO_PRESSED              0
#define ENCODER_BUTTON_PRESSED_TIME_SHORT                   1
#define ENCODER_BUTTON_PRESSED_TIME_LONG                    2 
/* encoderRotorFlag states */
#define ENCODER_ROTOR_STOPPED                               0
#define ENCODER_ROTOR_TURNED_CLOCK_WISE                     1
#define ENCODER_ROTOR_TURNED_COUNTER_CLOCK_WISE             2 

typedef struct Device
{
    unsigned char state                                     :2;  
    unsigned char encoderButtonFlag                         :2; 
    unsigned char encoderRotorFlag                          :2;  
    volatile unsigned char payloadReceivedFlag              :1;
    volatile unsigned char colonBlinkFlag                   :1;   
    unsigned char colonState                                :1;
} Device;
extern struct Device device;

typedef struct Menu
{
    unsigned char state                                     :1;
    signed char item                                        :5;
    unsigned char frameY; 
    unsigned char frameX;
    unsigned char frameWidth;  
    unsigned char frameHight;
    unsigned char oldFrameY;     
    unsigned char oldFrameX; 
    unsigned char oldFrameWidth;  
    unsigned char oldFrameHight;           
    signed int hoursTens                                    :5; 
    signed int hoursUnits                                   :5;  
    signed int minutesTens                                  :5; 
    signed int minutesUnits                                 :5; 
    signed int dateTens                                     :5;  
    signed int dateUnits                                    :5;  
    signed int monthTens                                    :5; 
    signed int monthUnits                                   :5;
    signed int yearTens                                     :5;
    signed int yearUnits                                    :5; 
    signed int day                                          :5;     
    signed int oldHoursTens                                 :5; 
    signed int oldHoursUnits                                :5;  
    signed int oldMinutesTens                               :5; 
    signed int oldMinutesUnits                              :5; 
    signed int oldDateTens                                  :5;  
    signed int oldDateUnits                                 :5;  
    signed int oldMonthTens                                 :5; 
    signed int oldMonthUnits                                :5;
    signed int oldYearTens                                  :5;
    signed int oldYearUnits                                 :5; 
    signed int oldDay                                       :4; 
    signed int temperatureTens                              :5; 
    signed int temperatureUnits                             :5;  
    signed int temperatureFraction                          :5;  
    signed int oldTemperatureTens                           :5; 
    signed int oldTemperatureUnits                          :5;  
    signed int oldTemperatureFraction                       :5;                       
    unsigned char temperatureSign                           :1;
    unsigned char oldTemperatureSign                        :1;   
    unsigned char TSsaveFlag                                :1; 
    unsigned char DSsaveFlag                                :1;
} Menu;
extern struct Menu menu;

#endif /* GLOBALS_H_ */