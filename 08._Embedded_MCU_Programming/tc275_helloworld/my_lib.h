/*
 * my_lib.h
 *
 *  Created on: 2022. 3. 2.
 *      Author: user
 */

#ifndef MY_LIB_H_
#define MY_LIB_H_
#endif /* MY_LIB_H_ */

#define SYSTEM_TIMER_31_0 *(unsigned int *)(0xF0000000+0x10);
// "0xF0000000(Base Add.)+0x10(Offset Add.)" = CPU0 의 Timer 값의 주소 이므로 int point 로 cast 해주고,
// 이 주소에 있는 Timer 값을 가져오고 싶기 때문에 * 로 값을 가져옴
// volatile 을 적어주는 이유는, 해당 메모리가 CPU0 만 쓰는 것이 아니라, 다른 Peri 등도 사용하기 때문에,
// 컴파일러가 다른 Peri 가 접근한 것에 대해 최적화 하지 않도록 하기 위한 것

void test_my_print(void);
