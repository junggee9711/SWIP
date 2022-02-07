#include <stdio.h>

// 1. ������ Ÿ���� ������ �������� �����ϴ� ���� ���� �Դϴ�.
// warning: incompatible integer to pointer conversion assigning to 'int *' from 'int'

// 2. �����ϴ� ����(���ü)�� Ÿ���� �����ϸ�,
//    ������ Ÿ�Ե� �����մϴ�.

int main()
{
    int num1 = 10;
    int num2 = 20;

    int* pnum = &num1;

    // pnum = 20; // error!
    *pnum = 20;

    pnum = &num2; // ok
    *pnum = 200;

    printf("%d\n", num1); // 20
    printf("%d\n", num2); // 200

    printf("%p\n", &num1); // 0x16d97b1fc
    printf("%p\n", &num2); // 0x16d97b1f8
    printf("%p\n", pnum); // 0x16d97b1f8

    printf("%d\n", *pnum); // 200

    return 0;
}