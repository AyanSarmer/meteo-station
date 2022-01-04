#ifndef DEVICE_H_
#define DEVICE_H_

#include "nRF24.h"
#include "DS18B20.h" 
#include "sleep.h"

void deviceInit();
void deviceControl();
void transmitTemperature();

#endif /* DEVICE_H_ */