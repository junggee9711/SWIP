
#include <stdio.h>

// ##
// => �� �� ��ū�� �ϳ��� ��ū���� ������ݴϴ�.
// => Ȱ��: ��ũ�θ� �̿��ؼ� �ڵ带 �����ϴ� ������ ���˴ϴ�.

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