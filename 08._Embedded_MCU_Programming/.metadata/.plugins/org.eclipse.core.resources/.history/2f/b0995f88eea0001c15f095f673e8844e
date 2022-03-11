
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

/* Address of Registers */

/* SCU Registers */
#define SCU_BASE            (0xF0036000)
#define SCU_WDTSCON0        (*(volatile unsigned int*)(SCU_BASE + 0x0F0))
#define SCU_WDT_CPU0CON0    (*(volatile unsigned int*)(SCU_BASE + 0x100))
#define SCU_EICR2           (*(volatile unsigned int*)(SCU_BASE + 0x218))
#define SCU_IGCR0           (*(volatile unsigned int*)(SCU_BASE + 0x22C))

#define LCK                 1
#define ENDINIT             0
#define INP0                12
#define EIEN0               11
#define REN0                9
#define FEN0                8
#define EXIS0               4
#define IGP0                14

/* SRC Registers */
#define SRC_BASE            (0xF0038000)
#define SRC_CCU60_SR0       (*(volatile unsigned int*)(SRC_BASE + 0x420))
#define SRC_SCUERU0         (*(volatile unsigned int*)(SRC_BASE + 0xCD4))

#define TOS                 11
#define SRE                 10
#define SRPN                0


// GTM Registers
// GTM - CMU
#define GTM_BASE                    (0xF0100000)
#define GTM_CMU_CLK_EN              (*(volatile unsigned int*)(GTM_BASE + 0x00300))
#define GTM_CMU_FXCLK_CTRL          (*(volatile unsigned int*)(GTM_BASE + 0x00344))

#define EN_FXCLK                    22
#define FXCLK_SEL                   0

// GTM - TOM0
#define GTM_TOM0_TGC1_GLB_CTRL      (*(volatile unsigned int*)(GTM_BASE + 0x08230))
#define GTM_TOM0_TGC1_ENDIS_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08270))
#define GTM_TOM0_TGC1_OUTEN_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08278))
#define GTM_TOM0_TGC1_FUPD_CTRL     (*(volatile unsigned int*)(GTM_BASE + 0x08238))
#define GTM_TOM0_CH11_CTRL          (*(volatile unsigned int*)(GTM_BASE + 0x082C0))
#define GTM_TOM0_CH11_SR0           (*(volatile unsigned int*)(GTM_BASE + 0x082C4))
#define GTM_TOM0_CH11_SR1           (*(volatile unsigned int*)(GTM_BASE + 0x082C8))

#define UPEN_CTRL3                  22
#define HOST_TRIG                   0
#define ENDIS_CTRL3                 6
#define OUTEN_CTRL3                 6
#define RSTCN0_CH3                  22
#define FUPD_CTRL3                  6
#define CLK_SRC_SR                  12
#define SL                          11

// GTM
#define GTM_CLC                     (*(volatile unsigned int*)(GTM_BASE + 0x9FD00))
#define GTM_TOUTSEL0                (*(volatile unsigned int*)(GTM_BASE + 0x9FD30))

#define SEL3                        6

/* CCU60 Registers */
#define CCU60_BASE          (0xF0002A00)
#define CCU60_CLC           (*(volatile unsigned int*)(CCU60_BASE + 0x00))
#define CCU60_T12           (*(volatile unsigned int*)(CCU60_BASE + 0x20))
#define CCU60_T12PR         (*(volatile unsigned int*)(CCU60_BASE + 0x24))
#define CCU60_TCTR0         (*(volatile unsigned int*)(CCU60_BASE + 0x70))
#define CCU60_TCTR4         (*(volatile unsigned int*)(CCU60_BASE + 0x78))
#define CCU60_INP           (*(volatile unsigned int*)(CCU60_BASE + 0xAC))
#define CCU60_IEN           (*(volatile unsigned int*)(CCU60_BASE + 0xB0))


#define DISS                1
#define DISR                0
#define CTM                 7
#define T12PRE              3
#define T12CLK              0
#define T12STR              6
#define T12RS               1
#define INPT12              10
#define ENT12PM             7

// PORT02 Registers
#define PORT02_BASE     (0xF003A200)
#define PORT02_IOCR0    (*(volatile unsigned int*)(PORT02_BASE + 0x10))


