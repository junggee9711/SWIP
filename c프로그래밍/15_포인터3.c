#include <stdio.h>

// 1. 포인터 타입의 변수에 정수값을 대입하는 것은 오류 입니다.
// warning: incompatible integer to pointer conversion assigning to 'int *' from 'int'

// 2. 참조하는 변수(대상체)의 타입이 동일하면,
//    포인터 타입도 동일합니다.

int main()
{
    int num1 = 10;
    int num2 = 20;

    int* pnum = &num1;

    // pnum = 20; // error!
    *pnum = 20;

    pnum = &num2; // ok
    *pnum = 200;

    printf("%d\n", num1); // 20
    printf("%d\n", num2); // 200

    printf("%p\n", &num1); // 0x16d97b1fc
    printf("%p\n", &num2); // 0x16d97b1f8
    printf("%p\n", pnum); // 0x16d97b1f8

    printf("%d\n", *pnum); // 200

    return 0;
}