#include "text.h"

tFont temperatureFont = Arial16, dateFont = Arial16;

void drawTime()
{
    if(menu.oldHoursTens != menu.hoursTens)
    {
        menu.oldHoursTens = menu.hoursTens;
        drawHoursTens();
    }

    if(menu.oldHoursUnits != menu.hoursUnits)
    {
        menu.oldHoursUnits = menu.hoursUnits;
        drawHoursUnits();
    }

    if(menu.oldMinutesTens != menu.minutesTens)
    {
        menu.oldMinutesTens = menu.minutesTens;
        drawMinutesTens();
    }

    if(menu.oldMinutesUnits != menu.minutesUnits)
    {
        menu.oldMinutesUnits = menu.minutesUnits;
        drawMinutesUnits();
    }
}

void drawHoursTens()
{
    tImage timeImage[10] = {Arial36_0x30, Arial36_0x31, Arial36_0x32, Arial36_0x33, Arial36_0x34, Arial36_0x35, Arial36_0x36, Arial36_0x37, Arial36_0x38, Arial36_0x39};
    clearTimeChar(eHoursTens);
    display.setColor(TIME_TEXT_COLOR);
    display.setCursor(HOURS_T_X, TIME_Y);
    display.drawIcon(timeImage[menu.hoursTens]);
}

void drawHoursUnits()
{
    tImage timeImage[10] = {Arial36_0x30, Arial36_0x31, Arial36_0x32, Arial36_0x33, Arial36_0x34, Arial36_0x35, Arial36_0x36, Arial36_0x37, Arial36_0x38, Arial36_0x39};
    clearTimeChar(eHoursUnits);
    display.setColor(TIME_TEXT_COLOR);
    display.setCursor(HOURS_U_X, TIME_Y);
    display.drawIcon(timeImage[menu.hoursUnits]);
}

void drawMinutesTens()
{
    tImage timeImage[10] = {Arial36_0x30, Arial36_0x31, Arial36_0x32, Arial36_0x33, Arial36_0x34, Arial36_0x35, Arial36_0x36, Arial36_0x37, Arial36_0x38, Arial36_0x39};
    clearTimeChar(eMinutesTens);
    display.setColor(TIME_TEXT_COLOR);
    display.setCursor(MINUTES_T_X, TIME_Y);
    display.drawIcon(timeImage[menu.minutesTens]); 
}

void drawMinutesUnits()
{
    tImage timeImage[10] = {Arial36_0x30, Arial36_0x31, Arial36_0x32, Arial36_0x33, Arial36_0x34, Arial36_0x35, Arial36_0x36, Arial36_0x37, Arial36_0x38, Arial36_0x39};
    clearTimeChar(eMinutesUnits);
    display.setColor(TIME_TEXT_COLOR);
    display.setCursor(MINUTES_U_X, TIME_Y);
    display.drawIcon(timeImage[menu.minutesUnits]);
}

void drawColon()
{
    display.setColor(TIME_TEXT_COLOR);
    display.setCursor(COLON_X, COLON_Y);
    display.drawIcon(Arial36_0x3a); 
}

void clearColon()
{
    display.setColor(BACKGROUND_COLOR);
    display.setCursor(COLON_X, COLON_Y);
    display.drawIcon(Arial36_0x3a);
}

void clearTimeChar(unsigned int num)
{
    unsigned int x;
    switch (num)
    {
        case eHoursTens:
            x = HOURS_T_X;
        break;

        case eHoursUnits:
            x = HOURS_U_X;
        break;

        case eMinutesTens:
            x = MINUTES_T_X;
        break;
    
        case eMinutesUnits:
            x = MINUTES_U_X;
        break;

        default:
        break;
    }
    display.setColor(BACKGROUND_COLOR);
    display.setCursor(x + 1, TIME_Y + 8);
    display.fillRectangle(TIME_CLEAR_WIDTH, TIME_CLEAR_HEIGHT);
}

