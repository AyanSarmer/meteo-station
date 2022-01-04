#include "encoder.h"

volatile unsigned char encoderTimerCounter;
volatile unsigned char encoderButtonState;
unsigned char encoderRotorTurnCounter;

ISR(TIMER1_OVF_vect)
{
    if(encoderButtonState == ENCODER_BUTTON_IS_PRESSED_BEFORE_BOUNCE)
    {
        encoderButtonState = ENCODER_BUTTON_IS_PRESSED_AFTER_BOUNCE;
        PCIFR |= (1 << ENCODER_BUTTON_PCIF);
        ENCODER_BUTTON_PCMSK |= (1 << ENCODER_BUTTON_PCINT);
        encoderTimerCounter++;
    }
    else if(encoderButtonState == ENCODER_BUTTON_IS_PRESSED_AFTER_BOUNCE)
    {
        encoderTimerCounter++;
    }

    else if(encoderButtonState == ENCODER_BUTTON_IS_RELEASED_BEFORE_BOUNCE)
    {
        encoderButtonState = ENCODER_BUTTON_IS_RELEASED;
        encoderTimerOff();
        if(encoderTimerCounter < ENCODER_BUTTON_TIMER_COUNTER_MAX)
        {
            device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_SHORT;
        }
        else
        {
            device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_LONG;
        }
        encoderTimerCounter = 0;
        PCIFR |= (1 << ENCODER_BUTTON_PCIF);
        ENCODER_BUTTON_PCMSK |= (1 << ENCODER_BUTTON_PCINT);        
    }
}

ISR(ENCODER_BUTTON_PCINT_vector)
{
    if(encoderButtonState == ENCODER_BUTTON_IS_RELEASED)
    {
        encoderButtonState = ENCODER_BUTTON_IS_PRESSED_BEFORE_BOUNCE;
        ENCODER_BUTTON_PCMSK &= ~(1 << ENCODER_BUTTON_PCINT);
        encoderTimerOn();
    }
    else if(encoderButtonState == ENCODER_BUTTON_IS_PRESSED_AFTER_BOUNCE)
    {
        encoderButtonState = ENCODER_BUTTON_IS_RELEASED_BEFORE_BOUNCE;
        ENCODER_BUTTON_PCMSK &= ~(1 << ENCODER_BUTTON_PCINT);
        encoderTimerOff();
        encoderTimerOn();
    }
}

void encoderInit()
{
    /* encoder button init */
    ENCODER_BUTTON_DDR &= ~(1 << ENCODER_BUTTON);
    ENCODER_BUTTON_PORT |= (1 << ENCODER_BUTTON);
    PCICR |= (1 << ENCODER_BUTTON_PCIE);
    ENCODER_BUTTON_PCMSK |= (1 << ENCODER_BUTTON_PCINT); 
    encoderButtonState = ENCODER_BUTTON_IS_RELEASED;
    device.encoderButtonFlag = ENCODER_BUTTON_PRESSED_TIME_NO_PRESSED;    
    /* encoder rotor init */
    ENCODER_ROTOR_DDR &= ~(1 << ENCODER_ROTOR_PIN_MS) | (1 << ENCODER_ROTOR_PIN_LS);
    ENCODER_ROTOR_PORT |= (1 << ENCODER_ROTOR_PIN_MS) | (1 << ENCODER_ROTOR_PIN_LS);
    encoderRotorTurnCounter = ENCODER_ROTOR_TURN_COUNTER_INIT_VALUE;
    getEncoderRotorState();
    /* timer init */
    TIMSK1 |= (1 << TOIE1);
}

void getEncoderRotorState()
{   
    static unsigned char oldEncoderRotorPinValue;
    unsigned char currentEncoderRotorPinValue = (ENCODER_ROTOR_PIN >> ENCODER_ROTOR_PIN_MS) & 0x03;   
    currentEncoderRotorPinValue <<= 1;
    if(currentEncoderRotorPinValue & (1 << 2))
    {
        currentEncoderRotorPinValue |= (1 << 0);
    }
    currentEncoderRotorPinValue & 0x03;

    unsigned char encoderRotorCode = (oldEncoderRotorPinValue << 2) | currentEncoderRotorPinValue;
    oldEncoderRotorPinValue = currentEncoderRotorPinValue;

    if (encoderRotorCode == 1 || encoderRotorCode == 7 || encoderRotorCode == 8 || encoderRotorCode == 14)
    {
        encoderRotorTurnCounter++;
        if(encoderRotorTurnCounter == ENCODER_ROTOR_TURN_COUNTER_MAX_VALUE)
        {
            encoderRotorTurnCounter = ENCODER_ROTOR_TURN_COUNTER_INIT_VALUE;
            device.encoderRotorFlag = ENCODER_ROTOR_TURNED_COUNTER_CLOCK_WISE;
        }
    }
    else if (encoderRotorCode == 2 || encoderRotorCode == 4 || encoderRotorCode == 11 || encoderRotorCode == 13)
    {
        encoderRotorTurnCounter--;
        if(encoderRotorTurnCounter == ENCODER_ROTOR_TURN_COUNTER_MIN_VALUE)
        {
            encoderRotorTurnCounter = ENCODER_ROTOR_TURN_COUNTER_INIT_VALUE;
            device.encoderRotorFlag = ENCODER_ROTOR_TURNED_CLOCK_WISE;
        }
    }
}

void encoderTimerOn()
{
    TCCR1B |= (1 << CS11);
}

void encoderTimerOff()
{
    TCCR1B &= ~(1 << CS11);
    TCNT1 = 0;
}