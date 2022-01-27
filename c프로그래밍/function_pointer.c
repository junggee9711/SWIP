// 함수 포인터
// : 함수의 주소를 가지는 포인터 변수

#include <stdio.h>

int add(int a, int b) { return a + b; }
// TEXT 영역에 로드됩니다.
// => 주소를 가집니다.

int main()
{
    int a = 10;
    int* p = &a;

    int (*fp)(int, int);
    fp = &add; // !
    fp = add;

    int result = (*fp)(10, 20); // !
    result = fp(10, 20);

    printf("%d\n", result);

    printf("%p\n", &add); // 0x100323f3c

    return 0;
}