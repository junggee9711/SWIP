// 14_����Լ�.c
#include <stdio.h>

#if 0
// �Լ��� ���ÿ��� �����մϴ�.
void print_hello()
{
    printf("hello\n");
    print_hello(); // �ڱ� �ڽ��� �ٽ� ȣ��!
}

int main()
{
    print_hello();
    return 0;
}
#endif

// ����: �Լ��� �ڱ� �ڽ��� �ٽ� ȣ���ϴ� ���� ���ȣ���̶�� �մϴ�.
// - ����Լ� ��� ���
//  * ��� Ż�� ������ �ݵ�� �ʿ��մϴ�.
//   - ���ڸ� ���� ���޵� ���� ���� Ż�� ������ üũ�մϴ�.

void print_hello(int n)
{
    // ��� Ż�� ����
    if (n < 0)
        return;

    printf("hello\n");
    print_hello(n - 1);
}

int main()
{
    print_hello(5);
}