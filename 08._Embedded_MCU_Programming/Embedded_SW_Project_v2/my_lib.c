#include "my_lib.h"

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

    /* VADC Group 4 Channel 7 Setting (potential_meter) */
    VADC_G4CHCTR7 |= (1 << RESPOS);           // Read Results Right-aligned
    VADC_G4CHCTR7 &= ~((0xF) << RESREG);      // Store Result in Group Result Register G4RES1
    VADC_G4CHCTR7 |= (1 << RESREG);
    VADC_G4CHCTR7 &= ~((0x3) << ICLSEL);      // Use Group-specific Class 0

    /* VADC Group 4 Channel 6 Setting (light_sensor) */
    VADC_G4CHCTR6 |= (1 << RESPOS);           // Read Results Right-aligned
    VADC_G4CHCTR6 &= ~((0xF) << RESREG);      // Store Result in Group Result Register G4RES1
    VADC_G4CHCTR6 |= (1 << RESREG);
    VADC_G4CHCTR6 &= ~((0x3) << ICLSEL);      // Use Group-specific Class 0
}

unsigned int GetVADC4(int channel)
{
    unsigned int result;

    result = 0;
    for( int i=0; i<16; i++)
    {
        VADC_G4QINR0 = channel;
        VADC_G4QMR0 |= (1 << TREV);                     // Generate a Trigger Event
        while((VADC_G4RES1 & (1 << VF)) == 0);          // Wait until New Result Available
        result += (VADC_G4RES1 & ((0xFFFF) << RESULT));  // Read Result
    }
    return result>>4;
}

/* Initialize LED (RED,BLUE) */
void init_LED(void)
{
    /* Reset PC1 & PC2 in IOCR0*/
    PORT10_IOCR0 &= ~((0x1F) << PC1);
    PORT10_IOCR0 &= ~((0x1F) << PC2);

    /* Set PC1 & PC2 with push-pull(2b10000) */
    PORT10_IOCR0 |= ((0x10) << PC1);
    PORT10_IOCR0 |= ((0x10) << PC2);
}

void init_LED_start(void)
{
    PORT10_IOCR0 &= ~((0x1F) << PC1);           // PORT10.1 : Alternate output function 1 (push-pull)
    PORT10_IOCR0 |= ((0x10) << PC1);            // PORT10.1 : GTM_TOUT103

    PORT10_IOCR0 &= ~((0x1F) << PC2);           // PORT10.2 : Alternate output function 1 (push-pull)
    PORT10_IOCR0 |= ((0x11) << PC2);            // PORT10.2 : GTM_TOUT104

    PORT10_OMR = (1<<PCL1);
    PORT10_OMR = (1<<PCL2);
}

/* Initialize Switch2 */
void init_Switch(void)
{
    /* Reset PC0 & PC1 in IOCR0*/
    PORT02_IOCR0 &= ~((0x1F) << PC1);
    PORT02_IOCR0 &= ~((0x1F) << PC0);

    /* Set PC0 & PC1 with pull-up(2b0xx10) */
    PORT02_IOCR0 |= ((0x2) << PC1);
    PORT02_IOCR0 |= ((0x2) << PC0);
}

void init_LED_RGB(void)
{
    PORT10_IOCR0 &= ~((0x1F) << PC3);           // PORT10.3 : Alternate output function 1 (push-pull)
    PORT10_IOCR0 |= ((0x10) << PC3);            // PORT10.3 : GTM_TOUT104
    PORT10_IOCR1 &= ~((0x1F) << PC5);           // PORT10.5 : Alternate output function 1 (push-pull)
    PORT10_IOCR1 |= ((0x10) << PC5);            // PORT10.5 : GTM_TOUT103
    PORT02_IOCR1 &= ~((0x1F) << PC7);           // PORT02.7 : Alternate output function 1 (push-pull)
    PORT02_IOCR1 |= ((0x10) << PC7);            // PORT02.7 : GTM_TOUT7
}

