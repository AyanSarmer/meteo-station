#include "display.h"

Menu menu;

void displayInit()
{
    st7735.begin();
    menu.oldHoursTens = 0x0f;
    menu.oldHoursUnits = 0x0f;
    menu.oldMinutesTens = 0x0f;
    menu.oldMinutesUnits = 0x0f;
    menu.oldDateTens = 0x0f;
    menu.oldDateUnits = 0x0f;
    menu.oldMonthTens = 0x0f;
    menu.oldMonthUnits = 0x0f;
    menu.oldYearTens = 0x0f;
    menu.oldYearUnits = 0x0f;
    menu.oldTemperatureTens = 0x0f;
    menu.oldTemperatureUnits = 0x0f;
    menu.oldTemperatureFraction = 0x0f;
    menu.oldTemperatureSign = PLUS;
    drawMenu(); 
}

void drawMenu()
{
    if(device.state == MAIN_MENU)
    { 
        st7735.fillScreen(BACKGROUND_COLOR);
        drawHoursTens();
        drawHoursUnits();
        drawMinutesTens();
        drawMinutesUnits(); 
        drawColon();
        drawDateTens();
        drawDateUnits();
        drawMonthTens();
        drawMonthUnits();
        drawYearTens();
        drawYearUnits();
        drawDateDots();   
        drawDay();
        drawTemperatureTens();
        drawTemperatureUnits();
        drawTemperatureFraction();     
        drawTempemperatureSign();
        drawTemperatureSymbols();
    }
    else if(device.state == TDE_MENU)
    {
        st7735.fillScreen(BACKGROUND_COLOR);
        currentFont = dateFont;
        display.setColor(MENU_TEXT_COLOR);
        display.setColor(MENU_TEXT_COLOR);        
        display.setCursor(TDE_TIME_STRING_X, TDE_TIME_STRING_Y);
        display.printString("time settings");
        display.setCursor(TDE_DATE_STRING_X, TDE_DATE_STRING_Y);
        display.printString("date settings");
        display.setCursor(TDE_EXIT_STRING_X, TDE_EXIT_STRING_Y);
        display.printString("exit");       
    } 
    else if(device.state == TS_MENU)
    {
        st7735.fillScreen(BACKGROUND_COLOR);
        drawHoursTens();
        drawHoursUnits();
        drawMinutesTens();
        drawMinutesUnits(); 
        drawColon();
        currentFont = dateFont;
        display.setColor(MENU_TEXT_COLOR);
        display.setCursor(TS_SAVE_X, TS_SAVE_Y);
        display.printString("save");
    }
    else if(device.state == DS_MENU)
    {
        st7735.fillScreen(BACKGROUND_COLOR);
        drawDateTens();
        drawDateUnits();
        drawMonthTens();
        drawMonthUnits(); 
        drawYearTens();
        drawYearUnits();
        drawDay();
        drawDateDots();
        currentFont = dateFont;
        display.setColor(MENU_TEXT_COLOR);
        display.setCursor(TS_SAVE_X, TS_SAVE_Y);
        display.printString("save");
    }
}

void drawFrame()
{
    display.setColor(BACKGROUND_COLOR);
    display.setCursor(menu.oldFrameX, menu.oldFrameY);
    display.drawRectangle(menu.oldFrameWidth, menu.oldFrameHight);
    display.setColor(FRAME_COLOR);
    display.setCursor(menu.frameX, menu.frameY);
    display.drawRectangle(menu.frameWidth, menu.frameHight);
}

void MAINcontrol()
{
    if(device.colonBlinkFlag)
    {
        device.colonBlinkFlag = 0;
        drawTime();
        drawDate();
        drawTemperature();

        if(device.colonState == COLON_OFF)
        {
            device.colonState = COLON_ON;
            drawColon();
        }
        else if(device.colonState == COLON_ON)
        {
            device.colonState = COLON_OFF;
            clearColon();
        }
    } 

    if(device.payloadReceivedFlag)
    {
        device.payloadReceivedFlag = 0;
        drawTemperature();
    }
}

