#include <stdio.h>

// ����ü ũ��
// 1. ��� ������ ������ ��ġ ��ġ�� ���� ����� �޶����ϴ�.
// 2. ����ü �е��� ���ֱ� ���ؼ���
//    �����Ϸ��� �����ϴ� ���þ ���ؼ� �е��� ������ �� �ֽ��ϴ�.

#pragma pack(push, 1)
struct A {
    char a;
    int b;
    double c;
};

struct B {
    char c;
    double a;
    int b;
};
#pragma pack(pop)

int main()
{
    printf("%ld\n", sizeof(struct A)); //
    printf("%ld\n", sizeof(struct B)); //

    return 0;
}