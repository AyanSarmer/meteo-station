#ifndef DEVICE_H_
#define DEVICE_H_

#include "encoder.h"
#include "DS1307.h"
#include "nRF24.h"
#include "display.h"

void deviceInit();
void deviceControl();
void getTime();
void setTime();
void getDate();
void setDate();
void getTemperature();

#endif /* DEVICE_H_ */