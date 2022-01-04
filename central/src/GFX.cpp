#include "GFX.h"

GFX display;
tFont currentFont;

void GFX::setColor(unsigned int color)
{
	currentColor = color;
}

void GFX::setCursor(unsigned int x, unsigned int y)
{
	currentX = x;
	currentY = y;   
}

void GFX::setFont(tFont fontName)
{
	currentFont.chars = fontName.chars;
}

void GFX::drawVerticalLine(unsigned int _hight)
{
	while(_hight--)
	{
		drawPixel(currentX, currentY, currentColor);
		currentY++;
	}    
}

void GFX::drawHorizontalLine(unsigned int _length)
{
	while(_length--)
	{
		drawPixel(currentX, currentY, currentColor);
		currentX++;
	}
}

void GFX::drawRectangle(unsigned int _width, unsigned int _hight)
{
	unsigned int startX = currentX, startY = currentY;
	
	drawVerticalLine(_hight);
	currentY--;
	drawHorizontalLine(_width);

	currentX = startX; currentY = startY;
	
	drawHorizontalLine(_width);
	currentX--;
	drawVerticalLine(_hight);
}

void GFX::fillRectangle(unsigned int _width, unsigned int _hight)
{
    unsigned int startX = currentX;
    unsigned int startY = currentY;
    
	for(unsigned int coordinateY = 0; coordinateY < _hight; coordinateY++)
	{
		drawHorizontalLine(_width);
        currentY++;
        currentX = startX;
	}
}

void GFX::drawByte(unsigned char data)
{ 
   	unsigned char bitNumber = 8;
	   
    while (bitNumber--)
    {
        if(data & MSBit)
        {
            drawPixel(currentX, currentY, currentColor);
        }
        data <<= 1;
        currentY++;        
    }
}

void GFX::drawIcon(tImage structureName)
{
  	unsigned int startX = currentX, startY = currentY;
 	unsigned int imageByteNum = 0;  
	
	unsigned int bytesPerHight = (unsigned int)(structureName.hight / 8); 
  	if ((bytesPerHight * 8) != structureName.hight) bytesPerHight += 1;
  
  	for(unsigned int imageHigt = 0; imageHigt < bytesPerHight; imageHigt++) 
   	{
      	for(unsigned int imageWidth = 0; imageWidth < structureName.width; imageWidth++) 
        {
           	drawByte(pgm_read_byte(&structureName.data[imageByteNum]));
           	currentX++;
           	currentY = startY;
           	imageByteNum++;      
        }
      
      	startY += 8;
      	currentY = startY;  
      	currentX = startX;
   	}      
}

void GFX::printChar(char myChar)
{
	myChar -= SUBTRUCT;
	unsigned int startX = currentX, startY = currentY;
	unsigned int width = currentFont.chars[myChar].image->width;
	unsigned int hight = currentFont.chars[myChar].image->hight;
	unsigned int bytesPerHight = (unsigned int)(hight / 8);
	unsigned int imageByteNum = 0;
	
	if ((bytesPerHight * 8) != hight) bytesPerHight += 1;
	
	for(unsigned int imageHigt = 0; imageHigt < bytesPerHight; imageHigt++)
	{
		for(unsigned int imageWidth = 0; imageWidth < width; imageWidth++)
		{
			drawByte(pgm_read_byte(&currentFont.chars[myChar].image -> data[imageByteNum]));
			currentX++;
			currentY = startY;
			imageByteNum++;
		}
		
		startY += 8;
		currentY = startY;
		currentX = startX;
	}
}

void GFX::printString(const char *myString)
{
	unsigned int startY = currentY;
	
	while(*myString != '\0')
	{
		char myChar = *myString - SUBTRUCT;
		unsigned int width = currentFont.chars[myChar].image->width;
		
		printChar(*myString);
		myString++;
		currentY = startY;
		currentX += width + 1;
	}
}

