#include <stdio.h>

// �Լ��� ���� ���� ���
// 1. ���� ���� �����ؼ� �����մϴ�.
//    ���� ���� �ٸ� �Լ��� ���ؼ� �����ϴ� ���� �Ұ����մϴ�.
//  => Call by Value
#if 0
void inc(int x)
{
    x = x + 1;
}

int main()
{
    int n = 10;
    inc(n);
    inc(n);
    inc(n);

    printf("%d\n", n);
}
#endif

// 2. ���� �����ϴ� ���� �ƴ϶�, �ּҰ��� �����ϸ�
//    ������ �����ؼ� ���� �аų� ������ �� �ֽ��ϴ�.
//  => Call by reference(pointer)
//   : ���ڷ� �ּҸ� �����ؼ� ���� �аų� �����ϴ� ���� �����մϴ�.

void inc(int* x)
{
    // *x = *x + 1;
    ++(*x);
}

int main()
{
    int n = 10;
    inc(&n);
    inc(&n);
    inc(&n);

    printf("%d\n", n);
}