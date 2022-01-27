#include <stdio.h>

int main()
{
    int n = 10;
    int n2 = 20;

    // *
    // ��: ����Ű�� ���ü(n)�� ��� ����ϰڴ�.
    // ��: ������ ������ ��� ����ϰڴ�.
    const int* p1 = &n;
    // *p1 = 20; // error!
    p1 = &n2; // ok!

    int const* p2 = &n;
    // *p2 = 20; // error!
    p2 = &n2; // ok!

    int* const p3 = &n;
    *p3 = 40; // ok!
    // p3 = &n2; // error!

    const int* const p4 = &n;
    int const* const p5 = &n;
}

#if 0
int main()
{
    int n1 = 0;

    int* p1 = &n1;
    const int* p2 = &n1;
    // p2�� �����͸� ���ؼ� ���ü n�� ���� �������� �ʰڴ�.

    const int n2 = 0;

    // int* => const int
    // int* p3 = &n2; // C�� ���, C++ �����Դϴ�.

    const int* p4 = &n2;
}
#endif

#if 0
int main()
{
    int c1 = 10; // ����

    const int c2 = 10; // ���
    // 1. �ݵ�� �ʱⰪ�� �����ؾ� �մϴ�.
    // 2. ���� �����ϴ� ���� �Ұ����մϴ�.
    int const c3 = 10;

    // c2�� c3�� ������ ����Դϴ�.
    // => const�� Ÿ���� �� / �ڿ� �� �� �ֽ��ϴ�.
    // c2 = 10;
    // c3 = 30;
}
#endif