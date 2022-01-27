#include <stdio.h>

typedef int* PINT;

typedef PINT const WHERE_CONST;

int main()
{
    int n = 10;

    WHERE_CONST p = &n;
    *p = 20; // 대상체는 변경 가능하다.
    // p = &n; // 자기 자신이 상수이다.
}