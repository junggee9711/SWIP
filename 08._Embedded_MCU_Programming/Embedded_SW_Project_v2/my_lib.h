/* Address of Registers */
#define SYSTEM_TIMER_0_31_0 *(volatile unsigned int *)(0xF0000000+0x10)

// SCU Registers
#define SCU_BASE        (0xF0036000)
#define SCU_WDT_CPU0CON0 (*(volatile unsigned int*)(SCU_BASE + 0x100))

#define LCK             1
#define ENDINIT         0

// GTM Registers
// GTM - CMU
#define GTM_BASE                    (0xF0100000)
#define GTM_CMU_CLK_EN              (*(volatile unsigned int*)(GTM_BASE + 0x00300))
#define GTM_CMU_FXCLK_CTRL          (*(volatile unsigned int*)(GTM_BASE + 0x00344))

#define EN_FXCLK                    22
#define FXCLK_SEL                   0

// GTM - TOM0 TGC0
#define GTM_TOM0_TGC0_GLB_CTRL      (*(volatile unsigned int*)(GTM_BASE + 0x08030))
#define GTM_TOM0_TGC0_ENDIS_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08070))
#define GTM_TOM0_TGC0_OUTEN_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08078))
#define GTM_TOM0_TGC0_FUPD_CTRL     (*(volatile unsigned int*)(GTM_BASE + 0x08038))

#define GTM_TOM0_CH1_CTRL           (*(volatile unsigned int*)(GTM_BASE + 0x08040))
#define GTM_TOM0_CH1_SR0            (*(volatile unsigned int*)(GTM_BASE + 0x08044))
#define GTM_TOM0_CH1_SR1            (*(volatile unsigned int*)(GTM_BASE + 0x08048))

#define GTM_TOM0_CH2_CTRL           (*(volatile unsigned int*)(GTM_BASE + 0x08080))
#define GTM_TOM0_CH2_SR0            (*(volatile unsigned int*)(GTM_BASE + 0x08084))
#define GTM_TOM0_CH2_SR1            (*(volatile unsigned int*)(GTM_BASE + 0x08088))

#define GTM_TOM0_CH3_CTRL           (*(volatile unsigned int*)(GTM_BASE + 0x080C0))
#define GTM_TOM0_CH3_SR0            (*(volatile unsigned int*)(GTM_BASE + 0x080C4))
#define GTM_TOM0_CH3_SR1            (*(volatile unsigned int*)(GTM_BASE + 0x080C8))

#define GTM_TOM0_CH11_CTRL          (*(volatile unsigned int*)(GTM_BASE + 0x082C0))
#define GTM_TOM0_CH11_SR0           (*(volatile unsigned int*)(GTM_BASE + 0x082C4))
#define GTM_TOM0_CH11_SR1           (*(volatile unsigned int*)(GTM_BASE + 0x082C8))

// GTM - TOM0 TGC1
#define GTM_TOM0_TGC1_GLB_CTRL      (*(volatile unsigned int*)(GTM_BASE + 0x08230))
#define GTM_TOM0_TGC1_ENDIS_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08270))
#define GTM_TOM0_TGC1_OUTEN_CTRL    (*(volatile unsigned int*)(GTM_BASE + 0x08278))
#define GTM_TOM0_TGC1_FUPD_CTRL     (*(volatile unsigned int*)(GTM_BASE + 0x08238))

#define GTM_TOM0_CH15_CTRL          (*(volatile unsigned int*)(GTM_BASE + 0x083C0))
#define GTM_TOM0_CH15_SR0           (*(volatile unsigned int*)(GTM_BASE + 0x083C4))
#define GTM_TOM0_CH15_SR1           (*(volatile unsigned int*)(GTM_BASE + 0x083C8))

#define HOST_TRIG                   0

#define UPEN_CTRL1                  18
#define ENDIS_CTRL1                 2
#define OUTEN_CTRL1                 2
#define RSTCN0_CH1                  18
#define FUPD_CTRL1                  2

#define UPEN_CTRL2                  20
#define ENDIS_CTRL2                 4
#define OUTEN_CTRL2                 4
#define RSTCN0_CH2                  20
#define FUPD_CTRL2                  4