void TDEcontrol()
{
    unsigned char TDEframeY[3] = {TDE_TIME_STRING_Y, TDE_DATE_STRING_Y, TDE_EXIT_STRING_Y};
    
    if(device.encoderButtonFlag == ENCODER_BUTTON_PRESSED_TIME_LONG)
    {
        device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_NO_PRESSED;
        menu.state = FRAME_SCROLL;
        menu.item = eTDEtimeSettings;
        drawMenu();
        menu.frameX = TDE_FRAME_X;
        menu.oldFrameX = TDE_FRAME_X;
        menu.frameY = TDE_TIME_STRING_Y;
        menu.oldFrameY = TDE_DATE_STRING_Y;
        menu.frameWidth = TDE_FRAME_WIDTH;
        menu.oldFrameWidth = TDE_FRAME_WIDTH;
        menu.frameHight = TDE_FRAME_HIGHT;
        menu.oldFrameHight = TDE_FRAME_HIGHT; 
        drawFrame();       
    }
    
    if(device.encoderRotorFlag != ENCODER_ROTOR_STOPPED)
    {
        if(device.encoderRotorFlag == ENCODER_ROTOR_TURNED_COUNTER_CLOCK_WISE)
        {
            device.encoderRotorFlag = ENCODER_ROTOR_STOPPED;
            menu.item--;
            if(menu.item < eTDEtimeSettings)
            {
                menu.item = eTDEexit;
            }
        }
        else if(device.encoderRotorFlag == ENCODER_ROTOR_TURNED_CLOCK_WISE) 
        {
            device.encoderRotorFlag = ENCODER_ROTOR_STOPPED;
            menu.item++;
            if(menu.item > eTDEexit)
            {
                menu.item = eTDEtimeSettings;
            }        
        }
        menu.oldFrameY = menu.frameY;
        menu.oldFrameX = menu.frameX;
        menu.frameY = TDEframeY[menu.item];
        menu.frameX = TDE_FRAME_X;
        drawFrame();       
    }

    if(device.encoderButtonFlag == ENCODER_BUTTON_PRESSED_TIME_SHORT)
    {
        device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_NO_PRESSED;
        if(menu.item == eTDEexit)
        {
            device.state = MAIN_MENU;
            drawMenu();
        }
        else if(menu.item == eTDEtimeSettings)
        {
            device.state = TS_MENU;
            menu.item = eTShoursTens;
            menu.state = FRAME_SCROLL;  
            drawMenu();    
            menu.frameX = HOURS_T_X - 1;
            menu.frameY = TS_TIME_FRAME_Y;
            menu.frameHight = TS_TIME_FRAME_HIGHT;
            menu.frameWidth = TS_TIME_FRAME_WIDTH;
            menu.oldFrameX = HOURS_U_X - 1;
            menu.oldFrameY = TS_TIME_FRAME_Y;
            menu.oldFrameHight = TS_TIME_FRAME_HIGHT;
            menu.oldFrameWidth = TS_TIME_FRAME_WIDTH;  
            drawFrame();         
        }
        else if(menu.item = eTDEdateSettings)
        {
            device.state = DS_MENU;
            menu.item = eDSdateTens;
            menu.state = FRAME_SCROLL;  
            drawMenu();    
            menu.frameX = DATE_DATE_T_X - 2;
            menu.frameY = DS_DATE_FRAME_Y;
            menu.frameHight = DS_DATE_FRAME_HIGHT;
            menu.frameWidth = DS_DATE_FRAME_WIDTH;
            menu.oldFrameX = DATE_DATE_U_X - 2;
            menu.oldFrameY = DS_DATE_FRAME_Y;
            menu.oldFrameHight = DS_DATE_FRAME_HIGHT;
            menu.oldFrameWidth = DS_DATE_FRAME_WIDTH;  
            drawFrame();                     
        }
    }
}

void TScontrol()
{
    if(device.encoderButtonFlag == ENCODER_BUTTON_PRESSED_TIME_SHORT)
    {
        TScontrolButtonPressedShort();    
    }

    if(device.encoderRotorFlag != ENCODER_ROTOR_STOPPED)
    {
        if(device.encoderRotorFlag == ENCODER_ROTOR_TURNED_CLOCK_WISE)
        {
            TScontrolRotorTurnedCW();
        }
        else if(device.encoderRotorFlag == ENCODER_ROTOR_TURNED_COUNTER_CLOCK_WISE)
        {
            TScontrolRotorTurnedCCW();
        }
    }
}

