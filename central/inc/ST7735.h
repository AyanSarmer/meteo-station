#ifndef ST7735_H_
#define ST7735_H_

#define F_CPU                   16000000UL

#include <util/delay.h>
#include "SPI.h"
#include "colors.h"

#define ST7735_TFTWIDTH     128
#define ST7735_TFTHEIGHT    160

#define A0_HIGH			        CONTROL_PORT |= (1 << A0)
#define A0_LOW				      CONTROL_PORT &= ~(1 << A0)

#define RESET_HIGH			    CONTROL_PORT |= (1 << RESET)
#define RESET_LOW			      CONTROL_PORT &= ~(1 << RESET)

#define ST7735_CS_HIGH			CONTROL_PORT |= (1 << ST7735_CS)
#define ST7735_CS_LOW			  CONTROL_PORT &= ~(1 << ST7735_CS)

#define BLACK               0x0000
#define BLUE                0x001F
#define RED                 0xF800
#define GREEN               0x07E0
#define CYAN                0x07FF
#define MAGENTA             0xF81F
#define YELLOW              0xFFE0
#define WHITE               0xFFFF

/* ST7735 commands */
#define ST7735_RESET_SW     0x01
#define ST7735_SLPOUT       0x11
#define ST7735_DISPON       0x29
#define ST7735_COLMOD       0x3A
  #define COLMOD_16_BIT   0x05
#define ST7735_MADCTL       0x36
  #define MADCTL_MY       0x80
  #define MADCTL_MX       0x40
  #define MADCTL_MV       0x20
  #define MADCTL_ML       0x10
  #define MADCTL_RGB      0x00
  #define MADCTL_BGR      0x08
  #define MADCTL_MH       0x04
#define ST7735_CASET        0x2A
#define ST7735_RASET        0x2B
#define ST7735_RAMWR        0x2C

class ST7735
{
    private:
        void resetSW();
        void resetHW();
    public:
        void begin();
        void command(unsigned char command);
        void data(unsigned char data);
        void setRotation(unsigned char rotation);
        void fillScreen(unsigned int color);
};

void drawPixel(unsigned int x, unsigned int y, unsigned int color);

extern ST7735 st7735;
extern unsigned char _width, _height;

#endif /* ST7735_H_ */