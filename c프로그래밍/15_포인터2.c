#include <stdio.h>

// 1. & 연산자를 통해 변수의 주소를 얻을 수 있습니다.
// 2. 포인터 변수를 통해 가르키는(참조하는) 변수의 값을
//    읽거나 변경하는 것이 가능합니다.
// 3. 참조 연산자(referencing operator)

int main()
{
    int num = 0;
    double d = 3.14;

    printf("%p\n", &num);
    // int* 포인터 변수: 주소 타입을 저장하기 위한 변수
    int* p = &num;

    double* p2 = &d;

    *p = 20;
    printf("%d\n", *p);
    printf("%d\n", num);

    return 0;
}