void TScontrolButtonPressedShort()
{
    device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_NO_PRESSED;
    if(menu.item != eTSsave)
    {
        menu.state++;
    }
    else if(menu.item == eTSsave)
    {
        device.state = TDE_MENU;
        menu.TSsaveFlag = TS_SAVE_FLAG_ON;
        menu.state = FRAME_SCROLL;
        menu.item = eTDEtimeSettings;
        drawMenu();
        menu.frameX = TDE_FRAME_X;
        menu.oldFrameX = TDE_FRAME_X;
        menu.frameY = TDE_TIME_STRING_Y;
        menu.oldFrameY = TDE_DATE_STRING_Y;
        menu.frameWidth = TDE_FRAME_WIDTH;
        menu.oldFrameWidth = TDE_FRAME_WIDTH;
        menu.frameHight = TDE_FRAME_HIGHT;
        menu.oldFrameHight = TDE_FRAME_HIGHT; 
        drawFrame();         
    }
}

void TScontrolRotorTurnedCW()
{
    device.encoderRotorFlag = ENCODER_ROTOR_STOPPED;
    if(menu.state == FRAME_SCROLL)
    {
        unsigned char TSframeX[5] = {HOURS_T_X - 1, HOURS_U_X - 1, MINUTES_T_X - 1, MINUTES_U_X - 1, TS_SAVE_X - 4};   
        menu.item++;
        if(menu.item > eTSsave)
        {
            menu.item = eTShoursTens;
        }
        menu.oldFrameX = menu.frameX;
        menu.oldFrameY = menu.frameY;
        menu.oldFrameWidth = menu.frameWidth;
        menu.oldFrameHight = menu.frameHight;
        menu.frameX = TSframeX[menu.item];
        if(menu.item == eTSsave)
        {
            menu.frameY = TS_SAVE_FRAME_Y;
            menu.frameWidth = TS_SAVE_FRAME_WIDTH;
            menu.frameHight = TS_SAVE_FRAME_HIGHT;
        }
        else
        {
            menu.frameY = TS_TIME_FRAME_Y;
            menu.frameWidth = TS_TIME_FRAME_WIDTH;
            menu.frameHight = TS_TIME_FRAME_HIGHT;
        }
        drawFrame(); 
    }
    else if(menu.state == PARAMETER_SETTING)
    {
        if(menu.item == eTShoursTens)
        {
            menu.hoursTens++;
            if(menu.hoursTens > 2)
            {
                menu.hoursTens = 0;
            }
            drawHoursTens();
        }
        else if(menu.item == eTShoursUnits)
        {
            menu.hoursUnits++;
            if(menu.hoursUnits > 9)
            {
                menu.hoursUnits = 0;
            }
            drawHoursUnits();
        }
        else if(menu.item == eTSminutesTens)
        {
            menu.minutesTens++;
            if(menu.minutesTens > 6)
            {
                menu.minutesTens = 0;
            }
            drawMinutesTens();
        }
        else if(menu.item == eTSminutesUnits)
        {
            menu.minutesUnits++;
            if(menu.minutesUnits > 9)
            {
                menu.minutesUnits = 0;
            }
            drawMinutesUnits();
        }
    }
}

void TScontrolRotorTurnedCCW()
{
    device.encoderRotorFlag = ENCODER_ROTOR_STOPPED;
    if(menu.state == FRAME_SCROLL)
    {
        unsigned char TSframeX[5] = {HOURS_T_X - 1, HOURS_U_X - 1, MINUTES_T_X - 1, MINUTES_U_X - 1, TS_SAVE_X - 4}; 
        device.encoderRotorFlag = ENCODER_ROTOR_STOPPED;
        menu.item--;
        if(menu.item < eTShoursTens)
        {
            menu.item = eTSsave;
        } 
        menu.oldFrameX = menu.frameX;
        menu.oldFrameY = menu.frameY;
        menu.oldFrameWidth = menu.frameWidth;
        menu.oldFrameHight = menu.frameHight;
        menu.frameX = TSframeX[menu.item];
        if(menu.item == eTSsave)
        {
            menu.frameY = TS_SAVE_FRAME_Y;
            menu.frameWidth = TS_SAVE_FRAME_WIDTH;
            menu.frameHight = TS_SAVE_FRAME_HIGHT;
        }
        else
        {
            menu.frameY = TS_TIME_FRAME_Y;
            menu.frameWidth = TS_TIME_FRAME_WIDTH;
            menu.frameHight = TS_TIME_FRAME_HIGHT;
        }
        drawFrame();           
    }
    else if(menu.state == PARAMETER_SETTING)
    {
        if(menu.item == eTShoursTens)
        {
            menu.hoursTens--;
            if(menu.hoursTens < 0)
            {
                menu.hoursTens = 2;
            }
            drawHoursTens();                
        }
        else if(menu.item == eTShoursUnits)
        {
            menu.hoursUnits--;
            if(menu.hoursUnits < 0)
            {
                menu.hoursUnits = 9;
            }
            drawHoursUnits();
        }
        else if(menu.item == eTSminutesTens)
        {
            menu.minutesTens--;
            if(menu.minutesTens < 0)
            {
                menu.minutesTens = 6;
            }
            drawMinutesTens();
        }
        else if(menu.item == eTSminutesUnits)
        {
            menu.minutesUnits--;
            if(menu.minutesUnits < 0)
            {
                menu.minutesUnits = 9;
            }
            drawMinutesUnits();
        }
    }
}

