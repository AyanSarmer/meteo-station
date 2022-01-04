#ifndef TEXT_H_
#define TEXT_H_

#include "GFX.h"
#include "globals.h"

/* device states */
#define MAIN_MENU                       0
#define TDE_MENU                        1
#define TS_MENU                         2
#define DS_MENU                         3

/* temperature data */
#define TEMPERATURE_Y                   5
#define TEMPERATURE_X_DIF               10
#define TEMPERATURE_SIGN_X              50
#define TEMPERATURE_T_X                 TEMPERATURE_SIGN_X + TEMPERATURE_X_DIF
#define TEMPERATURE_U_X                 TEMPERATURE_T_X + TEMPERATURE_X_DIF
#define TEMPERATURE_DOT_X               TEMPERATURE_U_X + TEMPERATURE_X_DIF - 2
#define TEMPERATURE_F_X                 TEMPERATURE_DOT_X + 5
#define TEMPERATURE_CIRCLE_X            TEMPERATURE_F_X + 4
#define TEMPERATURE_C_X                 TEMPERATURE_CIRCLE_X + TEMPERATURE_X_DIF + 2
#define TEMPERATURE_CLEAR_WIDTH         6
#define TEMPERATURE_CLEAR_HEIGHT        11  
#define SIGN_BITS                       0xf8 
#define MINUS                           0
#define PLUS                            1

/* time data */
#define TIME_Y                          30
#define TIME_X_DIF                      20
#define HOURS_T_X                       35
#define HOURS_U_X                       HOURS_T_X + TIME_X_DIF
#define MINUTES_T_X                     COLON_X + 13
#define MINUTES_U_X                     MINUTES_T_X + TIME_X_DIF
#define COLON_X                         HOURS_U_X + TIME_X_DIF  
#define COLON_Y_DIF                     2
#define COLON_Y                         TIME_Y - COLON_Y_DIF
#define COLON_OFF                       0
#define COLON_ON                        1
#define TIME_CLEAR_WIDTH                15
#define TIME_CLEAR_HEIGHT               26  

/* date data */ 
#define DATE_Y                          75
#define DATE_X_DIF                      10
#define DATE_DATE_T_X                   48 
#define DATE_DATE_U_X                   DATE_DATE_T_X  + DATE_X_DIF
#define DATE_DOT_1_X                    DATE_DATE_U_X + DATE_X_DIF - 2
#define DATE_MONTH_T_X                  DATE_DOT_1_X + 5
#define DATE_MONTH_U_X                  DATE_MONTH_T_X  + DATE_X_DIF
#define DATE_DOT_2_X                    DATE_MONTH_U_X + DATE_X_DIF - 2
#define DATE_YEAR_T_X                   DATE_DOT_2_X + 5
#define DATE_YEAR_U_X                   DATE_YEAR_T_X  + DATE_X_DIF
#define DATE_CLEAR_WIDTH                6
#define DATE_CLEAR_HIGHT                11

/* day data */
#define DAY_Y                           100
#define SUNDAY_X                        55
#define MONDAY_X                        55
#define TUESDAY_X                       52
#define WEDNESDAY_X                     42
#define THURSDAY_X                      50
#define FRIDAY_X                        59
#define SATURDAY_X                      50
#define DAY_CLEAR_X                     WEDNESDAY_X
#define DAY_CLEAR_WIDTH                 80 
#define DAY_CLEAR_HIGHT                 20

/* TDE menu */
#define TDE_Y_DIF                       40
#define TDE_TIME_STRING_X               35
#define TDE_TIME_STRING_Y               15
#define TDE_DATE_STRING_X               34
#define TDE_DATE_STRING_Y               TDE_TIME_STRING_Y + TDE_Y_DIF
#define TDE_EXIT_STRING_X               63
#define TDE_EXIT_STRING_Y               TDE_DATE_STRING_Y + TDE_Y_DIF
#define TDE_FRAME_X                     28
#define TDE_FRAME_WIDTH                 100
#define TDE_FRAME_HIGHT                 23

/* TS menu */
#define TS_TIME_FRAME_Y                 TIME_Y + 6
#define TS_TIME_FRAME_WIDTH             18
#define TS_TIME_FRAME_HIGHT             30
#define TS_SAVE_X                       66
#define TS_SAVE_Y                       90
#define TS_SAVE_FRAME_Y                 TS_SAVE_Y + 2
#define TS_SAVE_FRAME_WIDTH             40
#define TS_SAVE_FRAME_HIGHT             20

/* DS menu */
#define DS_Y_DIF                        50                      
#define DS_DATE_FRAME_Y                 DATE_Y - DS_Y_DIF + 3
#define DS_DATE_FRAME_WIDTH             10
#define DS_DATE_FRAME_HIGHT             15
#define DS_DAY_FRAME_X                  WEDNESDAY_X - 4 
#define DS_DAY_FRAME_Y                  DAY_Y - DS_Y_DIF - 1
#define DS_DAY_FRAME_WIDTH              88
#define DS_DAY_FRAME_HIGHT              24
#define DS_SAVE_X                       66
#define DS_SAVE_Y                       90
#define DS_SAVE_FRAME_Y                 DS_SAVE_Y + 2
#define DS_SAVE_FRAME_WIDTH             40
#define DS_SAVE_FRAME_HIGHT             20

/* time functions */
void drawTime();
void drawHoursTens();
void drawHoursUnits();
void drawMinutesTens();
void drawMinutesUnits();
void drawColon();
void clearColon();
void clearTimeChar(unsigned int num);
/* date functions */
void drawDate();
void drawDateTens();
void drawDateUnits();
void drawMonthTens();
void drawMonthUnits();
void drawYearTens();
void drawYearUnits();
void drawDay();
void clearDay();
void drawDateDots();
void clearDateChar(unsigned int num);
/* temperature functions */
void drawTemperature();
void drawTemperatureTens();
void drawTemperatureUnits();
void drawTemperatureFraction();
void drawTempemperatureSign();
void drawTemperatureSymbols();
void clearTemperatureChar(unsigned int num);
/* time enum */
enum {eHoursTens, eHoursUnits, eMinutesTens, eMinutesUnits};
/* temperature enum */
enum {eTemperatureTens, eTemperatureUnits, eTemperatureFraction, eTemperatureSign};
/* date enum */
enum {eDateTens, eDateUnits, eMonthTens, eMonthUnits, eYearTens, eYearUnits};
enum {eSunday = 1, eMonday, eTuesday, eWednesday, eThursday, eFriday, eSaturday};
/* TDE enum */
enum {eTDEtimeSettings, eTDEdateSettings, eTDEexit};
/* TS enum */
enum {eTShoursTens, eTShoursUnits, eTSminutesTens, eTSminutesUnits, eTSsave};
/* DS enum */
enum {eDSdateTens, eDSdateUnits, eDSmonthTens, eDSmonthUnits, eDSyearTens, eDSyearUnits, eDSday, eDSsave};

extern tFont temperatureFont, dateFont;

#endif /* TEXT_H_ */