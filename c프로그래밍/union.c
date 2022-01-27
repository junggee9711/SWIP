#include <stdio.h>

union AAA {
    int a;
    char b;
    double c;
};
// 상호 배타적인 상태값을 효율적으로 관리하기 위해 사용합니다.

int main()
{
    // 가장 마지막에 대입된 값이 유효합니다.
    union AAA aaa;
    aaa.a = 10;
    printf("%d\n", aaa.a);
    aaa.b = 'A';
    printf("%c\n", aaa.b);
    aaa.c = 3.14;
    printf("%lf\n", aaa.c);

    printf("%lu\n", sizeof(union AAA));
}