/* Define PORT15 Registers for Ultrasonic */
#define PORT15_BASE     (0xF003B500)
#define PORT15_OMR      (*(volatile unsigned int*)(PORT15_BASE + 0x04))
#define PORT15_IOCR4    (*(volatile unsigned int*)(PORT15_BASE + 0x14))
#define PORT15_IN       (*(volatile unsigned int*)(PORT15_BASE + 0x24))

#define PCL4            20
#define PS4             4
#define PC5             11
#define PC4             3
#define P5              5

#define PC3             27

/* Function Prototype */
void init_Buzzer(void);
void init_GTM_TOM0_PWM(void);

IfxCpu_syncEvent g_cpuSyncEvent = 0;

#define PWM_FREQ        6250000

int num_tones = 8;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392}; // 8


////////////////////////////////////////////////////////////////////////////////////

/* Function Prototype */
void init_ultrasonic(void);
void init_ERU(void);
void init_CCU60(void);


volatile unsigned int timer_cnt;
volatile unsigned int start_time;
volatile unsigned int end_time;
volatile unsigned int interval_time;
volatile unsigned int distance;
volatile unsigned char irq_ultra_sensor;

#define duration        50000000
volatile unsigned int   period = 1;

int read_data = 0;
// ============= VADC_oil ===========================

/* SCU Registers */
//#define SCU_BASE            (0xF0036000)
//#define SCU_WDT_CPU0CON0    (*(volatile unsigned int*)(SCU_BASE + 0x100))

//#define LCK                 1
//#define ENDINIT             0

/* VADC Registers */
#define VADC_BASE       (0xF0020000)
#define VADC_CLC        (*(volatile unsigned int*)(VADC_BASE + 0x000))
#define VADC_GLOBCFG    (*(volatile unsigned int*)(VADC_BASE + 0x080))
#define VADC_G4ARBCFG   (*(volatile unsigned int*)(VADC_BASE + 0x1480))
#define VADC_G4ARBPR    (*(volatile unsigned int*)(VADC_BASE + 0x1484))
#define VADC_G4ICLASS0  (*(volatile unsigned int*)(VADC_BASE + 0x14A0))
#define VADC_G4QMR0     (*(volatile unsigned int*)(VADC_BASE + 0x1504))
#define VADC_G4QINR0    (*(volatile unsigned int*)(VADC_BASE + 0x1510))
#define VADC_G4CHCTR7   (*(volatile unsigned int*)(VADC_BASE + 0x161C))
#define VADC_G4RES1     (*(volatile unsigned int*)(VADC_BASE + 0x1704))

#define DISS            1
#define DISR            0
#define ANONC           0
#define ASEN0           24
#define CSM0            3
#define PRIO0           0
#define CMS             8
#define STCS            0
#define FLUSH           10
#define TREV            9
#define ENGT            0
#define RF              5
#define REQCHNR         0
#define RESPOS          21
#define RESREG          16
#define ICLSEL          0
#define VF              31
#define RESULT          0

/* Define PORT02/10 Registers for RGB LED */
#define PORT02_BASE     (0xF003A200)
#define PORT02_IOCR4    (*(volatile unsigned int*)(PORT02_BASE + 0x14))
#define PORT02_OMR      (*(volatile unsigned int*)(PORT02_BASE + 0x04))

#define PC7             27
#define PCL7            23
#define PS7             7

#define PORT10_BASE     (0xF003B000)
#define PORT10_IOCR4    (*(volatile unsigned int*)(PORT10_BASE + 0x14))
#define PORT10_IOCR0    (*(volatile unsigned int*)(PORT10_BASE + 0x10))
#define PORT10_OMR      (*(volatile unsigned int*)(PORT10_BASE + 0x04))

#define PC5             11
#define PC3             27
#define PCL5            21
#define PCL3            19
#define PS5             5
#define PS3             3

/********Comunication********/
#define POR15_BASE      (0xF003B500)
#define PORT15_IOCR0    (*(volatile unsigned int*)(PORT15_BASE + 0x0010))
#define PORT15_OMR      (*(volatile unsigned int*)(PORT15_BASE + 0x0004))
#define PORT15_IN       (*(volatile unsigned int*)(PORT15_BASE + 0x0024))

#define PC3             27
#define PC2             19
#define PCL3            19
#define PS3             3
#define PCL2            18
#define PS2             2
#define P3              3
#define P2              2
#define MIN_DIST     5
#define MAX_DIST     100


