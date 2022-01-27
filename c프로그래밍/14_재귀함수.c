// 14_재귀함수.c
#include <stdio.h>

#if 0
// 함수는 스택에서 동작합니다.
void print_hello()
{
    printf("hello\n");
    print_hello(); // 자기 자신을 다시 호출!
}

int main()
{
    print_hello();
    return 0;
}
#endif

// 정의: 함수가 자기 자신을 다시 호출하는 것을 재귀호출이라고 합니다.
// - 재귀함수 사용 방법
//  * 재귀 탈출 조건이 반드시 필요합니다.
//   - 인자를 통해 전달된 값을 통해 탈출 조건을 체크합니다.

void print_hello(int n)
{
    // 재귀 탈출 구문
    if (n < 0)
        return;

    printf("hello\n");
    print_hello(n - 1);
}

int main()
{
    print_hello(5);
}