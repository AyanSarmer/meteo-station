#ifndef PINOUT_H_
#define PINOUT_H_

/* SPI pinout */
#define SPI_DDR					            DDRB
#define SPI_PORT				            PORTB
#define SPI_PIN                             PINB
#define MOSI					            PB1
#define MISO					            PB2
#define SCK						            PB3
/* nRF24 pinout */
#define nRF24_DDR                           DDRB
#define nRF24_PORT                          PORTB
#define CS_nRF24			                PB0
#define CE  			                    PB4
/* ST7735 pinout */
#define CONTROL_DDR                         DDRC              
#define CONTROL_PORT                        PORTC
#define A0                                  PC5
#define RESET                               PC4
#define ST7735_CS                           PC3
/* I2C pinout */
#define I2C_DDR                             DDRD
#define I2C_PORT                            PORTD
#define I2C_PIN                             PIND
#define SCL                                 PD5
#define SDA                                 PD6
/* encoder pinout */
#define ENCODER_BUTTON_DDR                  DDRC
#define ENCODER_BUTTON_PORT                 PORTC
#define ENCODER_BUTTON_PIN                  PINC
#define ENCODER_BUTTON                      PC0
#define ENCODER_BUTTON_PCINT                PCINT8
#define ENCODER_BUTTON_PCMSK                PCMSK1
#define ENCODER_BUTTON_PCIE                 PCIE1
#define ENCODER_BUTTON_PCIF                 PCIF1
#define ENCODER_BUTTON_PCINT_vector         PCINT1_vect
#define ENCODER_ROTOR_DDR                   DDRC
#define ENCODER_ROTOR_PORT                  PORTC
#define ENCODER_ROTOR_PIN                   PINC
#define ENCODER_ROTOR_PIN_LS                PC2
#define ENCODER_ROTOR_PIN_MS                PC1

#endif /* PINOUT_H_ */