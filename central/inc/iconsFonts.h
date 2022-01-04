#ifndef ICONS_FONTS_H_
#define ICONS_FONTS_H_

#include <avr/pgmspace.h>

typedef struct tImage
{
    const unsigned char *data;
	unsigned int width;
	unsigned int hight;
} tImage;

typedef struct tChar
{
	const tImage *image;
} tChar;

typedef struct tFont
{
	const tChar *chars;
} tFont;

/* time fonts */
extern const unsigned char image_data_Arial36_0x30[] PROGMEM;
extern tImage Arial36_0x30; 
extern const unsigned char image_data_Arial36_0x31[] PROGMEM;
extern tImage Arial36_0x31; 
extern const unsigned char image_data_Arial36_0x32[] PROGMEM;
extern tImage Arial36_0x32; 
extern const unsigned char image_data_Arial36_0x33[] PROGMEM;
extern tImage Arial36_0x33; 
extern const unsigned char image_data_Arial36_0x34[] PROGMEM;
extern tImage Arial36_0x34; 
extern const unsigned char image_data_Arial36_0x35[] PROGMEM;
extern tImage Arial36_0x35; 
extern const unsigned char image_data_Arial36_0x36[] PROGMEM;
extern tImage Arial36_0x36; 
extern const unsigned char image_data_Arial36_0x37[] PROGMEM;
extern tImage Arial36_0x37; 
extern const unsigned char image_data_Arial36_0x38[] PROGMEM;
extern tImage Arial36_0x38; 
extern const unsigned char image_data_Arial36_0x39[] PROGMEM;
extern tImage Arial36_0x39; 
extern const unsigned char image_data_Arial36_0x3a[] PROGMEM;
extern tImage Arial36_0x3a; 

