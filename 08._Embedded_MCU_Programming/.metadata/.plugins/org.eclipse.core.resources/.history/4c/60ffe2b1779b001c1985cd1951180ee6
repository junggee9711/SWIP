/*
 * my_lib.c
 *
 *  Created on: 2022. 3. 4.
 *      Author: user
 */
#include "my_lib.h"
#include <stdio.h>

void init_LED(void)
{
    /* Reset PC1 in IOCR0*/
    PORT10_IOCR0 &= ~((0x1F) << PC1);

    /* Set PC1 with push-pull(2b10000) */
    PORT10_IOCR0 |= ((0x10) << PC1);

    /* Reset PC2 in IOCR0*/
    PORT10_IOCR0 &= ~((0x1F) << PC2);

    /* Set PC1 with push-pull(2b10000) */
    PORT10_IOCR0 |= ((0x10) << PC2);

    /* LED OFF */
    PORT10_OMR = ((1<<PCL1) | (1<<PCL2));
}

#if 0
void init_CCU60(void)
{
    /* CCU60 T12 Setting */

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    CCU60_CLC &= ~(1 << DISR);                     // Enable CCU60 Module

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((CCU60_CLC & (1 << DISS)) != 0);       // Wait until module is enabled

    CCU60_TCTR0 &= ~((0x7) << T12CLK);           // f_T12 = f_CCU6 / prescaler
    CCU60_TCTR0 |= ((0x3) << T12CLK);            // F_CCU6 = 100 MHz, prescaler = 2048
    CCU60_TCTR0 |= (1 << T12PRE);                // f_T12 = 48828 Hz

    CCU60_TCTR0 &= ~(1 << CTM);                  // T12 always counts up and continues counting
                                                 // from zero after reaching the period value

    CCU60_T12PR = 24414 - 1;                     // Interrupt freq. = f_T12 / (period value  + 1)
    CCU60_TCTR4 |= (1 << T12STR);                // Interrupt freq. = 2 Hz

    CCU60_T12 = 0;                               // Clear T12 counting value

    /* CCU60 T12 Interrupt Setting */
    CCU60_INP &= ~((0x3) << INPT12);             // Service Request output SR0 is selected

    CCU60_IEN |= (1 << ENT12PM);                 // Enable Interrupt for T12 Period-Match

    /* SRC Interrupt Setting For CCU60 */
    SRC_CCU60_SR0 &= ~((0xFF) << SRPN);           // Set Priority : 0x0A
    SRC_CCU60_SR0 |= ((0x0A) << SRPN);

    SRC_CCU60_SR0 &= ~((0x3) << TOS);             // CPU0 services

    SRC_CCU60_SR0 |= (1 << SRE);                  // Service Request is enabled

    /* CCU60 T12 Start */
    CCU60_TCTR4 = (1 << T12RS);                  // T12 starts counting
}
#endif

void init_CCU6(myCCU6 *CCU6, int ms, int int_priority)
{
    /* CCU60 T12 Setting */

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    CCU6->CLC &= ~(1 << DISR);                     // Enable CCU61 Module

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((CCU6->CLC & (1 << DISS)) != 0);       // Wait until module is enabled

    CCU6->TCTR0 &= ~((0x7) << T12CLK);           // f_T12 = f_CCU6 / prescaler, 100MHz
    CCU6->TCTR0 |= ((0x3) << T12CLK);            // F_CCU6 = 100 MHz, prescaler = 2048
    CCU6->TCTR0 |= (1 << T12PRE);                // f_T12 = 48828 Hz

    CCU6->TCTR0 &= ~(1 << CTM);                  // T12 always counts up and continues counting
                                                 // from zero after reaching the period value

    // FIXME: 0.5s -> ms
    CCU6->T12PR = (int)((48828*ms)/1000) - 1;                   // Interrupt freq. = f_T12 / (period value  + 1)
    CCU6->TCTR4 |= (1 << T12STR);                // Interrupt freq. = 2 Hz

    CCU6->T12 = 0;                               // Clear T12 counting value

    /* CCU6 T12 Interrupt Setting */
    CCU6->INP &= ~((0x3) << INPT12);             // Service Request output SR0 is selected

    CCU6->IEN |= (1 << ENT12PM);                 // Enable Interrupt for T12 Period-Match

    /* SRC Interrupt Setting For CCU6 */
    if( (int)CCU6 == CCU60_BASE )
    {
        SRC_CCU60_SR0 &= ~((0xFF) << SRPN);           // Set Priority
        SRC_CCU60_SR0 |= (int_priority << SRPN);
        SRC_CCU60_SR0 &= ~((0x3) << TOS);             // CPU0 services
        SRC_CCU60_SR0 |= (1 << SRE);                  // Service Request is enabled
    }
    else
    {
        SRC_CCU61_SR0 &= ~((0xFF) << SRPN);           // Set Priority
        SRC_CCU61_SR0 |= (int_priority << SRPN);
        SRC_CCU61_SR0 &= ~((0x3) << TOS);             // CPU0 services
        SRC_CCU61_SR0 |= (1 << SRE);                  // Service Request is enabled
    }

    /* CCU6 T12 Start */
    CCU6->TCTR4 = (1 << T12RS);                  // T12 starts counting
}


