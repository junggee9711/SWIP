#include <stdio.h>

// C���� �迭�� ó���ϴ� �Լ��� ������ ����
// �ݵ�� �迭�� ���� ������ ���� �޾ƾ� �մϴ�.
// memcpy

// �迭�� �Լ��� ���� ó���ϴ� ���.
// => sizeof(x) / sizeof(x[0])

// �迭�� ��� ��Ҹ� ����ϴ� �Լ�
// void print_array(int x[5])
void print_array(int* x, int n)
{
    printf("%lu\n", sizeof(x)); // 8

    for (int i = 0; i < n; ++i)
        printf("%d\n", x[i]);
}

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };
    print_array(x, sizeof(x) / sizeof(x[0]));
    // �迭�� ù��° ������ ���� �ּҸ� �����մϴ�.

    return 0;
}