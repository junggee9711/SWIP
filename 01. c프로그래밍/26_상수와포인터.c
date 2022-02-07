#include <stdio.h>

int main()
{
    int n = 10;
    int n2 = 20;

    // *
    // 앞: 가르키는 대상체(n)을 상수 취급하겠다.
    // 뒤: 포인터 변수를 상수 취급하겠다.
    const int* p1 = &n;
    // *p1 = 20; // error!
    p1 = &n2; // ok!

    int const* p2 = &n;
    // *p2 = 20; // error!
    p2 = &n2; // ok!

    int* const p3 = &n;
    *p3 = 40; // ok!
    // p3 = &n2; // error!

    const int* const p4 = &n;
    int const* const p5 = &n;
}

#if 0
int main()
{
    int n1 = 0;

    int* p1 = &n1;
    const int* p2 = &n1;
    // p2의 포인터를 통해서 대상체 n의 값을 변경하지 않겠다.

    const int n2 = 0;

    // int* => const int
    // int* p3 = &n2; // C는 경고, C++ 오류입니다.

    const int* p4 = &n2;
}
#endif

#if 0
int main()
{
    int c1 = 10; // 변수

    const int c2 = 10; // 상수
    // 1. 반드시 초기값을 지정해야 합니다.
    // 2. 값을 변경하는 것이 불가능합니다.
    int const c3 = 10;

    // c2와 c3는 동일한 상수입니다.
    // => const는 타입의 앞 / 뒤에 올 수 있습니다.
    // c2 = 10;
    // c3 = 30;
}
#endif