#ifndef DS1307_H_
#define DS1307_H_

#include "I2C_S.h"

#define DS1307_ADDRESS			0x68
#define DS1307_ADDRESS_WRITE 	(DS1307_ADDRESS << 1)
#define DS1307_ADDRESS_READ 	((DS1307_ADDRESS << 1) + 1)

#define DS1307_SECONDS		    0x00
    #define CH					7
	#define SECONDS_10			4
	#define SECONDS				0
#define DS1307_MINUTES			0x01
	#define MINUTES_10			4
	#define MINUTES				0
#define DS1307_HOURS			0x02
	#define HOURS_10			4
	#define HOURS				0
#define DS1307_DAY              0x03
    #define DAY                 0
#define DS1307_DATE             0x04
    #define DATE_10             4
    #define DATE                0
#define DS1307_MONTH            0x05
    #define MONTH_10            4
    #define MONTH               0
#define DS1307_YEAR             0x06
    #define YEAR_10             4
    #define YEAR                0
#define DS1307_CONTROL          0x07  
    #define OUT                 7
    #define SQWE                4
    #define RS1                 1
    #define RS0                 0   

#define SQW_1                   0
#define SQW_4                   1
#define SQW_8                   2
#define SQW_32                  3

class DS1307
{
    public:
        DS1307();
        void On();
        void Off();
        void setSeconds();
        void setMinutes();
        void setHours();
        void setDay();
        void setDate();
        void setMonth();
        void setYear();
        void setControl();
        void setTime();
        void setFullDate();
        void getFullDate();
        void getSeconds();
        void getMinutes();
        void getHours();
        void getDay();
        void getMonth();
        void getYear();
        void getControl();
        void getTime();
        void getDate();
        void SQWEon(unsigned char frequency);
        void SQWEoff();    

        unsigned char seconds, minutes, hours, day, date, month, year, control; 

    private:
        unsigned char decToBcd(unsigned char val);
        unsigned char bcdToDec(unsigned char val);
};

extern DS1307 ds1307;

#endif /* DS1307_H_ */