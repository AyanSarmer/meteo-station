#include "Serial.h"

hardwareSerial Serial;

void hardwareSerial::begin(long baudRate)
{
	unsigned int ubrrValue;
	switch (baudRate)
	{
		case 2400:
			ubrrValue = 416;
			break;
		case 4800:
			ubrrValue = 207;
			break;	
		case 9600:
			ubrrValue = 103;
			break;
		case 14400:
			ubrrValue = 68;
			break;
		case 19200:
			ubrrValue = 51;
			break;
		case 28800:
			ubrrValue = 34;
			break;
		case 38400:
			ubrrValue = 25;
			break;
		case 57600:
			ubrrValue = 16;
			break;
		case 76800:
			ubrrValue = 12;
			break;
		case 115200:
			ubrrValue = 8;
			break;
		case 23400:
			ubrrValue = 3;
			break;
		default:
		break;
	}
	UBRR0H = (unsigned char)(ubrrValue >> 8);
	UBRR0L = (unsigned char)(ubrrValue);
	UCSR0B |= (1 << TXEN0);
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ00);
}

void hardwareSerial::sendByte(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void hardwareSerial::println(const char* buff)
{
	while(*buff != '\0')
	{
		sendByte(*buff);
		buff++;
	}
	sendByte('\n');
}