void init_RGBLED(void);
void init_VADC(void);
void VADC_startConversion(void);
unsigned int VADC_readResult(void);
void initSerialInterface(void);

int core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    irq_ultra_sensor = 0;

    /* Initialization */
    init_ultrasonic();
    init_ERU();
    init_CCU60();
    initSerialInterface();
    
    init_Buzzer();
    init_GTM_TOM0_PWM();

    /* Initialization */

    unsigned int adcResult;
    init_RGBLED();              // Initialize PORT
    init_VADC();                // Initialize VADC


    while(1)
    {
        if ((PORT15_IN & (1<<P2)) == (1 << P2))
        {
            read_data = 2;
            // Buzzer
            int pwm_cnt = PWM_FREQ / tones[4];

            GTM_TOM0_CH11_SR0 = pwm_cnt;
            GTM_TOM0_CH11_SR1 = pwm_cnt / 2;

            /*
            period = 8;
            GTM_CMU_CLK_EN |= ((0x2) <<EN_FXCLK);
            for(int j = 0 ; j < duration/period ; j++);
            GTM_TOM0_CH11_SR1 = 0;
            */


            // ultra_sensor
            irq_ultra_sensor = 0;
            while( irq_ultra_sensor == 0 );

            if(distance < MIN_DIST)
                distance = MIN_DIST;
            if(distance > MAX_DIST)
                distance = MAX_DIST;


            if(distance >= 60)
            {
                GTM_CMU_CLK_EN &= ~ ((0x2) <<EN_FXCLK); // disable
                GTM_TOM0_CH11_SR1 = 0;
            }
            else if(distance >= 30 && distance < 60)
            {
                pwm_cnt = PWM_FREQ / tones[0];
                GTM_TOM0_CH11_SR1 = pwm_cnt / 2;
                period = 15;
                GTM_CMU_CLK_EN |= ((0x2) <<EN_FXCLK);
                for(int j = 0 ; j < duration/period ; j++);
                GTM_TOM0_CH11_SR1 = 0;
            }
            else if(distance >= 15 && distance < 30)
            {
                pwm_cnt = PWM_FREQ / tones[4];
                GTM_TOM0_CH11_SR1 = pwm_cnt / 2;
                period = 40;
                GTM_CMU_CLK_EN |= ((0x2) <<EN_FXCLK);
                for(int j = 0 ; j < duration/period ; j++);
                GTM_TOM0_CH11_SR1 = 0;
            }
            else if(distance >= 5 && distance < 15)
            {
                pwm_cnt = PWM_FREQ / tones[6];
                GTM_TOM0_CH11_SR1 = pwm_cnt / 2;
                period = 80000;
                GTM_CMU_CLK_EN |= ((0x2) <<EN_FXCLK);
                for(int j = 0 ; j < duration/period ; j++);
                GTM_TOM0_CH11_SR1 = 0;
            }
            else
            {
                pwm_cnt = PWM_FREQ / tones[6];
                GTM_TOM0_CH11_SR1 = pwm_cnt / 2;
                period = 80000;
                GTM_CMU_CLK_EN |= ((0x2) <<EN_FXCLK);
                for(int j = 0 ; j < duration/period ; j++);
                GTM_TOM0_CH11_SR1 = 0;
            }


            for(int i=0; i<10; i++)
            {
                irq_ultra_sensor = 0;
                while( irq_ultra_sensor == 0 );
            } // 2 seconds waiting

            VADC_startConversion();

            adcResult = VADC_readResult();

            if(adcResult >= 3096)
            {
                PORT02_OMR |= (1<<PCL7);            // Clear LED RED
                PORT10_OMR |= (1<<PS5);             // Set LED GREEN
                PORT10_OMR |= (1<<PCL3);            // Clear LED BLUE
            }
            else if(adcResult >= 2048)
            {
                PORT02_OMR |= (1<<PS7);             // Set LED RED
                PORT10_OMR |= (1<<PS5);             // Set LED GREEN
                PORT10_OMR |= (1<<PCL3);             // Set LED BLUE
            }
            else if(adcResult >= 1024)
            {
                PORT02_OMR |= (1<<PS7);            // Set LED RED
                PORT10_OMR |= (1<<PCL5);           // Clear LED GREEN
                PORT10_OMR |= (1<<PCL3);           // Clear LED BLUE
            }
            else
            {
                PORT02_OMR |= (1<<PS7);            // Set LED RED
                PORT10_OMR |= (1<<PCL5);           // Clear LED GREEN
                PORT10_OMR |= (1<<PCL3);           // Clear LED BLUE
            }
        }

        else if ((PORT15_IN & (1<<P2)) == (0 << P2))
        {
            read_data = 3;
        }

    }

    return (1);
}

