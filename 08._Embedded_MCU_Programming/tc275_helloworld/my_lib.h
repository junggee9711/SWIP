/*
 * my_lib.h
 *
 *  Created on: 2022. 3. 2.
 *      Author: user
 */

#ifndef MY_LIB_H_
#define MY_LIB_H_

#define SYSTEM_TIMER_31_0 *(unsigned int *)(0xF0000000+0x10);
// "0xF0000000(Base Add.)+0x10(Offset Add.)" = CPU0 �� Timer ���� �ּ� �̹Ƿ� int point �� cast ���ְ�,
// �� �ּҿ� �ִ� Timer ���� �������� �ͱ� ������ * �� ���� ������
// volatile �� �����ִ� ������, �ش� �޸𸮰� CPU0 �� ���� ���� �ƴ϶�, �ٸ� Peri � ����ϱ� ������,
// �����Ϸ��� �ٸ� Peri �� ������ �Ϳ� ���� ����ȭ ���� �ʵ��� �ϱ� ���� ��

#endif /* MY_LIB_H_ */