void DScontrol()
{
    if(device.encoderButtonFlag == ENCODER_BUTTON_PRESSED_TIME_SHORT)
    {
        DScontrolButtonPressedShort();            
    }

    if(device.encoderRotorFlag != ENCODER_ROTOR_STOPPED)
    {
        if(device.encoderRotorFlag == ENCODER_ROTOR_TURNED_CLOCK_WISE)
        {
            DScontrolRotorTurnedCW();
        }
        else if(device.encoderRotorFlag == ENCODER_ROTOR_TURNED_COUNTER_CLOCK_WISE)
        {
            DScontrolRotorTurnedCCW();
        }
    }
}

void DScontrolButtonPressedShort()
{
    device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_NO_PRESSED;
    if(menu.item != eDSsave)
    {
        menu.state++;
    }
    else if(menu.item == eDSsave)
    {
        device.state = TDE_MENU;
        menu.DSsaveFlag = DS_SAVE_FLAG_ON;
        menu.state = FRAME_SCROLL;
        menu.item = eTDEdateSettings;
        drawMenu();
        menu.frameX = TDE_FRAME_X;
        menu.oldFrameX = TDE_FRAME_X;
        menu.frameY = TDE_DATE_STRING_Y;
        menu.oldFrameY = TDE_EXIT_STRING_Y;
        menu.frameWidth = TDE_FRAME_WIDTH;
        menu.oldFrameWidth = TDE_FRAME_WIDTH;
        menu.frameHight = TDE_FRAME_HIGHT;
        menu.oldFrameHight = TDE_FRAME_HIGHT; 
        drawFrame(); 
    }            
}

void DScontrolRotorTurnedCW()
{
    device.encoderRotorFlag = ENCODER_ROTOR_STOPPED;
    if(menu.state == FRAME_SCROLL)
    {
        unsigned char DSframeX[8] = {DATE_DATE_T_X - 2, DATE_DATE_U_X - 2, DATE_MONTH_T_X - 2, DATE_MONTH_U_X - 2, DATE_YEAR_T_X - 2, DATE_YEAR_U_X - 2, DS_DAY_FRAME_X, DS_SAVE_X - 4};   
        menu.item++;
        if(menu.item > eDSsave)
        {
            menu.item = eDSdateTens;
        }
        menu.oldFrameX = menu.frameX;
        menu.oldFrameY = menu.frameY;
        menu.oldFrameWidth = menu.frameWidth;
        menu.oldFrameHight = menu.frameHight;
        menu.frameX = DSframeX[menu.item];
        if(menu.item == eDSsave)
        {
            menu.frameY = DS_SAVE_FRAME_Y;
            menu.frameWidth = DS_SAVE_FRAME_WIDTH;
            menu.frameHight = DS_SAVE_FRAME_HIGHT;
        }
        else if(menu.item == eDSday)
        {
            menu.frameY = DS_DAY_FRAME_Y;
            menu.frameWidth = DS_DAY_FRAME_WIDTH;
            menu.frameHight = DS_DAY_FRAME_HIGHT;            
        }
        else
        {
            menu.frameY = DS_DATE_FRAME_Y;
            menu.frameWidth = DS_DATE_FRAME_WIDTH;
            menu.frameHight = DS_DATE_FRAME_HIGHT;
        }
        drawFrame(); 
    }
    else if(menu.state == PARAMETER_SETTING)
    {
        if(menu.item == eDSdateTens)
        {
            menu.dateTens++;
            if(menu.dateTens > 3)
            {
                menu.dateTens = 0;
            }
            drawDateTens();
        }
        else if(menu.item == eDSdateUnits)
        {
            menu.dateUnits++;
            if(menu.dateUnits > 9)
            {
                menu.dateUnits = 0;
            }
            drawDateUnits();
        }  
        else if(menu.item == eDSmonthTens)
        {
            menu.monthTens++;
            if(menu.monthTens > 1)
            {
                menu.monthTens = 0;
            }
            drawMonthTens();
        } 
        else if(menu.item == eDSmonthUnits)
        {
            menu.monthUnits++;
            if(menu.monthUnits > 9)
            {
                menu.monthUnits = 0;
            }
            drawMonthUnits();
        }  
        else if(menu.item == eDSyearTens)
        {
            menu.yearTens++;
            if(menu.yearTens > 9)
            {
                menu.yearTens = 0;
            }
            drawYearTens();
        } 
        else if(menu.item == eDSyearUnits)
        {
            menu.yearUnits++;
            if(menu.yearUnits > 9)
            {
                menu.yearUnits = 0;
            }
            drawYearUnits();
        }   
        else if(menu.item == eDSday)
        {
            menu.day++;
            if(menu.day > 7)
            {
                menu.day = 1;
            }
            drawDay();
        }                                                         
    }
}