void drawDate()
{
    if(menu.oldDay != menu.day)
    {
        menu.oldDay = menu.day;
        drawDay();
    }

    if(menu.oldDateTens != menu.dateTens)
    {
        menu.oldDateTens = menu.dateTens;
        drawDateTens();
    }
    if(menu.oldDateUnits != menu.dateUnits)
    {
        menu.oldDateUnits = menu.dateUnits;
        drawDateUnits();
    }  

    if(menu.oldMonthTens != menu.monthTens)
    {
        menu.oldMonthTens = menu.monthTens;
        drawMonthTens();
    }
    if(menu.oldMonthUnits != menu.monthUnits)
    {
        menu.oldMonthUnits = menu.monthUnits;
        drawMonthUnits();
    }  

    if(menu.oldYearTens != menu.yearTens)
    {
        menu.oldYearTens = menu.yearTens;
        drawYearTens();
    }
    if(menu.oldYearUnits != menu.yearUnits)
    {
        menu.oldYearUnits = menu.yearUnits;
        drawYearUnits();
    }  
}

void drawDateTens()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y - DS_Y_DIF;
    }
    clearDateChar(eDateTens);
    currentFont = dateFont;
    display.setColor(DATE_TEXT_COLOR);
    display.setCursor(DATE_DATE_T_X, y);
    display.printChar(menu.dateTens + 48);
}

void drawDateUnits()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y - DS_Y_DIF;
    }
    clearDateChar(eDateUnits);
    currentFont = dateFont;
    display.setColor(DATE_TEXT_COLOR);
    display.setCursor(DATE_DATE_U_X, y);
    display.printChar(menu.dateUnits + 48);
}

void drawMonthTens()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y - DS_Y_DIF;
    }
    clearDateChar(eMonthTens);
    currentFont = dateFont;
    display.setColor(DATE_TEXT_COLOR);
    display.setCursor(DATE_MONTH_T_X, y);
    display.printChar(menu.monthTens + 48);
}

void drawMonthUnits()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y - DS_Y_DIF;
    }
    clearDateChar(eMonthUnits);
    currentFont = dateFont;
    display.setColor(DATE_TEXT_COLOR);
    display.setCursor(DATE_MONTH_U_X, y);
    display.printChar(menu.monthUnits + 48);
}

void drawYearTens()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y - DS_Y_DIF;
    }
    clearDateChar(eYearTens);
    currentFont = dateFont;
    display.setColor(DATE_TEXT_COLOR);
    display.setCursor(DATE_YEAR_T_X, y);
    display.printChar(menu.yearTens + 48);
}

void drawYearUnits()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y - DS_Y_DIF;
    }
    clearDateChar(eYearUnits);
    currentFont = dateFont;
    display.setColor(DATE_TEXT_COLOR);
    display.setCursor(DATE_YEAR_U_X, y);
    display.printChar(menu.yearUnits + 48);
}

void drawDay()
{
    const char dayName[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    currentFont = dateFont;
    clearDay();
    display.setColor(DAY_TEXT_COLOR);
    unsigned int x, y, dayNum;

    if(device.state == MAIN_MENU)
    {
        y = DAY_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DAY_Y - DS_Y_DIF;
    }

    switch(menu.day)
    {
        case eSunday:
            x = SUNDAY_X;
            dayNum = 0;
        break;

        case eMonday:
            x = MONDAY_X;
            dayNum = 1;
        break;

        case eTuesday:
            x = TUESDAY_X;
            dayNum = 2;
        break;

        case eWednesday:
            x = WEDNESDAY_X;
            dayNum = 3;
        break;

        case eThursday:
            x = THURSDAY_X;
            dayNum = 4;
        break;

        case eFriday:
            x = FRIDAY_X;
            dayNum = 5;
        break;

        case eSaturday:
            x = SATURDAY_X;
            dayNum = 6;
        break;

        default:
        break;
    }
    display.setCursor(x, y); 
    display.printString(dayName[dayNum]);
}

void clearDay()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DAY_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DAY_Y - DS_Y_DIF;
    }

    display.setColor(BACKGROUND_COLOR);
    display.setCursor(DAY_CLEAR_X, y);
    display.fillRectangle(DAY_CLEAR_WIDTH, DAY_CLEAR_HIGHT);    
}

void drawDateDots()
{
    unsigned int y;

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y - DS_Y_DIF;
    }

    display.setColor(DATE_TEXT_COLOR);
    display.setCursor(DATE_DOT_1_X, y);
    display.printChar('.');  
    display.setCursor(DATE_DOT_2_X, y);
    display.printChar('.'); 
}

