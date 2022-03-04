/*
 * my_lib.h
 *
 *  Created on: 2022. 3. 4.
 *      Author: user
 */

#ifndef MY_LIB_H_
#define MY_LIB_H_

#endif /* MY_LIB_H_ */

/* SCU Registers */
#define SCU_BASE            (0xF0036000)
#define SCU_WDT_CPU0CON0     (*(volatile unsigned int*)(SCU_BASE + 0x100))

#define SYSTEM_TIMER_0_31_0 *(unsigned int *)(0xF0000000+0x10)

#define LCK                 1
#define ENDINIT             0

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

#define CCU61_BASE          (0xF0002B00)

typedef struct CCU6 {
    unsigned int CLC;
    unsigned int REG_04_1C[(0x20-0x04)/4];      // 0x04 ~ 0x1C
    unsigned int T12;                           // 0x20
    unsigned int T12PR;                         // 0x24
    unsigned int REG_28_6C[(0x70-0x28)/4];      // 0x28 ~ 0x6C
    unsigned int TCTR0;                         // 0x70
    unsigned int REG_74;                        // 0x74
    unsigned int TCTR4;                         // 0x78
    unsigned int REG_7C_A8[(0xAC-0x7C)/4];      // 0x7C ~ 0xA8
    unsigned int INP;                           // 0xAC
    unsigned int IEN;                           // 0xB0
} myCCU6;

#define CCU60 (*(volatile myCCU6 *)CCU60_BASE)
#define CCU61 (*(volatile myCCU6 *)CCU61_BASE)
// FIXME: add CCU61

#define DISS                1
#define DISR                0
#define CTM                 7
#define T12PRE              3
#define T12CLK              0
#define T12STR              6
#define T12RS               1
#define INPT12              10
#define ENT12PM             7

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

void init_LED(void);
void init_CCU6(myCCU6 *CCU6, int ms, int int_priority);
