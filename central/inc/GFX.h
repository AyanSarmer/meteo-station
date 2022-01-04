#ifndef GFX_H_
#define GFX_H_

#include "ST7735.h"
#include "iconsFonts.h"

#define SUBTRUCT            0x20

class GFX
{
    private:
        void drawByte(unsigned char data);
    public:
        void setCursor(unsigned int x, unsigned int y);
        void setColor(unsigned int color);    
        void drawVerticalLine(unsigned int _hight);
        void drawHorizontalLine(unsigned int _length);
        void drawRectangle(unsigned int _width, unsigned int _hight);
        void fillRectangle(unsigned int _width, unsigned int _hight);
        void drawIcon(tImage structureName);
        void setFont(tFont fontName); 
        void printChar(char myChar);
        void printString(const char *myString);
    public:   
        unsigned int currentX, currentY, currentColor;
};

extern GFX display;
extern tFont currentFont;

#endif /* GFX_H_ */