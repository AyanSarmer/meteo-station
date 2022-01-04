#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>

class hardwareSerial
{
	public:
		void begin(long baudRate);
		void println(const char* buff);
	private:
		void sendByte(char symbol);
};

extern hardwareSerial Serial;

#endif /* SERIAL_H_ */