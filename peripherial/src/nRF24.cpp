#include "nRF24.h"

NRF24 nRF24;

void NRF24::command(unsigned char command)
{
    CS_nRF24_LOW;
    SPI.byte(command);
    CS_nRF24_HIGH;
}

void NRF24::writeRegister(unsigned char reg, unsigned char* buf, unsigned char length)
{
	reg |= W_REGISTER;
	CS_nRF24_LOW;;
	SPI.byte(reg);
	while (length--)
	{
		SPI.byte(*buf++);
	}
	CS_nRF24_HIGH;   
}

unsigned char NRF24::readRegister(unsigned char reg, unsigned char* buf, unsigned char length)
{
	CS_nRF24_LOW;
	unsigned char status = SPI.byte(reg);
	while(length--)
	{
		*buf++ = SPI.byte(NOP);
	}
	CS_nRF24_HIGH;

	return status;
}

void NRF24::begin(unsigned char mode)
{
    nRF24_DDR |= (1 << CS_nRF24) | (1 << CE);
    CS_nRF24_HIGH;

	_delay_ms(100);
	if(mode == PTX)
	{
		setPTX();
	}
	else if(mode == PRX)
	{
		setPRX();		
	}
	flushStatus();
	flushFIFO();	
}

void NRF24::setPTX()
{
	unsigned char mask = PTX_MASK;
	writeRegister(CONFIG, &mask, sizeof(mask));
	CE_LOW;
}

void NRF24::setPRX()
{
	unsigned char mask = PRX_MASK;
	writeRegister(CONFIG, &mask, sizeof(mask));
	mask = PAYLOAD_SIZE;
	writeRegister(RX_PW_P0, &mask, sizeof(mask));
	powerUp();
	CE_HIGH;
	_delay_us(150);
}

void NRF24::powerUp()
{
	unsigned char config;

	readRegister(CONFIG, &config, 1);
	config |= (1 << PWR_UP);
	writeRegister(CONFIG, &config, 1); 
	_delay_ms(2);
}

void NRF24::powerDown()
{
	unsigned char config;
	
	readRegister(CONFIG, &config, 1);
	config &= ~(1 << PWR_UP);
	writeRegister(CONFIG, &config, 1); 
}

void NRF24::trasmit()
{
	writeRegister(W_TX_PAYLOAD, payload, PAYLOAD_SIZE);
	CE_HIGH;
	_delay_us(15);
	CE_LOW;
	_delay_us(135);
}

void NRF24::receive()
{
	status = readRegister(R_RX_PAYLOAD, payload, PAYLOAD_SIZE);
	flushStatus();
}

void NRF24::flushStatus()
{
	unsigned char mask = STATUS_CLEAR_MASK;
	writeRegister(STATUS, &mask, sizeof(mask));
}

void NRF24::flushFIFO()
{
	command(FLUSH_TX);
	command(FLUSH_RX);
}


