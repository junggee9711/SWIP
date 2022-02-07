
#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pswap(int** a, int** b)
{
    // int** p;
    // *p => int*
    // ** => int

    int* temp = *a;
    *a = *b;
    *b = temp;
}

void pswap2(int** a, int** b)
{
    int temp = **a;
    **a = **b;
    **b = temp;
}

void foo(int** arr)
{
    static int x[3] = { 1, 2, 3 };
    *arr = x;
}

int* goo()
{
    static int x[3] = { 1, 2, 3 };
    return x;
}

int main()
{
    int* p;
    foo(&p);

    p = goo();

    printf("%d\n", p[0]);
    printf("%d\n", p[1]);
    printf("%d\n", p[2]);

    int a = 10;
    int b = 20;
    swap(&a, &b);

    int* p1 = &a;
    int* p2 = &b;
    pswap(&p1, &p2);
    pswap2(&p1, &p2);

    printf("%d %d\n", a, b);
}