__interrupt( 0x0A ) __vector_table( 0 )
void CCU60_T12_ISR(void)
{
    timer_cnt++;

    if(timer_cnt == 1)
    {
        /* Set TRIG Pin */
        PORT15_OMR |= (1<<PS4);
    }
    else if(timer_cnt == 2)
    {
        /* Clear TRIG Pin */
        /* Generate 10us Pulse */
        PORT15_OMR |= (1<<PCL4);
    }
    else if(timer_cnt == 5000)
    {
        /* TRIG Period: 100ms */
        timer_cnt = 0;
    }
}

__interrupt( 0x0B ) __vector_table( 0 )
void ERU0_ISR(void)
{
    if((PORT15_IN & (1<<P5)) == 0)              // Falling edge
    {
        /* Get distance */
        end_time = timer_cnt;

        // 10us
        interval_time = end_time - start_time;  // clock per 0.02us

        // 340m/s -> 340_00cm/s -> 340_00
        // 1us    -> 1000000/340_00 = 29
        // ToF(Time of Flight) = distance * 2
        // distance = ToF us / 58 cm
        // distance = ToF 10us / 5.8 cm
        // distance = ToF 10us 17/100 cm

        //distance = ((interval_time/2)*34000)/1000_00;    // cm
        distance = (interval_time*17)/100;      // cm
        irq_ultra_sensor = 1;
    }
    else                                        // Rising edge
    {
        start_time = timer_cnt;
    }
}

void initSerialInterface(void)
{
    PORT15_IOCR0 &= ~(0x1F << PC2);
    PORT15_IOCR0 &= ~(0x1F << PC3);
}

void init_ultrasonic(void)
{
    /* Init TRIG Pin - P15.4 (Output) */
    PORT15_IOCR4 &= ~((0x1F) << PC4);
    PORT15_IOCR4 |= ((0x10) << PC4);

    /* Init ECHO Pin - P15.5 (Input) */
    PORT15_IOCR4 &= ~((0x1F) << PC5);
}

void init_ERU(void)
{
    /* ERU Input Channel 4 Setting */
    /* Password Access to unlock WDTSCON0 */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    // Modify Access to clear ENDINIT bit
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    SCU_EICR2 &= ~((0x7) << EXIS0);             // External input 3 is selected
    SCU_EICR2 |= ((0x3) << EXIS0);

    SCU_EICR2 |= (1 << REN0);                   // Rising edge enable
    SCU_EICR2 |= (1 << FEN0);                   // Falling edge enable

    SCU_EICR2 |= (1 << EIEN0);                  // The trigger event is enabled

    SCU_EICR2 &= ~((0x7) << INP0);              // An event from input ETL 4 triggers output OGU 0

    SCU_IGCR0 &= ~((0x3) << IGP0);              // IOUT(0) is activated in response to a trigger event
    SCU_IGCR0 |= (1 << IGP0);                   // The pattern is not considered

    /* Password Access to unlock WDTSCON0 */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    /* Modify Access to set ENDINIT bit */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    /* SRC Interrupt Setting For ECU */
    SRC_SCUERU0 &= ~((0xFF) << SRPN);           // Set Priority : 0x0B
    SRC_SCUERU0 |= ((0x0B) << SRPN);

    SRC_SCUERU0 &= ~((0x3) << TOS);             // CPU0 services

    SRC_SCUERU0 |= (1 << SRE);                  // Service Request is enabled
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

// ================ Buzzer Code ===================
void init_Buzzer(void)
{
    PORT02_IOCR0 &= ~((0x1F) << PC3);           // PORT02.3 : Alternate output function 1 (push-pull)
    PORT02_IOCR0 |= ((0x11) << PC3);            // PORT02.3 : GTM_TOUT3

}

void init_GTM_TOM0_PWM(void)
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

    /* GTM TOM0 PWM Setting */
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

    GTM_TOM0_TGC1_GLB_CTRL |= (1 << HOST_TRIG);         // Trigger request signal to update
}

// ================= VADC ======================

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
