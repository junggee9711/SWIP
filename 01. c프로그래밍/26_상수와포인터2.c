#include <stdio.h>

typedef int* PINT;

typedef PINT const WHERE_CONST;

int main()
{
    int n = 10;

    WHERE_CONST p = &n;
    *p = 20; // ���ü�� ���� �����ϴ�.
    // p = &n; // �ڱ� �ڽ��� ����̴�.
}