#define UPEN_CTRL3                  22
#define ENDIS_CTRL3                 6
#define OUTEN_CTRL3                 6
#define RSTCN0_CH3                  22
#define FUPD_CTRL3                  6


#define UPEN_CTRL15                 30
#define ENDIS_CTRL15                14
#define OUTEN_CTRL15                14
#define RSTCN0_CH15                 30
#define FUPD_CTRL15                 14

#define CLK_SRC_SR                  12
#define SL                          11

// GTM
#define GTM_CLC                     (*(volatile unsigned int*)(GTM_BASE + 0x9FD00))
#define GTM_TOUTSEL0                (*(volatile unsigned int*)(GTM_BASE + 0x9FD30))
#define GTM_TOUTSEL6                (*(volatile unsigned int*)(GTM_BASE + 0x9FD48))

#define DISS                        1
#define DISR                        0

#define SEL3                        6           // (Buzzer) TOUT3
#define SEL7                        14          // TOUT103 - LED RED   (Pin D12)
#define SEL8                        16          // TOUT104 - LED BLUE  (Pin D13)
#define SEL9                        18          // TOUT105  10.3 - RGB LED R
#define SEL10                       20          // TOUT106       - RGB LED G
#define SEL11                       22          // TOUT107  10.5 - RGB LED B

// PORT10 Registers
#define PORT10_BASE     (0xF003B000)
#define PORT10_IOCR0    (*(volatile unsigned int*)(PORT10_BASE + 0x10))
#define PORT10_IOCR1    (*(volatile unsigned int*)(PORT10_BASE + 0x14))

#define PC0             3
#define PC1             11
#define PC2             19
#define PC3             27
#define PC4             3
#define PC5             11

#define SYSTICK_100MHZ  1000000000



#define LCK                 1
#define ENDINIT             0

/* VADC Registers */
#define VADC_BASE       (0xF0020000)
#define VADC_CLC        (*(volatile unsigned int*)(VADC_BASE + 0x000))
#define VADC_GLOBCFG    (*(volatile unsigned int*)(VADC_BASE + 0x080))
#define VADC_G4ARBCFG   (*(volatile unsigned int*)(VADC_BASE + 0x1480))
#define VADC_G4ARBPR    (*(volatile unsigned int*)(VADC_BASE + 0x1484))
#define VADC_G4ICLASS0  (*(volatile unsigned int*)(VADC_BASE + 0x14A0))
#define VADC_G4QMR0     (*(volatile unsigned int*)(VADC_BASE + 0x1504))
#define VADC_G4QINR0    (*(volatile unsigned int*)(VADC_BASE + 0x1510))
#define VADC_G4CHCTR6   (*(volatile unsigned int*)(VADC_BASE + 0x1618))
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

#define light_sensor_min 2000
#define light_sensor_max 3600


/* Define PORT10 Registers for LED */
#define PORT10_BASE     (0xF003B000)
#define PORT10_IOCR0    (*(volatile unsigned int*)(PORT10_BASE + 0x10))
#define PORT10_OMR      (*(volatile unsigned int*)(PORT10_BASE + 0x04))

#define PC0             3
#define PC1             11
#define PC2             19

#define PCL1            17
#define PCL2            18
#define PS1             1
#define PS2             2

/* Define PORT02 Registers for Switch2 */
#define PORT02_BASE     (0xF003A200)
#define PORT02_IOCR0    (*(volatile unsigned int*)(PORT02_BASE + 0x10))
#define PORT02_IOCR1    (*(volatile unsigned int*)(PORT02_BASE + 0x14))
#define PORT02_IN       (*(volatile unsigned int*)(PORT02_BASE + 0x24))

#define P0              0
#define P1              1

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


////////////////////////////// Timer setting /////////////////////////////////////////
/* SRC Registers */
#define SRC_BASE            (0xF0038000)
#define SRC_CCU60_SR0        (*(volatile unsigned int*)(SRC_BASE + 0x420))
#define SRC_CCU61_SR0        (*(volatile unsigned int*)(SRC_BASE + 0x430))

#define TOS                 11
#define SRE                 10
#define SRPN                0

