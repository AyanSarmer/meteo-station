#include "sleep.h"

volatile unsigned int wdtCounter;

ISR(WDT_vect)
{
    wdtCounter++;
}

void sleepInit()
{
    MCUCR |= (1 << SE) | (1 << SM1);
    MCUSR &= ~(1 << WDRF);
    WDTCR |= (1 << WDCE) | (1 << WDE);
    WDTCR = (1 << WDIE) | (1 << WDP3) | (1 << WDP0);    
    sei();   
}

void sleepOn()
{
    __asm("sleep");
}