/* temperature fonts */
extern const unsigned char image_data_Arial16_0x20[] PROGMEM;
extern tImage Arial16_0x20; 
extern const unsigned char image_data_Arial16_0x21[] PROGMEM;
extern tImage Arial16_0x21; 
extern const unsigned char image_data_Arial16_0x22[] PROGMEM;
extern tImage Arial16_0x22; 
extern const unsigned char image_data_Arial16_0x23[] PROGMEM;
extern tImage Arial16_0x23; 
extern const unsigned char image_data_Arial16_0x24[] PROGMEM;
extern tImage Arial16_0x24; 
extern const unsigned char image_data_Arial16_0x25[] PROGMEM;
extern tImage Arial16_0x25; 
extern const unsigned char image_data_Arial16_0x26[] PROGMEM;
extern tImage Arial16_0x26; 
extern const unsigned char image_data_Arial16_0x27[] PROGMEM;
extern tImage Arial16_0x27; 
extern const unsigned char image_data_Arial16_0x28[] PROGMEM;
extern tImage Arial16_0x28; 
extern const unsigned char image_data_Arial16_0x29[] PROGMEM;
extern tImage Arial16_0x29; 
extern const unsigned char image_data_Arial16_0x2a[] PROGMEM;
extern tImage Arial16_0x2a; 
extern const unsigned char image_data_Arial16_0x2b[] PROGMEM;
extern tImage Arial16_0x2b; 
extern const unsigned char image_data_Arial16_0x2c[] PROGMEM;
extern tImage Arial16_0x2c; 
extern const unsigned char image_data_Arial16_0x2d[] PROGMEM;
extern tImage Arial16_0x2d; 
extern const unsigned char image_data_Arial16_0x2e[] PROGMEM;
extern tImage Arial16_0x2e; 
extern const unsigned char image_data_Arial16_0x2f[] PROGMEM;
extern tImage Arial16_0x2f; 
extern const unsigned char image_data_Arial16_0x30[] PROGMEM;
extern tImage Arial16_0x30; 
extern const unsigned char image_data_Arial16_0x31[] PROGMEM;
extern tImage Arial16_0x31; 
extern const unsigned char image_data_Arial16_0x32[] PROGMEM;
extern tImage Arial16_0x32; 
extern const unsigned char image_data_Arial16_0x33[] PROGMEM;
extern tImage Arial16_0x33; 
extern const unsigned char image_data_Arial16_0x34[] PROGMEM;
extern tImage Arial16_0x34; 
extern const unsigned char image_data_Arial16_0x35[] PROGMEM;
extern tImage Arial16_0x35; 
extern const unsigned char image_data_Arial16_0x36[] PROGMEM;
extern tImage Arial16_0x36; 
extern const unsigned char image_data_Arial16_0x37[] PROGMEM;
extern tImage Arial16_0x37; 
extern const unsigned char image_data_Arial16_0x38[] PROGMEM;
extern tImage Arial16_0x38; 
extern const unsigned char image_data_Arial16_0x39[] PROGMEM;
extern tImage Arial16_0x39; 
extern const unsigned char image_data_Arial16_0x3a[] PROGMEM;
extern tImage Arial16_0x3a; 
extern const unsigned char image_data_Arial16_0x3b[] PROGMEM;
extern tImage Arial16_0x3b; 
extern const unsigned char image_data_Arial16_0x3c[] PROGMEM;
extern tImage Arial16_0x3c; 
extern const unsigned char image_data_Arial16_0x3d[] PROGMEM;
extern tImage Arial16_0x3d; 
extern const unsigned char image_data_Arial16_0x3e[] PROGMEM;
extern tImage Arial16_0x3e; 
extern const unsigned char image_data_Arial16_0x3f[] PROGMEM;
extern tImage Arial16_0x3f; 
extern const unsigned char image_data_Arial16_0x40[] PROGMEM;
extern tImage Arial16_0x40; 
extern const unsigned char image_data_Arial16_0x41[] PROGMEM;
extern tImage Arial16_0x41; 
extern const unsigned char image_data_Arial16_0x42[] PROGMEM;
extern tImage Arial16_0x42; 
extern const unsigned char image_data_Arial16_0x43[] PROGMEM;
extern tImage Arial16_0x43; 
extern const unsigned char image_data_Arial16_0x44[] PROGMEM;
extern tImage Arial16_0x44; 
extern const unsigned char image_data_Arial16_0x45[] PROGMEM;
extern tImage Arial16_0x45; 
extern const unsigned char image_data_Arial16_0x46[] PROGMEM;
extern tImage Arial16_0x46; 
extern const unsigned char image_data_Arial16_0x47[] PROGMEM;
extern tImage Arial16_0x47; 
extern const unsigned char image_data_Arial16_0x48[] PROGMEM;
extern tImage Arial16_0x48; 
extern const unsigned char image_data_Arial16_0x49[] PROGMEM;
extern tImage Arial16_0x49; 
extern const unsigned char image_data_Arial16_0x4a[] PROGMEM;
extern tImage Arial16_0x4a; 
extern const unsigned char image_data_Arial16_0x4b[] PROGMEM;
extern tImage Arial16_0x4b; 
extern const unsigned char image_data_Arial16_0x4c[] PROGMEM;
extern tImage Arial16_0x4c; 
extern const unsigned char image_data_Arial16_0x4d[] PROGMEM;
extern tImage Arial16_0x4d; 
extern const unsigned char image_data_Arial16_0x4e[] PROGMEM;
extern tImage Arial16_0x4e; 
extern const unsigned char image_data_Arial16_0x4f[] PROGMEM;
extern tImage Arial16_0x4f; 
extern const unsigned char image_data_Arial16_0x50[] PROGMEM;
extern tImage Arial16_0x50; 
extern const unsigned char image_data_Arial16_0x51[] PROGMEM;
extern tImage Arial16_0x51; 
extern const unsigned char image_data_Arial16_0x52[] PROGMEM;
extern tImage Arial16_0x52; 
extern const unsigned char image_data_Arial16_0x53[] PROGMEM;
extern tImage Arial16_0x53; 
extern const unsigned char image_data_Arial16_0x54[] PROGMEM;
extern tImage Arial16_0x54; 
extern const unsigned char image_data_Arial16_0x55[] PROGMEM;
extern tImage Arial16_0x55; 
extern const unsigned char image_data_Arial16_0x56[] PROGMEM;
extern tImage Arial16_0x56; 
extern const unsigned char image_data_Arial16_0x57[] PROGMEM;
extern tImage Arial16_0x57; 
extern const unsigned char image_data_Arial16_0x58[] PROGMEM;
extern tImage Arial16_0x58; 
extern const unsigned char image_data_Arial16_0x59[] PROGMEM;
extern tImage Arial16_0x59; 
extern const unsigned char image_data_Arial16_0x5a[] PROGMEM;
extern tImage Arial16_0x5a; 
extern const unsigned char image_data_Arial16_0x5b[] PROGMEM;
extern tImage Arial16_0x5b; 
extern const unsigned char image_data_Arial16_0x5c[] PROGMEM;
extern tImage Arial16_0x5c; 
extern const unsigned char image_data_Arial16_0x5d[] PROGMEM;
extern tImage Arial16_0x5d; 
extern const unsigned char image_data_Arial16_0x5e[] PROGMEM;
extern tImage Arial16_0x5e; 
extern const unsigned char image_data_Arial16_0x5f[] PROGMEM;
extern tImage Arial16_0x5f; 
extern const unsigned char image_data_Arial16_0x60[] PROGMEM;
extern tImage Arial16_0x60; 
extern const unsigned char image_data_Arial16_0x61[] PROGMEM;
extern tImage Arial16_0x61; 
extern const unsigned char image_data_Arial16_0x62[] PROGMEM;
extern tImage Arial16_0x62; 
extern const unsigned char image_data_Arial16_0x63[] PROGMEM;
extern tImage Arial16_0x63; 
extern const unsigned char image_data_Arial16_0x64[] PROGMEM;
extern tImage Arial16_0x64; 
extern const unsigned char image_data_Arial16_0x65[] PROGMEM;
extern tImage Arial16_0x65; 
extern const unsigned char image_data_Arial16_0x66[] PROGMEM;
extern tImage Arial16_0x66; 
extern const unsigned char image_data_Arial16_0x67[] PROGMEM;
extern tImage Arial16_0x67; 
extern const unsigned char image_data_Arial16_0x68[] PROGMEM;
extern tImage Arial16_0x68; 
extern const unsigned char image_data_Arial16_0x69[] PROGMEM;
extern tImage Arial16_0x69; 
extern const unsigned char image_data_Arial16_0x6a[] PROGMEM;
extern tImage Arial16_0x6a; 
extern const unsigned char image_data_Arial16_0x6b[] PROGMEM;
extern tImage Arial16_0x6b; 
extern const unsigned char image_data_Arial16_0x6c[] PROGMEM;
extern tImage Arial16_0x6c; 
extern const unsigned char image_data_Arial16_0x6d[] PROGMEM;
extern tImage Arial16_0x6d; 
extern const unsigned char image_data_Arial16_0x6e[] PROGMEM;
extern tImage Arial16_0x6e; 
extern const unsigned char image_data_Arial16_0x6f[] PROGMEM;
extern tImage Arial16_0x6f; 
extern const unsigned char image_data_Arial16_0x70[] PROGMEM;
extern tImage Arial16_0x70; 
extern const unsigned char image_data_Arial16_0x71[] PROGMEM;
extern tImage Arial16_0x71; 
extern const unsigned char image_data_Arial16_0x72[] PROGMEM;
extern tImage Arial16_0x72; 
extern const unsigned char image_data_Arial16_0x73[] PROGMEM;
extern tImage Arial16_0x73; 
extern const unsigned char image_data_Arial16_0x74[] PROGMEM;
extern tImage Arial16_0x74; 
extern const unsigned char image_data_Arial16_0x75[] PROGMEM;
extern tImage Arial16_0x75; 
extern const unsigned char image_data_Arial16_0x76[] PROGMEM;
extern tImage Arial16_0x76; 
extern const unsigned char image_data_Arial16_0x77[] PROGMEM;
extern tImage Arial16_0x77; 
extern const unsigned char image_data_Arial16_0x78[] PROGMEM;
extern tImage Arial16_0x78; 
extern const unsigned char image_data_Arial16_0x79[] PROGMEM;
extern tImage Arial16_0x79; 
extern const unsigned char image_data_Arial16_0x7a[] PROGMEM;
extern tImage Arial16_0x7a; 
extern const unsigned char image_data_Arial16_0x7b[] PROGMEM;
extern tImage Arial16_0x7b; 
extern const unsigned char image_data_Arial16_0x7c[] PROGMEM;
extern tImage Arial16_0x7c; 
extern const unsigned char image_data_Arial16_0x7d[] PROGMEM;
extern tImage Arial16_0x7d; 
extern const unsigned char image_data_Arial16_0x7e[] PROGMEM;
extern tImage Arial16_0x7e; 
extern const unsigned char image_data_Arial16_circle[] PROGMEM;
extern tImage Arial16_circle;

extern tChar Arial16_array[];
extern tFont Arial16;

#endif /* ICONS_FONTS_H_ */