// 11_�Լ�.c
#include <stdio.h>

// �Լ��� ����?
// : �Է°��� �޾Ƽ� �־��� ������ ������ ��
//   ����� ��ȯ�ϴ� �ڵ��� �����Դϴ�.
#if 0
��ȯ��Ÿ�� �Լ��̸�(�Լ����ڿ�)
{
    �Լ� ����
        return ��ȯ��;
}
#endif

int add(int a, int b) { return a + b; }

void print_number(int a)
{
    if (a < 0) {
        return;
    }

    printf("%d\n", a);
    printf("%x\n", a);
    printf("%o\n", a);

    // return; // void�� ��ȯ�ϴ� ���.
}

// ���ڷ� ���޵� n�� ���ؼ� n-1������ ���� ���ϴ� �Լ�
int sum(int n)
{
    int s = 0;
    for (int i = 1; i < n; ++i)
        s += i;

    return s;
}

int main(void)
{
    int a = 10;
    int b = 20;

    printf("%d\n", sum(a));

    // int result = a + b;
    int result = add(a, b);

    print_number(result);

    return 0;
}