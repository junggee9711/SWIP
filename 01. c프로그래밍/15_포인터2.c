#include <stdio.h>

// 1. & �����ڸ� ���� ������ �ּҸ� ���� �� �ֽ��ϴ�.
// 2. ������ ������ ���� ����Ű��(�����ϴ�) ������ ����
//    �аų� �����ϴ� ���� �����մϴ�.
// 3. ���� ������(referencing operator)

int main()
{
    int num = 0;
    double d = 3.14;

    printf("%p\n", &num);
    // int* ������ ����: �ּ� Ÿ���� �����ϱ� ���� ����
    int* p = &num;

    double* p2 = &d;

    *p = 20;
    printf("%d\n", *p);
    printf("%d\n", num);

    return 0;
}