void init_ERU(void)
{

    /* Password Access to unlock WDTSCON0 */
    // ^ operator : if 2 bits are same -> '0', elif 2 bits are different -> '1'
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    // Modify Access to clear ENDINIT bit
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    //////////////////////////////////////////////////////////////////////////////////////
    /* ERU Input Channel 2, input 1 Setting */
    SCU_EICR1 &= ~((0x7) << EXIS0);             // External input 1 is selected
    SCU_EICR1 |= ((0x1) << EXIS0);

    SCU_EICR1 |= (1 << FEN0);                   // Falling edge enable

    SCU_EICR1 |= ((0x1) << EIEN0);              // The trigger event is enabled

    SCU_EICR1 &= ~((0x7) << INP0);              // An event from input ETL 2 triggers output OGU 0
    SCU_EICR1 |= (0x0 << INP0);                 // 0b000 => trigger event to output channel 0

    SCU_IGCR0 &= ~((0x3) << IGP0);              // IOUT(0) is activated in response to a trigger event
    SCU_IGCR0 |= ((0x1) << IGP0);               // The pattern is not considered

    ////////////////////////////////////////////////////////////////////////////////////
    /* ERU Input Channel 4, input 3 Setting */
    SCU_EICR2 &= ~((0x7) << EXIS0);             // External input 3 is selected
    SCU_EICR2 |= ((0x3) << EXIS0);

    SCU_EICR2 |= (1 << REN0);                   // Rising edge enable
    SCU_EICR2 |= (1 << FEN0);                   // Falling edge enable

    SCU_EICR2 |= (1 << EIEN0);                  // The trigger event is enabled

    SCU_EICR2 &= ~((0x7) << INP0);              // An event from input ETL 4 triggers output OGU 1
    SCU_EICR2 |= (1 << INP0);                   // 0b001 => trigger event to output channel 1

    SCU_IGCR0 &= ~((0x3) << IGP1);              // IOUT(1) is activated in response to a trigger event
    SCU_IGCR0 |= ((0x1) << IGP1);               // The pattern is not considered
    //////////////////////////////////////////////////////////////////////////////////////

    /* Password Access to unlock WDTSCON0 */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    /* Modify Access to set ENDINIT bit */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    /* SRC Interrupt Setting For ECU */
    // Output channel 0 (0xF003800H + 0xCD4)
    SRC_SCUERU0 &= ~((0xFF) << SRPN);           // Set Priority : 0x0D
    SRC_SCUERU0 |= ((0x0D) << SRPN);            // Set Priority : 0x0D
    SRC_SCUERU0 &= ~((0x3) << TOS);             // CPU0 services
    SRC_SCUERU0 |= (1 << SRE);                  // Service Request is enabled

    /* SRC Interrupt Setting For ECU */
    // Output channel 1 (0xF003800H + 0xCD4 + 0x4)
    SRC_SCUERU1 &= ~((0xFF) << SRPN);           // Set Priority : 0x0B
    SRC_SCUERU1 |= ((0x0B) << SRPN);            // Set Priority : 0x0B
    SRC_SCUERU1 &= ~((0x3) << TOS);             // CPU0 services
    SRC_SCUERU1 |= (1 << SRE);                  // Service Request is enabled
}

