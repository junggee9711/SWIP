#include <stdio.h>

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };

    // x: �迭�� �̸��� �迭�� ù��° ������ ���� �ּҷ� �ؼ��ȴ�.
    // int* p = &x[0];

    int* p = x;

    printf("%d\n", x[0]);
    printf("%d\n", x[1]);
    printf("%d\n", x[2]);

    printf("%d\n", *(x + 0));
    printf("%d\n", *(x + 1));
    printf("%d\n", *(x + 2));

    printf("%d\n", *(p + 0));
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));

    printf("%d\n", p[0]);
    printf("%d\n", p[1]);
    printf("%d\n", p[2]);

    return 0;
}