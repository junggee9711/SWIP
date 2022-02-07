
// swap
// : 두개의 변수의 값을 교환하는 함수

#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    printf("%d %d\n", a, b);

    swap(&a, &b);
    // int temp = a;
    // a = b;
    // b = temp;

    printf("%d %d\n", a, b);
    return 0;
}