void DScontrolRotorTurnedCCW()
{
    device.encoderRotorFlag = ENCODER_ROTOR_STOPPED;
    if(menu.state == FRAME_SCROLL)
    {
        unsigned char DSframeX[8] = {DATE_DATE_T_X - 2, DATE_DATE_U_X - 2, DATE_MONTH_T_X - 2, DATE_MONTH_U_X - 2, DATE_YEAR_T_X - 2, DATE_YEAR_U_X - 2, DS_DAY_FRAME_X, DS_SAVE_X - 4};   
        menu.item--;
        if(menu.item < eDSdateTens)
        {
            menu.item = eDSsave;
        }
        menu.oldFrameX = menu.frameX;
        menu.oldFrameY = menu.frameY;
        menu.oldFrameWidth = menu.frameWidth;
        menu.oldFrameHight = menu.frameHight;
        menu.frameX = DSframeX[menu.item];
        if(menu.item == eDSsave)
        {
            menu.frameY = DS_SAVE_FRAME_Y;
            menu.frameWidth = DS_SAVE_FRAME_WIDTH;
            menu.frameHight = DS_SAVE_FRAME_HIGHT;
        }
        else if(menu.item == eDSday)
        {
            menu.frameY = DS_DAY_FRAME_Y;
            menu.frameWidth = DS_DAY_FRAME_WIDTH;
            menu.frameHight = DS_DAY_FRAME_HIGHT;            
        }
        else
        {
            menu.frameY = DS_DATE_FRAME_Y;
            menu.frameWidth = DS_DATE_FRAME_WIDTH;
            menu.frameHight = DS_DATE_FRAME_HIGHT;
        }
        drawFrame(); 
    }
    else if(menu.state == PARAMETER_SETTING)
    {
        if(menu.item == eDSdateTens)
        {
            menu.dateTens--;
            if(menu.dateTens < 0)
            {
                menu.dateTens = 3;
            }
            drawDateTens();
        }
        else if(menu.item == eDSdateUnits)
        {
            menu.dateUnits--;
            if(menu.dateUnits < 0)
            {
                menu.dateUnits = 9;
            }
            drawDateUnits();
        }  
        else if(menu.item == eDSmonthTens)
        {
            menu.monthTens--;
            if(menu.monthTens < 0)
            {
                menu.monthTens = 1;
            }
            drawMonthTens();
        } 
        else if(menu.item == eDSmonthUnits)
        {
            menu.monthUnits--;
            if(menu.monthUnits < 0)
            {
                menu.monthUnits = 9;
            }
            drawMonthUnits();
        }  
        else if(menu.item == eDSyearTens)
        {
            menu.yearTens--;
            if(menu.yearTens < 0)
            {
                menu.yearTens = 9;
            }
            drawYearTens();
        } 
        else if(menu.item == eDSyearUnits)
        {
            menu.yearUnits--;
            if(menu.yearUnits < 0)
            {
                menu.yearUnits = 9;
            }
            drawYearUnits();
        }   
        else if(menu.item == eDSday)
        {
            menu.day--;
            if(menu.day < 1)
            {
                menu.day = 7;
            }
            drawDay();
        }                                                         
    }    
}