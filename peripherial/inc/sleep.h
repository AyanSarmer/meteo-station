#ifndef SLEEP_H_
#define SLEEP_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define WDT_COUNTER_MAX             450

void sleepInit();
void sleepOn();

extern volatile unsigned int wdtCounter;

#endif /* SLEEP_H_ */