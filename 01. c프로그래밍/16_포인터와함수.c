#include <stdio.h>

// 함수의 인자 전달 방식
// 1. 인자 값을 복사해서 전달합니다.
//    인자 값을 다른 함수를 통해서 변경하는 것이 불가능합니다.
//  => Call by Value
#if 0
void inc(int x)
{
    x = x + 1;
}

int main()
{
    int n = 10;
    inc(n);
    inc(n);
    inc(n);

    printf("%d\n", n);
}
#endif

// 2. 값을 전달하는 것이 아니라, 주소값을 전달하면
//    변수를 참조해서 값을 읽거나 변경할 수 있습니다.
//  => Call by reference(pointer)
//   : 인자로 주소를 전달해서 값을 읽거나 변경하는 것이 가능합니다.

void inc(int* x)
{
    // *x = *x + 1;
    ++(*x);
}

int main()
{
    int n = 10;
    inc(&n);
    inc(&n);
    inc(&n);

    printf("%d\n", n);
}