#include <stdio.h>

// factorial
// ����� ����
// => �޸� ������ ������ �� ������,
//    �ڵ带 �м��ϱ� ��ƽ��ϴ�.
int factorial(int n)
{
    int s = 1;
    for (int i = 1; i <= n; ++i) {
        // s = s * i;
        s *= i;
    }

    return s;
}

// ��͹���
// => �ڵ带 '����'�ϰ� ǥ���ϴ� ���� �����մϴ�.
// => �Լ� ȣ���� ��ø�Ǵ� ������尡 �ְ�,
//    ȣ���� ������ ��ø�� �� �����ϴ�.
int factorial2(int n)
{
    if (n == 1)
        return 1;

    return n * factorial2(n - 1);
}

int fib(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{

    int result
        = factorial2(5);
    printf("%d\n", result);
}