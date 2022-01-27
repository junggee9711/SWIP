#include <stdio.h>

int main()
{
    int x[3] = { 1, 2, 3 };

    int* p1 = x; // int*

    // p2 ----> int[3]
    // ??? p2 = &x; // ?

    int(*p2)[3] = &x;

    int n = 10;
    int* p = &n;

    printf("%lu\n", sizeof(*p)); // 4
    printf("%lu\n", sizeof(*p2)); // 12

    printf("%d\n", (*p2)[1]);

    return 0;
}