/* CCU60 Registers */
#define CCU60_BASE          (0xF0002A00)
#define CCU60_CLC           (*(volatile unsigned int*)(CCU60_BASE + 0x00))
#define CCU60_T12           (*(volatile unsigned int*)(CCU60_BASE + 0x20))
#define CCU60_T12PR         (*(volatile unsigned int*)(CCU60_BASE + 0x24))
#define CCU60_TCTR0         (*(volatile unsigned int*)(CCU60_BASE + 0x70))
#define CCU60_TCTR4         (*(volatile unsigned int*)(CCU60_BASE + 0x78))
#define CCU60_INP           (*(volatile unsigned int*)(CCU60_BASE + 0xAC))
#define CCU60_IEN           (*(volatile unsigned int*)(CCU60_BASE + 0xB0))

/* CCU61 Registers */
#define CCU61_BASE          (0xF0002B00)
#define CCU61_CLC           (*(volatile unsigned int*)(CCU61_BASE + 0x00))
#define CCU61_T12           (*(volatile unsigned int*)(CCU61_BASE + 0x20))
#define CCU61_T12PR         (*(volatile unsigned int*)(CCU61_BASE + 0x24))
#define CCU61_TCTR0         (*(volatile unsigned int*)(CCU61_BASE + 0x70))
#define CCU61_TCTR4         (*(volatile unsigned int*)(CCU61_BASE + 0x78))
#define CCU61_INP           (*(volatile unsigned int*)(CCU61_BASE + 0xAC))
#define CCU61_IEN           (*(volatile unsigned int*)(CCU61_BASE + 0xB0))

#define DISS                1
#define DISR                0
#define CTM                 7
#define T12PRE              3
#define T12CLK              0
#define T12STR              6
#define T12RS               1
#define INPT12              10
#define ENT12PM             7


///////////////////////////////////////////////////////////////////////////////////

/* Define PORT10 Registers for LED */
#define PORT10_BASE     (0xF003B000)
#define PORT10_IOCR0    (*(volatile unsigned int*)(PORT10_BASE + 0x10))
#define PORT10_OMR      (*(volatile unsigned int*)(PORT10_BASE + 0x04))

#define PC0             3
#define PC1             11
#define PC2             19

#define PCL1            17
#define PCL2            18
#define PS1             1
#define PS2             2

// PORT02 Registers
#define PORT02_BASE     (0xF003A200)
#define PORT02_IOCR0    (*(volatile unsigned int*)(PORT02_BASE + 0x10))

#define PC3             27
#define PWM_FREQ        6250000

/* for Interrupt service */
/////////////////////////////////////////////////
// SCU Registers
#define SCU_EICR1       (*(volatile unsigned int*)(SCU_BASE + 0x214))
#define SCU_WDTSCON0    (*(volatile unsigned int*)(SCU_BASE + 0x0f0))
#define SCU_IGCR0       (*(volatile unsigned int*)(SCU_BASE + 0x22C))
#define SCU_EICR2           (*(volatile unsigned int*)(SCU_BASE + 0x218))
#define SCU_IGCR0           (*(volatile unsigned int*)(SCU_BASE + 0x22C))
#define SCU_IGCR1           (*(volatile unsigned int*)(SCU_BASE + 0x230))

#define LCK             1
#define ENDINIT         0
#define INP0            12
#define EIEN0           11
#define REN0            9
#define FEN0            8
#define EXIS0           4
#define IGP0            14

#define INP1            28
#define EIEN1           27
#define FEN1            24
#define EXIS1           20
#define IGP1            30

// SRC Registers
#define SRC_SCUERU0     (*(volatile unsigned int*)(SRC_BASE + 0xCD4))
#define SRC_SCUERU1     (*(volatile unsigned int*)(SRC_BASE + 0xCD4 + 0x4))

#define TOS             11
#define SRE             10
#define SRPN            0

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


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define IDLE 0
#define PARK 1
#define DRIVE 2
#define REVERSE 3

#define DELAY_125MS 2083333
#define DELAY_250MS 4166666
#define DELAY_1S 16000000

/* Function Prototype */
void init_Switch(void);
void init_LED(void);
void init_LED_start(void);
void init_LED_RGB(void);
void init_ERU(void);
void init_GTM_TOM0_PWM_RGB(void);
void init_VADC(void);
unsigned int GetVADC4(int channel);
void init_CCU60(void);
void init_CCU61(int ms);
void init_ultrasonic(void);
void init_Buzzer(void);
void init_GTM_TOM0_PWM(void);
