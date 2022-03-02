/*
 * my_lib.h
 *
 *  Created on: 2022. 3. 2.
 *      Author: user
 */

#ifndef MY_LIB_H_
#define MY_LIB_H_

#endif /* MY_LIB_H_ */

#define SYSTEM_TIMER_0_31_0 *(unsigned int *)(0xF0000000+0x10);
#define DELAY_250MS 4166666

#define PORT10_BASE     (0xF003B000)
#define PORT10_IOCR0    (*(volatile unsigned int*)(PORT10_BASE + 0x10))
#define PORT10_OMR      (*(volatile unsigned int*)(PORT10_BASE + 0x04))

#define PC1             11
#define PC2             19

#define PCL1            17
#define PCL2            18
#define PS1             1
#define PS2             2
