#include <stdio.h>

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };

    // x: 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석된다.
    // int* p = &x[0];

    int* p = x;

    printf("%d\n", x[0]);
    printf("%d\n", x[1]);
    printf("%d\n", x[2]);

    printf("%d\n", *(x + 0));
    printf("%d\n", *(x + 1));
    printf("%d\n", *(x + 2));

    printf("%d\n", *(p + 0));
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));

    printf("%d\n", p[0]);
    printf("%d\n", p[1]);
    printf("%d\n", p[2]);

    return 0;
}