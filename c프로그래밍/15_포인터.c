#include <stdio.h>

// 1. 포인터는 다른 함수에서 변수의 값을 변경하기 위해서
//    사용합니다.
// => 근본적인 포인터의 필요성

// 2. 포인터 활용
//  : 배열과 포인터
//    함수 포인터

void foo(int a)
{
    a = 30;
    printf("foo: %d\n", a);
}

int main()
{
    int a = 10;

    // a = 20;
    printf("main: %d\n", a);
    foo(a);
    printf("main: %d\n", a);
}