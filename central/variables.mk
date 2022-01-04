# Основные параметры проекта
FILE				= central
MCU					= atmega328p
# Папки хранения файлов
SRC_DIR       		= src
INC_DIR       		= inc
EXE_DIR       		= exe
# Список объектных файлов
SOURCES       		= $(wildcard $(SRC_DIR)/*.cpp)
# Компилятор GCC и его опции
PREAMBLE      		= avr-
COMPILER      		= $(PREAMBLE)gcc
	CC_OPTIONS  	= -mmcu=$(MCU)
	CC_OPTIONS  	+= -Wl,-u,vfprintf -lprintf_flt
	CC_OPTIONS  	+= -Os
	CC_OPTIONS		+= -I $(INC_DIR)
	CC_OPTIONS  	+= -o
# Загрузчик и его опции
UPLOADER      		= avrdude
	U_OPTIONS		= -p $(MCU)
	U_OPTIONS		+= -c usbasp
	U_OPTIONS		+= -P usb
	U_OPTIONS		+= -e
	U_OPTIONS		+= -U flash:w:$(EXE_DIR)/$(FILE).hex

	
