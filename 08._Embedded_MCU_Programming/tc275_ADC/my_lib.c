/*
 * my_lib.c
 *
 *  Created on: 2022. 3. 4.
 *      Author: user
 */
#include "my_lib.h"

/* Initialize RGB LED */
void init_RGBLED(void)
{
    /* Reset IOCR0 bits */
    PORT02_IOCR4 &= ~((0x1F) << PC7);
    PORT10_IOCR4 &= ~((0x1F) << PC5);
    PORT10_IOCR0 &= ~((0x1F) << PC3);

    /* Set PC bits in IOCR0 with push-pull(2b10000) */
    PORT02_IOCR4 |= ((0x10) << PC7);
    PORT10_IOCR4 |= ((0x10) << PC5);
    PORT10_IOCR0 |= ((0x10) << PC3);
}

void init_VADC(void)
{
    /* VADC Enable */
    /* Password Access to unlock WDTCPU0CON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    VADC_CLC &= ~(1 << DISR);                 // Enable VADC Module

    /* Password Access to unlock WDTSCPU0CON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((VADC_CLC & (1 << DISS)) != 0);     // Wait until module is enabled

    VADC_G4ARBPR |= ((0x3) << PRIO0);         // Highest Priority for Request Source 0
    VADC_G4ARBPR &= ~(1 << CSM0);             // Conversion Start Mode : Wait-for-start mode
    VADC_G4ARBPR |= (1 << ASEN0);             // Arbitration Source Input 0 Enable

    VADC_G4QMR0  &= ~((0x3) << ENGT);         // Enable Conversion Requests
    VADC_G4QMR0  |= ((0x1) << ENGT);

    VADC_G4QMR0  |= (1 << FLUSH);             // Clear all Queue Entries

    VADC_G4ARBCFG |= ((0x3) << ANONC);        // Analog Converter : Normal Operation

    VADC_G4ICLASS0 &= ~((0x7) << CMS);        // Group-specific Class 0
                                              // Conversion Mode : Standard Conversion (12-bit)

    /* VADC Group 4 Channel 7 Setting */
    VADC_G4CHCTR7 |= (1 << RESPOS);           // Read Results Right-aligned
    VADC_G4CHCTR7 &= ~((0xF) << RESREG);      // Store Result in Group Result Register G4RES1
    VADC_G4CHCTR7 |= (1 << RESREG);
    VADC_G4CHCTR7 &= ~((0x3) << ICLSEL);      // Use Group-specific Class 0

    /* VADC Group 4 Channel 6 Setting */
    VADC_G4CHCTR6 |= (1 << RESPOS);           // Read Results Right-aligned
    VADC_G4CHCTR6 &= ~((0xF) << RESREG);      // Store Result in Group Result Register G4RES1
    VADC_G4CHCTR6 |= (1 << RESREG);
    VADC_G4CHCTR6 &= ~((0x3) << ICLSEL);      // Use Group-specific Class 0
}


void VADC_startConversion(void)
{
    /* No fill and Start Queue */
    VADC_G4QINR0 &= ~(0x1F);                 // Request Channel Number : 7
    VADC_G4QINR0 |= (0x07);

    VADC_G4QINR0 &= ~(1 << RF);              // No fill : it is converted once

    VADC_G4QMR0 |= (1 << TREV);              // Generate a Trigger Event
}

unsigned int VADC_readResult(void)
{
    unsigned int result;

    while((VADC_G4RES1 & (1 << VF)) == 0);          // Wait until New Result Available

    result = (VADC_G4RES1 & ((0xFFFF) << RESULT));  // Read Result

    return result;
}


unsigned int GetVADC4(unsigned int ChannelNum)
{
    unsigned int result;
    /* No fill and Start Queue */
    VADC_G4QINR0 &= ~(0x1F);                 // Request Channel Number
    VADC_G4QINR0 |= (ChannelNum);

    VADC_G4QINR0 &= ~(1 << RF);              // No fill : it is converted once

    VADC_G4QMR0 |= (1 << TREV);              // Generate a Trigger Event

    while((VADC_G4RES1 & (1 << VF)) == 0);          // Wait until New Result Available

    result = (VADC_G4RES1 & ((0xFFFF) << RESULT));  // Read Result

    return result;
}

void SetRGBLED(int adcResult)
{
    if(adcResult >= 3096)
    {
        PORT02_OMR |= (1<<PS7);            // Set LED RED
        PORT10_OMR |= (1<<PCL5);           // Clear LED GREEN
        PORT10_OMR |= (1<<PCL3);           // Clear LED BLUE
    }
    else if(adcResult >= 2048)
    {
        PORT02_OMR |= (1<<PCL7);            // Clear LED RED
        PORT10_OMR |= (1<<PS5);             // Set LED GREEN
        PORT10_OMR |= (1<<PCL3);            // Clear LED BLUE
    }
    else if(adcResult >= 1024)
    {
        PORT02_OMR |= (1<<PCL7);            // Clear LED RED
        PORT10_OMR |= (1<<PCL5);            // Clear LED GREEN
        PORT10_OMR |= (1<<PS3);             // Set LED BLUE
    }
    else
    {
        PORT02_OMR |= (1<<PCL7);            // Clear LED RED
        PORT10_OMR |= (1<<PCL5);            // Clear LED GREEN
        PORT10_OMR |= (1<<PCL3);            // Clear LED BLUE
    }
}

