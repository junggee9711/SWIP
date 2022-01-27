
#include <stdio.h>

// ##
// => 두 개 토큰을 하나의 토큰으로 만들어줍니다.
// => 활용: 매크로를 이용해서 코드를 생성하는 도구로 사용됩니다.

#define print_value(x) \
    printf("%d, %d\n", x##1, x##2)

#define CALC_OP(op) \
    void my_##op##_func() { }

CALC_OP(hello)

int main()
{
    int value1 = 10;
    int value2 = 20;

    print_value(value);
    // printf("%d, %d", value1, value2)
}