/*********************************************************************
This is a library for our Monochrome OLEDs based on SSD1306 drivers

BSD license, check License.txt for more information
*********************************************************************/


// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SSD1306TINY_H
#define	SSD1306TINY_H

#include <stdint.h>
#include "I2CMaster.h"

void ssd1306_command(uint8_t);
void invertDisplay(uint8_t);
void initDisplay(void);
void clearDisplay(void);
void putChar_Display(uint8_t, uint8_t, char);
uint8_t putString_Display(uint8_t, uint8_t, char * );

#include <xc.h> // include processor files - each processor file is guarded.  
//#define SSD1306_128_64
#define SSD1306_128_32

#if defined SSD1306_128_64

#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 64

#endif

#if defined SSD1306_128_32

#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 32

#endif

#define SSD1306_ADDR 0x3C

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

#endif