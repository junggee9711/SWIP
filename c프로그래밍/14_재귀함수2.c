#include <stdio.h>

// factorial
// 비재귀 버전
// => 메모리 관리를 쉽게할 수 있지만,
//    코드를 분석하기 어렵습니다.
int factorial(int n)
{
    int s = 1;
    for (int i = 1; i <= n; ++i) {
        // s = s * i;
        s *= i;
    }

    return s;
}

// 재귀버전
// => 코드를 '간결'하게 표현하는 것이 가능합니다.
// => 함수 호출이 중첩되는 오버헤드가 있고,
//    호출이 무한정 중첩될 수 없습니다.
int factorial2(int n)
{
    if (n == 1)
        return 1;

    return n * factorial2(n - 1);
}

int fib(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{

    int result
        = factorial2(5);
    printf("%d\n", result);
}