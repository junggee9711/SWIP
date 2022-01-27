
// ���� �Լ�
// => �Լ��� ��ȯ�ϰų� �Լ��� ���ڷ� �޴� �Լ�
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

// int (int a, int b)

typedef int (*FP)(int a, int b);
// FP == int(*)(int, int);

FP goo(FP arg)
{
    return &add;
}

// �ƹ� ���ڵ� ���� �ʰ�  "int *(int, int) =  2���� ������ �޾Ƽ� ������ ��ȯ�ϴ� �Լ�"�� �����͸� ��ȯ�ϴ� �Լ�
int (*foo(  )) (int a, int b)
{

    return &add; // �Լ� �����͸� ��ȯ�մϴ�.
}

// 2���� ������ �޾Ƽ� "*p(int, int) = �Լ��� �����͸� ���ڷ� �޴� �Լ���" �����͸� ��ȯ�ϴ� �Լ� => ���� �ݴ��!
int (*foo(int (*p)(int, int))) (int a, int b)
{

    return &add; // �Լ� �����͸� ��ȯ�մϴ�.
}



int main()
{
    int result = foo(&add)(10, 20);
    printf("%d\n", result);

    // int (*p)(int, int) = &add;
    // printf("%d\n", (*p)(10, 20));

    int (*p)(int a, int b) = add;
    printf("%d\n", p(10, 20));
    // �Լ��� �̸��� �Լ� �������� �Ϲ��� ��ȯ�� ����մϴ�.
    // �Լ������Ϳ� ���� ȣ���� ���� ���� ȣ�� �����մϴ�.
}

foo(int (*))