void clearDateChar(unsigned int num)
{
    unsigned int x, y;
    switch (num)
    {
        case eDateTens:
            x = DATE_DATE_T_X;
        break;

        case eDateUnits:
            x = DATE_DATE_U_X;
        break;

        case eMonthTens:
            x = DATE_MONTH_T_X;
        break;

        case eMonthUnits:
            x = DATE_MONTH_U_X;
        break;

        case eYearTens:
            x = DATE_YEAR_T_X;
        break;

        case eYearUnits:
            x = DATE_YEAR_U_X;
        break;

        default:
        break;
    }

    if(device.state == MAIN_MENU)
    {
        y = DATE_Y + 5;
    }
    else if(device.state == DS_MENU)
    {
        y = DATE_Y + 5 - DS_Y_DIF;
    }

    display.setColor(BACKGROUND_COLOR);
    display.setCursor(x, y);
    display.fillRectangle(DATE_CLEAR_WIDTH , DATE_CLEAR_HIGHT);
}

void drawTemperature()
{
    if(menu.oldTemperatureTens != menu.temperatureTens)
    {
        menu.oldTemperatureTens = menu.temperatureTens;
        drawTemperatureTens();
    }

    if(menu.oldTemperatureUnits != menu.temperatureUnits)
    {
        menu.oldTemperatureUnits = menu.temperatureUnits;
        drawTemperatureUnits();
    }

    if(menu.oldTemperatureFraction != menu.temperatureFraction)
    {
        menu.oldTemperatureFraction = menu.temperatureFraction;
        drawTemperatureFraction();
    }

    if(menu.oldTemperatureSign != menu.temperatureSign)
    {
        menu.oldTemperatureSign = menu.temperatureSign;
        drawTempemperatureSign();
    }
}

void drawTemperatureTens()
{
    clearTemperatureChar(eTemperatureTens);
    currentFont = temperatureFont;
    display.setColor(TEMPERATURE_TEXT_COLOR);
    display.setCursor(TEMPERATURE_T_X, TEMPERATURE_Y);
    display.printChar(menu.temperatureTens + 48);
}

void drawTemperatureUnits()
{
    clearTemperatureChar(eTemperatureUnits);
    currentFont = temperatureFont;
    display.setColor(TEMPERATURE_TEXT_COLOR);
    display.setCursor(TEMPERATURE_U_X, TEMPERATURE_Y);
    display.printChar(menu.temperatureUnits + 48);
}

void drawTemperatureFraction()
{
    clearTemperatureChar(eTemperatureFraction);
    currentFont = temperatureFont;
    display.setColor(TEMPERATURE_TEXT_COLOR);
    display.setCursor(TEMPERATURE_F_X, TEMPERATURE_Y);
    display.printChar(menu.temperatureFraction + 48);
}

void drawTempemperatureSign()
{
    clearTemperatureChar(eTemperatureSign);
    currentFont = temperatureFont;
    display.setColor(TEMPERATURE_TEXT_COLOR);
    display.setCursor(TEMPERATURE_SIGN_X, TEMPERATURE_Y);
    if(menu.temperatureSign == MINUS)
    {
        display.printChar('-');
    }
    else if(menu.temperatureSign == PLUS)
    {
        display.printChar('+');
    }
}

void drawTemperatureSymbols()
{
    currentFont = temperatureFont;
    display.setColor(TEMPERATURE_TEXT_COLOR);
    display.setCursor(TEMPERATURE_DOT_X, TEMPERATURE_Y); 
    display.printChar('.');
    display.setCursor(TEMPERATURE_CIRCLE_X, TEMPERATURE_Y); 
    display.drawIcon(Arial16_circle);    
    display.setCursor(TEMPERATURE_C_X, TEMPERATURE_Y); 
    display.printChar('C');    
}

void clearTemperatureChar(unsigned int num)
{
    unsigned int x;
    switch (num)
    {
        case eTemperatureTens:
            x = TEMPERATURE_T_X;
        break;

        case eTemperatureUnits:
            x = TEMPERATURE_U_X;
        break;

        case eTemperatureFraction:
            x = TEMPERATURE_F_X;
        break;

        case eTemperatureSign:
            x = TEMPERATURE_SIGN_X;
        break;

        default:
        break;
    }
    display.setColor(BACKGROUND_COLOR);
    display.setCursor(x, TEMPERATURE_Y + 5);
    display.fillRectangle(TEMPERATURE_CLEAR_WIDTH, TEMPERATURE_CLEAR_HEIGHT);    
}