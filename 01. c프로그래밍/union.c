#include <stdio.h>

union AAA {
    int a;
    char b;
    double c;
};
// ��ȣ ��Ÿ���� ���°��� ȿ�������� �����ϱ� ���� ����մϴ�.

int main()
{
    // ���� �������� ���Ե� ���� ��ȿ�մϴ�.
    union AAA aaa;
    aaa.a = 10;
    printf("%d\n", aaa.a);
    aaa.b = 'A';
    printf("%c\n", aaa.b);
    aaa.c = 3.14;
    printf("%lf\n", aaa.c);

    printf("%lu\n", sizeof(union AAA));
}