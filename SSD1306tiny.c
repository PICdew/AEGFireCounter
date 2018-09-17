/*********************************************************************
This is a library for our Monochrome OLEDs based on SSD1306 drivers

BSD license, check License.txt for more information
*********************************************************************/


#include <xc.h>
#include "SSD1306tiny.h"
#include <stdint.h>
#include "I2CMaster.h"
#include "digitfont.h"

#define SSD1306_ADDR 0x3C


void ssd1306_command(uint8_t command) {
    uint8_t controll = 0;
    uint8_t ans = 0;
    ans = start_I2C(SSD1306_ADDR, 0); //write start
    if(ans == 0){
        send_I2C(controll);
        send_I2C(command);
    }
    stop_I2C();
    return;
}

void invertDisplay(uint8_t i) {
  if (i == 1) {
    ssd1306_command(SSD1306_INVERTDISPLAY);
  } else {
    ssd1306_command(SSD1306_NORMALDISPLAY);
  }
}

void clearDisplay(void){
    uint8_t colnum, pagenum = 0;
    ssd1306_command(SSD1306_COLUMNADDR);
    ssd1306_command(0);
    ssd1306_command(SSD1306_LCDWIDTH-1);
    ssd1306_command(SSD1306_PAGEADDR);
    ssd1306_command(0); // Page start address (0 = reset)
    ssd1306_command(7); // Page end address
    for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
      // send a bunch of data in one xmission
      start_I2C(SSD1306_ADDR, 0);
      send_I2C(0x40);
      for (uint8_t x=0; x<16; x++) {
        send_I2C(0);
        i++;
      }
      i--;
      stop_I2C();
    }
}

void putChar_Display(uint8_t position_x, uint8_t position_y, char s){
    ssd1306_command(SSD1306_COLUMNADDR);
    ssd1306_command(position_x * FONT_WIDTH);
    ssd1306_command((position_x + 1) * FONT_WIDTH - 1);
    ssd1306_command(SSD1306_PAGEADDR);
    ssd1306_command(position_y); // Page start address (0 = reset)
    ssd1306_command(position_y + (FONT_HEIGHT / 8) - 1); // Page end address
    uint16_t ptrFontHead = (uint16_t)((uint8_t)s * FONT_BYTES);
    for (uint16_t i=0; i<FONT_BYTES; i++) {
      // send a bunch of data in one xmission
      start_I2C(SSD1306_ADDR, 0);
      send_I2C(0x40);
      for (uint8_t x=0; x<FONT_BYTES; x++) {
        send_I2C(font_0[(uint16_t)(i + ptrFontHead)]);
        i++;
      }
      i--;
      stop_I2C();
    }
}

uint8_t putString_Display(uint8_t position_x, uint8_t position_y, char * s){
    uint8_t charLength = 0;
    char * s_temp = s;
    while(*s_temp){
        charLength++;
        s_temp++;
    }
    
    if((position_x + charLength) * FONT_WIDTH > 128-FONT_WIDTH
            | position_y * FONT_HEIGHT / 8 > 8 - FONT_HEIGHT / 8){
        return 1;
    }
    
    while(charLength){
        putChar_Display(position_x++, position_y * FONT_HEIGHT / 8, *s++);
        charLength--;
    }
    
    return 0;
}

void initDisplay(){
    // Init sequence
  ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
  ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
  ssd1306_command(0x80);                                  // the suggested ratio 0x80

  ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
  ssd1306_command(SSD1306_LCDHEIGHT - 1);

  ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
  ssd1306_command(0x0);                                   // no offset
  ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
  ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
  ssd1306_command(0x14);
  ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
  ssd1306_command(0x00);                                  // 0x0 act like ks0108
  ssd1306_command(SSD1306_SEGREMAP | 0x1);
  ssd1306_command(SSD1306_COMSCANDEC);

#if defined SSD1306_128_32
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x02);
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  ssd1306_command(0x8F);

#elif defined SSD1306_128_64
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x12);
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  ssd1306_command(0xCF);
  
#endif
  
  ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
  ssd1306_command(0xF1);
  ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
  ssd1306_command(0x40);
  ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
  ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6

  ssd1306_command(SSD1306_DEACTIVATE_SCROLL);

  ssd1306_command(SSD1306_DISPLAYON);//--turn on oled panel
}
