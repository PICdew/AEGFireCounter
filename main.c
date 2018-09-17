/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1508
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "SSD1306tiny.h"
#include "I2CMaster.h"
#include "itoa.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void tm2_Systick(void);

bool system_tick = false;
uint8_t systick_num = 0;
/*
                         Main application
 */
void main(void)
{
    char s;
    char st[4];
    char st_cnt[4];
    // initialize the device
    SYSTEM_Initialize();
    init_I2C();
    TMR2_SetInterruptHandler(&tm2_Systick);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    __delay_ms(1000);
    initDisplay();
    clearDisplay();
    
    //char name[11] = "KLAMATH.JP";
   // putString_Display(0, 0, name);
    putString_Display(0, 0, "TIME:000");
    putString_Display(0, 1, "COUNT:000");
    uint8_t system_time = 0;
    
    LATBbits.LATB7 = 1; 
    DAC_SetOutput(0x01);
    while (1)
    {
        systick_num++;
        if(0 == systick_num % 20){
            itoa(st, system_time, 10);
            putString_Display(5, 0, st);
            system_time++;
        } else if(0 == systick_num % 2){
            uint8_t fire_cnt = TMR0_ReadTimer();
            itoa(st_cnt, fire_cnt, 10);
            putString_Display(6, 1, st_cnt);
        }
        if(systick_num == 220) systick_num = 0;
        while(!system_tick){}
        system_tick = false;
        // Add your application code
    }
}

void tm2_Systick(void){
    PIR1bits.TMR2IF = 0;
    system_tick = true;
}
/**
 End of File
*/