void init_GTM_TOM0_PWM_RGB(void)
{
    /* GTM Enable */
    // Password Access to unlock WDTCPU0CON0
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    // Modify Access to clear ENDINIT bit
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~(1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    GTM_CLC &= ~(1 << DISR);                        // Enable GTM Module

    // Password Access to unlock WDTCPU0CON0
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    // Modify Access to set ENDINIT bit
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((GTM_CLC & (1 << DISS)) != 0);            // Wait until module is enabled

    /* GTM Clock Setting */
    GTM_CMU_FXCLK_CTRL &= ~((0xF) << FXCLK_SEL);    // Input clock of CMU_FXCLK : CMU_GCLK_EN

    GTM_CMU_CLK_EN &= ~((0x3) << EN_FXCLK);         // Enable all CMU_FXCLK
    GTM_CMU_CLK_EN |= ((0x2) << EN_FXCLK);

    /* GTM TOM0 PWM Setting channel 0 ~ channel 7*/

    // channel 1 - TOUT103, LED BLUE
    GTM_TOM0_TGC0_GLB_CTRL &= ~((0x3) << UPEN_CTRL1);   // TOM0 channel 1 enable update of
    GTM_TOM0_TGC0_GLB_CTRL |= ((0x2) << UPEN_CTRL1);    // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << FUPD_CTRL1);  // Enable force update of TOM0 channel 1
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << FUPD_CTRL1);
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << RSTCN0_CH1);  // Reset CN0 of TOM0 channel 1 on force update
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << RSTCN0_CH1);
    GTM_TOM0_TGC0_ENDIS_CTRL &= ~((0x3) << ENDIS_CTRL1); // Enable channel 1 on an update trigger
    GTM_TOM0_TGC0_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL1);
    GTM_TOM0_TGC0_OUTEN_CTRL &= ~((0x3) << OUTEN_CTRL1); // Enable channel 1 output on an update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL1);
    GTM_TOM0_CH1_CTRL |= (1 << SL);                     // High signal level for duty cycle
    GTM_TOM0_CH1_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH1_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH1_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH1_SR1 = 0;                               // Duty cycle = 100
    GTM_TOUTSEL6 &= ~((0x3) << SEL7);                   // TOUT103 : TOM0 channel 1

    // channel 2 - TOUT104, LED RED
    GTM_TOM0_TGC0_GLB_CTRL &= ~((0x3) << UPEN_CTRL2);   // TOM0 channel 2 enable update of
    GTM_TOM0_TGC0_GLB_CTRL |= ((0x2) << UPEN_CTRL2);    // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << FUPD_CTRL2);  // Enable force update of TOM0 channel 1
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << FUPD_CTRL2);
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << RSTCN0_CH2);  // Reset CN0 of TOM0 channel 1 on force update
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << RSTCN0_CH2);
    GTM_TOM0_TGC0_ENDIS_CTRL &= ~((0x3) << ENDIS_CTRL2); // Enable channel 1 on an update trigger
    GTM_TOM0_TGC0_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL2);
    GTM_TOM0_TGC0_OUTEN_CTRL &= ~((0x3) << OUTEN_CTRL2); // Enable channel 1 output on an update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL2);
    GTM_TOM0_CH2_CTRL |= (1 << SL);                     // High signal level for duty cycle
    GTM_TOM0_CH2_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH2_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH2_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH2_SR1 = 0;                               // Duty cycle = 100
    GTM_TOUTSEL6 &= ~((0x3) << SEL8);                   // TOUT104 : TOM0 channel 1

    /*
    // channel 2 - RGB LED R
    GTM_TOM0_TGC0_GLB_CTRL &= ~((0x3) << UPEN_CTRL2);   // TOM0 channel 2 enable update of
    GTM_TOM0_TGC0_GLB_CTRL |= ((0x2) << UPEN_CTRL2);    // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << FUPD_CTRL2);  // Enable force update of TOM0 channel 1
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << FUPD_CTRL2);
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << RSTCN0_CH1);  // Reset CN0 of TOM0 channel 1 on force update
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << RSTCN0_CH1);
    GTM_TOM0_TGC0_ENDIS_CTRL &= ~((0x3) << ENDIS_CTRL2); // Enable channel 1 on an update trigger
    GTM_TOM0_TGC0_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL2);
    GTM_TOM0_TGC0_OUTEN_CTRL &= ~((0x3) << OUTEN_CTRL2); // Enable channel 1 output on an update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL2);
    GTM_TOM0_CH2_CTRL |= (1 << SL);                     // High signal level for duty cycle
    GTM_TOM0_CH2_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH2_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH2_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH2_SR1 = 0;                               // Duty cycle = 0
    GTM_TOUTSEL6 &= ~((0x3) << SEL11);                  // TOUT107 : TOM0 channel 2


    // channel 3 - RGB LED G
    GTM_TOM0_TGC0_GLB_CTRL &= ~((0x3) << UPEN_CTRL3);   // TOM0 channel 3 enable update of
    GTM_TOM0_TGC0_GLB_CTRL |= ((0x2) << UPEN_CTRL3);    // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << FUPD_CTRL3);  // Enable force update of TOM0 channel 3
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << FUPD_CTRL3);
    GTM_TOM0_TGC0_FUPD_CTRL &= ~((0x3) << RSTCN0_CH3);  // Reset CN0 of TOM0 channel 3 on force update
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << RSTCN0_CH3);
    GTM_TOM0_TGC0_ENDIS_CTRL &= ~((0x3) << ENDIS_CTRL3); // Enable channel 3 on an update trigger
    GTM_TOM0_TGC0_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL3);
    GTM_TOM0_TGC0_OUTEN_CTRL &= ~((0x3) << OUTEN_CTRL3); // Enable channel 3 output on an update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL3);

    GTM_TOM0_CH3_CTRL |= (1 << SL);                     // High signal level for duty cycle
    GTM_TOM0_CH3_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH3_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH3_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH3_SR1 = 0;                               // Duty cycle = 0
    GTM_TOUTSEL6 &= ~((0x3) << SEL9);                   // TOUT105 : TOM0 channel 3


    // channel 15 - RGB LED B
    GTM_TOM0_TGC1_GLB_CTRL &= ~((0x3) << UPEN_CTRL15);  // TOM0 channel 15 enable update of
    GTM_TOM0_TGC1_GLB_CTRL |= ((0x2) << UPEN_CTRL15);   // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC1_FUPD_CTRL &= ~((0x3) << FUPD_CTRL15); // Enable force update of TOM0 channel 15
    GTM_TOM0_TGC1_FUPD_CTRL |= ((0x2) << FUPD_CTRL15);
    GTM_TOM0_TGC1_FUPD_CTRL &= ~((0x3) << RSTCN0_CH15); // Reset CN0 of TOM0 channel 15 on force update
    GTM_TOM0_TGC1_FUPD_CTRL |= ((0x2) << RSTCN0_CH15);
    GTM_TOM0_TGC1_ENDIS_CTRL &= ~((0x3) << ENDIS_CTRL15);// Enable channel 15 on an update trigger
    GTM_TOM0_TGC1_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL15);
    GTM_TOM0_TGC1_OUTEN_CTRL &= ~((0x3) << OUTEN_CTRL15);// Enable channel 15 output on an update trigger
    GTM_TOM0_TGC1_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL15);

    GTM_TOM0_CH15_CTRL |= (1 << SL);                     // High signal level for duty cycle
    GTM_TOM0_CH15_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH15_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH15_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH15_SR1 = 0;                               // Duty cycle = 0
    GTM_TOUTSEL0 &= ~((0x3) << SEL7);                    // TOUT7 : TOM0 channel 3
    */

    // channel 11 (Buzzer)
    GTM_TOM0_TGC1_GLB_CTRL &= ~((0x3) << UPEN_CTRL3);   // TOM0 channel 11 enable update of
    GTM_TOM0_TGC1_GLB_CTRL |= ((0x2) << UPEN_CTRL3);    // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC1_FUPD_CTRL &= ~((0x3) << FUPD_CTRL3);  // Enable force update of TOM0 channel 11
    GTM_TOM0_TGC1_FUPD_CTRL |= ((0x2) << FUPD_CTRL3);
    GTM_TOM0_TGC1_FUPD_CTRL &= ~((0x3) << RSTCN0_CH3);  // Reset CN0 of TOM0 channel 11 on force update
    GTM_TOM0_TGC1_FUPD_CTRL |= ((0x2) << RSTCN0_CH3);
    GTM_TOM0_TGC1_ENDIS_CTRL &= ~((0x3) << ENDIS_CTRL3); // Enable channel 11 on an update trigger
    GTM_TOM0_TGC1_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL3);
    GTM_TOM0_TGC1_OUTEN_CTRL &= ~((0x3) << OUTEN_CTRL3); // Enable channel 11 output on an update trigger
    GTM_TOM0_TGC1_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL3);

    GTM_TOM0_CH11_CTRL |= (1 << SL);                    // High signal level for duty cycle
    GTM_TOM0_CH11_CTRL &= ~((0x7) << CLK_SRC_SR);       // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH11_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH11_SR0 = 12500 - 1;                      // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH11_SR1 = 0;                              // Duty cycle = 0
    GTM_TOUTSEL0 &= ~((0x3) << SEL3);                   // TOUT3 : TOM0 channel 11



    GTM_TOM0_TGC0_GLB_CTRL |= (1 << HOST_TRIG);         // Trigger request signal to update
    GTM_TOM0_TGC1_GLB_CTRL |= (1 << HOST_TRIG);         // Trigger request signal to update
}

