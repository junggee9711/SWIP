
// swap
// : �ΰ��� ������ ���� ��ȯ�ϴ� �Լ�

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