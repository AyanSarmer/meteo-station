include variables.mk

all:
	mkdir -p $(EXE_DIR)
	$(COMPILER) $(SOURCES) $(CC_OPTIONS) $(EXE_DIR)/$(FILE).hex	
	avr-size $(EXE_DIR)/$(FILE).hex	
	$(UPLOADER) $(U_OPTIONS)