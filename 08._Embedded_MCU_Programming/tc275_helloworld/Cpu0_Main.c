/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

#include <stdio.h>
#include <my_lib.h>
#include <string.h>

IfxCpu_syncEvent g_cpuSyncEvent = 0;

unsigned int systemtick[4];
volatile int checksum_0;
volatile int checksum_1;

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

    // 1) CPU0, CPU1 의 Scratch-Pad RAM 주소 데이터를 읽는데 걸리는 시간 비교
    // CPU0 에서 CPU0 Data Scratch-Pad RAM 주소에 접근하여 data 를 읽어 오는데 걸리는 시간
    systemtick[0] = SYSTEM_TIMER_31_0;
    checksum_0 = 0;
    for (int i = 0; i<0x2000; i++)
        checksum_0 += *((volatile int *)0x70008000+i);
    systemtick[1] = SYSTEM_TIMER_31_0;

    // CPU0 에서 CPU1 Data Scratch-Pad RAM 주소에 접근하여 data 를 읽어 오는데 걸리는 시간
    systemtick[2] = SYSTEM_TIMER_31_0;
    checksum_1 = 0;
     for (int i = 0; i<0x2000; i++)
         checksum_1 += *((volatile int *)0x60008000+i);
    systemtick[3] = SYSTEM_TIMER_31_0;

    printf("0x7000 access @ cpu0 : %d\n", systemtick[1]-systemtick[0]);
    printf("0x7000 access @ cpu0 : %d\n", systemtick[3]-systemtick[2]);

    // 2) CPU0, CPU1 의 Scratch-Pad RAM 주소 데이터를 memcpy 하는데 걸리는 시간 비교
    systemtick[0] = SYSTEM_TIMER_31_0;
    memcpy((char*)0x70008000, (char*)0x70008000, 0x8000);
    systemtick[1] = SYSTEM_TIMER_31_0;

    systemtick[2] = SYSTEM_TIMER_31_0;
    memcpy((char*)0x60008000, (char*)0x60008000, 0x8000);
    systemtick[3] = SYSTEM_TIMER_31_0;

    printf("0x7000 memcpy @ cpu0 : %d\n", systemtick[1]-systemtick[0]);
    printf("0x7000 memcpy @ cpu0 : %d\n", systemtick[3]-systemtick[2]);

    /*
     * CPU 의 처리과정에서 CPU 내부의 연산은 시간이 오래 걸리지 않고,
     * 다른 메모리 (Scratch-Pad, Cache 등) 에서 register 로 값을 load/store 하는데 시간이 오래 걸림
     * -> 이때, 값을 불러와서 checksum 에 더하는 경우는 ld/st 횟수가 1회지만,
     *    memcpy 는 매 for loop 마다 ld/st 횟수가 많게 구현 되기 때문에
     *    1) 보다 2) 에서 Timer 의 차이가 많이 난다
     */

    /*
    systemtick_0 = SYSTEM_TIMER_0_31_0;
    printf("Hello, World!\n");
    systemtick_1 = SYSTEM_TIMER_0_31_0;

    printf("systemtick_0 : %d\n", systemtick_0);
    printf("systemtick_1 : %d\n", systemtick_1);
    printf("system clock : %d\n", systemtick_1 - systemtick_0);
    */

    test_my_print();

    while(1)
    {
    }
    return (1);
}
