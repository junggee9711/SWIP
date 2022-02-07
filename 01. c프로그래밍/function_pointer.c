// �Լ� ������
// : �Լ��� �ּҸ� ������ ������ ����

#include <stdio.h>

int add(int a, int b) { return a + b; }
// TEXT ������ �ε�˴ϴ�.
// => �ּҸ� �����ϴ�.

int main()
{
    int a = 10;
    int* p = &a;

    int (*fp)(int, int);
    fp = &add; // !
    fp = add;

    int result = (*fp)(10, 20); // !
    result = fp(10, 20);

    printf("%d\n", result);

    printf("%p\n", &add); // 0x100323f3c

    return 0;
}