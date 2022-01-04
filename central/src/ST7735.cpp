#include "ST7735.h"

ST7735 st7735;
unsigned char _width, _height;

void ST7735::command(unsigned char command)
{
    A0_LOW;
    ST7735_CS_LOW;
    SPI.byte(command);
    ST7735_CS_HIGH;
}

void ST7735::data(unsigned char data)
{
    A0_HIGH;
    ST7735_CS_LOW;
    SPI.byte(data);
    ST7735_CS_HIGH;
}

void ST7735::resetSW()
{
    command(ST7735_RESET_SW);
    _delay_ms(120);
}
void ST7735::resetHW()
{
    RESET_LOW;
    _delay_us(10);
    RESET_HIGH;
    _delay_ms(120);
}

void ST7735::begin()
{
    CONTROL_DDR |= (1 << A0) | (1 << RESET) | (1 << ST7735_CS);
    ST7735_CS_HIGH;
    RESET_HIGH;   
    resetHW();
    command(ST7735_COLMOD);
    data(COLMOD_16_BIT);
    command(ST7735_SLPOUT);
    _delay_ms(120);
    command(ST7735_DISPON);
    _delay_ms(120);
    setRotation(4);
    fillScreen(BACKGROUND_COLOR);
}

void ST7735::setRotation(unsigned char rotation)
{
    command(ST7735_MADCTL);
    switch (rotation)
    {
        case 1:
            data(MADCTL_MX | MADCTL_MY | MADCTL_RGB);
            _width  = ST7735_TFTWIDTH;
            _height = ST7735_TFTHEIGHT;
        break;
    
        case 2:
            data(MADCTL_MY | MADCTL_MV | MADCTL_RGB);
            _width  = ST7735_TFTHEIGHT;
            _height = ST7735_TFTWIDTH;
        break;    

        case 3:
            data(MADCTL_RGB);
            _width  = ST7735_TFTWIDTH;
            _height = ST7735_TFTHEIGHT;            
        break;

        case 4:
            data(MADCTL_MV | MADCTL_MX | MADCTL_RGB);
            _width  = ST7735_TFTHEIGHT;
            _height = ST7735_TFTWIDTH;
        break;    

        default:
        break;
    }
}

void ST7735::fillScreen(unsigned int color)
{
    command(ST7735_CASET); 
    data(0x00); data(0x00); 
    data(0x00); data(_width - 1);
    command(ST7735_RASET); 
    data(0x00); data(0x00); 
    data(0x00); data(_height - 1);
    command(ST7735_RAMWR);
  
    for(unsigned int counter = 0; counter < (_width*_height); counter++)     
    {
        data(color >> 8);
        data(color);   
    } 
}

void drawPixel(unsigned int x, unsigned int y, unsigned int color)
{
    st7735.command(ST7735_CASET); 
    st7735.data(x >> 8); st7735.data(x); 
    st7735.data((x + 1) >> 8); st7735.data(x + 1);
  
    st7735.command(ST7735_RASET); 
    st7735.data(y >> 8); st7735.data(y); 
    st7735.data((y + 1) >> 8); st7735.data(y + 1);
      
    st7735.command(ST7735_RAMWR);
    st7735.data(color >> 8);
    st7735.data(color);          
}