void init_CCU60(void)
{
    /* CCU60 T12 Setting */

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    CCU60_CLC &= ~(1 << DISR);                  // Enable CCU60 Module

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((CCU60_CLC & (1 << DISS)) != 0);       // Wait until module is enabled

    CCU60_TCTR0 &= ~((0x7) << T12CLK);           // f_T12 = f_CCU6 / prescaler
    CCU60_TCTR0 |= (1 << T12CLK);                // F_CCU6 = 100 MHz, prescaler = 2
    CCU60_TCTR0 &= ~(1 << T12PRE);               // f_T12 = 50 MHz

    CCU60_TCTR0 &= ~(1 << CTM);                  // T12 always counts up and continues counting
                                                 // from zero after reaching the period value

    CCU60_T12PR = 500 - 1;                       // Interrupt freq. = f_T12 / (period value + 1)
    CCU60_TCTR4 |= (1 << T12STR);                // Interrupt freq. = 100 kHz (10 us)

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

void init_CCU61(int ms)
{
    /* CCU60 T12 Setting */

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    CCU61_CLC &= ~(1 << DISR);                     // Enable CCU61 Module

    /* Password Access to unlock WDTSCON0 */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    /* Modify Access to clear ENDINIT bit */
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((CCU61_CLC & (1 << DISS)) != 0);       // Wait until module is enabled

    CCU61_TCTR0 &= ~((0x7) << T12CLK);           // f_T12 = f_CCU6 / prescaler, 100MHz
    CCU61_TCTR0 |= ((0x3) << T12CLK);            // F_CCU6 = 100 MHz, prescaler = 2048
    CCU61_TCTR0 |= (1 << T12PRE);                // f_T12 = 48828 Hz

    CCU61_TCTR0 &= ~(1 << CTM);                  // T12 always counts up and continues counting
                                                 // from zero after reaching the period value

    // FIXME: 0.5s -> ms
    CCU61_T12PR = ((48828*ms)/1000) - 1;         // Interrupt freq. = f_T12 / (period value  + 1)
    CCU61_TCTR4 |= (1 << T12STR);                // Interrupt freq. = 2 Hz

    CCU61_T12 = 0;                               // Clear T12 counting value

    /* CCU6 T12 Interrupt Setting */
    CCU61_INP &= ~((0x3) << INPT12);             // Service Request output SR0 is selected

    CCU61_IEN |= (1 << ENT12PM);                 // Enable Interrupt for T12 Period-Match

    SRC_CCU61_SR0 &= ~((0xFF) << SRPN);           // Set Priority
    SRC_CCU61_SR0 |= (0x0C << SRPN);
    SRC_CCU61_SR0 &= ~((0x3) << TOS);             // CPU0 services
    SRC_CCU61_SR0 |= (1 << SRE);                  // Service Request is enabled

    /* CCU6 T12 Start */
    CCU61_TCTR4 = (1 << T12RS);                  // T12 starts counting
}

void init_ultrasonic(void)
{
    /* Init TRIG Pin - P15.4 (Output) */
    PORT15_IOCR4 &= ~((0x1F) << PC4);
    PORT15_IOCR4 |= ((0x10) << PC4);

    /* Init ECHO Pin - P15.5 (Input) */
    PORT15_IOCR4 &= ~((0x1F) << PC5);
}


void init_Buzzer(void)
{
    PORT02_IOCR0 &= ~((0x1F) << PC3);           // PORT02.3 : Alternate output function 1 (push-pull)
    PORT02_IOCR0 |= ((0x11) << PC3);            // PORT02.3 : GTM_TOUT3
}
