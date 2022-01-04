#ifndef nRF24_H_
#define nRF24_H_

#define F_CPU                   16000000UL

#include <util/delay.h>
#include "SPI.h"

#define CS_nRF24_HIGH		nRF24_PORT |= (1 << CS_nRF24)
#define CS_nRF24_LOW		nRF24_PORT &= ~(1 << CS_nRF24)
#define CE_HIGH		        nRF24_PORT |= (1 << CE)
#define CE_LOW      	    nRF24_PORT &= ~(1 << CE)

/* nRF24 commands and registers */
/* commands */
#define R_REGISTER          0x00
#define W_REGISTER          0x20
#define R_RX_PAYLOAD        0x61
#define W_TX_PAYLOAD        0xA0
#define FLUSH_TX            0xE1
#define FLUSH_RX            0xE2
#define NOP                 0xFF
/* registers */
#define CONFIG              0x00
#define MASK_RX_DR			6
#define MASK_TX_DS			5
#define MASK_MAX_RT			4
#define EN_CRC				3
#define CRCO				2
#define PWR_UP				1
#define PRIM_RX				0
#define SETUP_AW            0x03
#define RF_CH				0x05
#define RF_SETUP            0x06
#define STATUS              0x07
#define RX_DR				6
#define TX_DS				5
#define MAX_RT				4
#define RX_P_NO				1
#define TX_FULL				0
#define RX_ADDR_P0          0x0A
#define RX_ADDR_P1          0x0B
#define RX_ADDR_P2          0x0C
#define RX_ADDR_P3          0x0D
#define RX_ADDR_P4          0x0E
#define RX_ADDR_P5          0x0F
#define TX_ADDR             0x10
#define RX_PW_P0            0x11

#define PAYLOAD_SIZE        2
#define PTX                 1
#define PRX                 2

#define PTX_MASK            (1 << MASK_RX_DR) | (1 << MASK_TX_DS) | (1 << MASK_MAX_RT) | (1 << EN_CRC)
#define PRX_MASK            (1 << MASK_TX_DS) | (1 << MASK_MAX_RT) | (1 << EN_CRC) | (1 << PRIM_RX)
#define STATUS_CLEAR_MASK   (1 << RX_DR) | (1 << TX_DS) | (1 << MAX_RT) | (1 << TX_FULL)

class NRF24
{
    private:
        void command(unsigned char command);
        void writeRegister(unsigned char reg, unsigned char* buf, unsigned char length);
        unsigned char readRegister(unsigned char reg, unsigned char* buf, unsigned char length);
        void flushStatus();
        void flushFIFO();
    public:
        void begin(unsigned char mode);
        void setPTX();
        void setPRX();
        void powerUp();
        void powerDown();
        void trasmit(); 
        void receive();
    public:
        unsigned char status;
        unsigned char payload[PAYLOAD_SIZE];
};

extern NRF24 nRF24;

#endif /* nRF24_H_ */
