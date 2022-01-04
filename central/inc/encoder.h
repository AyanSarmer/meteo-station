#ifndef ENCODER_H_
#define ENCODER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "globals.h"
#include "pinout.h"

/* encoder button data */
#define ENCODER_BUTTON_IS_RELEASED                          1
#define ENCODER_BUTTON_IS_PRESSED_BEFORE_BOUNCE             2
#define ENCODER_BUTTON_IS_PRESSED_AFTER_BOUNCE              3
#define ENCODER_BUTTON_IS_RELEASED_BEFORE_BOUNCE            4  
/* timer data */
#define ENCODER_BUTTON_TIMER_COUNTER_MAX                    30              
/* encoder rotor data */
#define ENCODER_ROTOR_TURN_COUNTER_DIF  				    4
#define ENCODER_ROTOR_TURN_COUNTER_INIT_VALUE			    7
#define ENCODER_ROTOR_TURN_COUNTER_MAX_VALUE			    ENCODER_ROTOR_TURN_COUNTER_INIT_VALUE + ENCODER_ROTOR_TURN_COUNTER_DIF
#define ENCODER_ROTOR_TURN_COUNTER_MIN_VALUE			    ENCODER_ROTOR_TURN_COUNTER_INIT_VALUE - ENCODER_ROTOR_TURN_COUNTER_DIF 

void encoderInit(); 
void getEncoderRotorState();
void encoderTimerOn();
void encoderTimerOff(); 

extern volatile unsigned char encoderTimerCounter;
extern volatile unsigned char encoderButtonState;
extern unsigned char encoderRotorTurnCounter;

#endif /* ENCODER_H_ */