 /**
   CLC1 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     clc1.c
 
   @Summary
     This is the generated driver implementation file for the CLC1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CLC1.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
         Device            :  PIC16F1509
         Driver Version    :  2.11
     The generated drivers are tested against the following:
         Compiler          :  XC8 1.45 or later
         MPLAB             :  MPLAB X 4.15
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
 
 /**
   Section: Included Files
 */

#include <xc.h>
#include "clc1.h"

/**
  Section: CLC1 APIs
*/

void CLC1_Initialize(void)
{
    // Set the CLC1 to the options selected in the User Interface

    // LC1G1POL inverted; LC1G2POL not_inverted; LC1G3POL inverted; LC1G4POL not_inverted; LC1POL not_inverted; 
    CLC1POL = 0x05;
    // LC1D2S FOSC; LC1D1S SYNCC1OUT; 
    CLC1SEL0 = 0x02;
    // LC1D4S CLCIN1; LC1D3S NCO1OUT; 
    CLC1SEL1 = 0x54;
    // LC1G1D3N disabled; LC1G1D2N disabled; LC1G1D4N enabled; LC1G1D1T disabled; LC1G1D3T disabled; LC1G1D2T disabled; LC1G1D4T disabled; LC1G1D1N enabled; 
    CLC1GLS0 = 0x41;
    // LC1G2D2N disabled; LC1G2D1N disabled; LC1G2D4N disabled; LC1G2D3N disabled; LC1G2D2T disabled; LC1G2D1T disabled; LC1G2D4T disabled; LC1G2D3T disabled; 
    CLC1GLS1 = 0x00;
    // LC1G3D1N disabled; LC1G3D2N disabled; LC1G3D3N enabled; LC1G3D4N disabled; LC1G3D1T enabled; LC1G3D2T disabled; LC1G3D3T disabled; LC1G3D4T disabled; 
    CLC1GLS2 = 0x12;
    // LC1G4D1N disabled; LC1G4D2N disabled; LC1G4D3N disabled; LC1G4D4N disabled; LC1G4D1T disabled; LC1G4D2T disabled; LC1G4D3T disabled; LC1G4D4T disabled; 
    CLC1GLS3 = 0x00;
    // LC1EN enabled; LCINTN disabled; LCINTP disabled; LC1MODE SR latch; LC1OE enabled; 
    CLC1CON = 0xC3;

}


bool CLC1_OutputStatusGet(void)
{
    return(CLC1CONbits.LC1OUT);
}
/**
 End of File
*/
