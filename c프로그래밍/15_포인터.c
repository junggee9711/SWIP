#include <stdio.h>

// 1. �����ʹ� �ٸ� �Լ����� ������ ���� �����ϱ� ���ؼ�
//    ����մϴ�.
// => �ٺ����� �������� �ʿ伺

// 2. ������ Ȱ��
//  : �迭�� ������
//    �Լ� ������

void foo(int a)
{
    a = 30;
    printf("foo: %d\n", a);
}

int main()
{
    int a = 10;

    // a = 20;
    printf("main: %d\n", a);
    foo(a);
    printf("main: %d\n", a);
}