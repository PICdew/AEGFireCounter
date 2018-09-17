/*
 * File:   SSD1306tiny.c
 * Author: Kazusa
 *
 * Created on 2018/09/09, 11:08
 */

#include "I2CMaster.h"
#include <xc.h>

uint8_t AckCheck = 0;

void init_I2C(void){
    SSP1STAT= 0b10000000;
    SSP1CON1= 0b00101000;
    SSP1ADD = 0x09; // Fosc = 16MHz, SCL = 400kHz
    ANSELBbits.ANSB4 = 0;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.SSP1IE = 1; 
    PIR1bits.SSP1IF = 0;
}

uint8_t start_I2C(uint8_t adrs, uint8_t rw){
    uint8_t dt = (uint8_t)((adrs<<1)+rw) ;
    checkIdle_I2C(0x5) ;
    AckCheck = 1 ;
    SSP1CON2bits.SEN = 1 ;
    while (AckCheck == 1) ;
    AckCheck = 1 ;
    //checkIdle_I2C(0x5) ;
    SSP1CON1bits.WCOL = 0;
    SSP1BUF = dt;
    while (AckCheck == 1) ;
    return SSP1CON2bits.ACKSTAT ;
}

uint8_t send_I2C(uint8_t dt){
     checkIdle_I2C(0x5) ;
     AckCheck = 1 ;
     SSP1CON1bits.WCOL = 0;
     SSP1BUF = dt ;
     while (AckCheck == 1) ;
     return SSP1CON2bits.ACKSTAT ;
}

void checkIdle_I2C(uint8_t mask){
     while (( SSP1CON2 & 0x1F ) | (SSP1STAT & mask)) ;
}

void stop_I2C(){
     checkIdle_I2C(0x5) ;
     SSP1CON2bits.PEN = 1 ;
}

void isr_I2C(){
     if (PIR1bits.SSP1IF == 1) {
          AckCheck = 0;
          PIR1bits.SSP1IF = 0;      
     }
}
