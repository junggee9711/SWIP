// 11_함수.c
#include <stdio.h>

// 함수의 목적?
// : 입력값을 받아서 주어진 연산을 수행한 후
//   결과를 반환하는 코드의 집합입니다.
#if 0
반환값타입 함수이름(함수인자열)
{
    함수 구현
        return 반환값;
}
#endif

int add(int a, int b) { return a + b; }

void print_number(int a)
{
    if (a < 0) {
        return;
    }

    printf("%d\n", a);
    printf("%x\n", a);
    printf("%o\n", a);

    // return; // void를 반환하는 방법.
}

// 인자로 전달된 n에 대해서 n-1까지의 합을 구하는 함수
int sum(int n)
{
    int s = 0;
    for (int i = 1; i < n; ++i)
        s += i;

    return s;
}

int main(void)
{
    int a = 10;
    int b = 20;

    printf("%d\n", sum(a));

    // int result = a + b;
    int result = add(a, b);

    print_number(result);

    return 0;
}