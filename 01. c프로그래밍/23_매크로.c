
#include <stdio.h>

// ��ũ�� ���
// => �빮��_�빮�� ������ ����մϴ�.

#define PI 3.14
#define MAX_STR_SIZE 32

// 1) �迭�� ũ�⸦ ������ ��
// 2) ��� ���� �ǹ� �ִ� �̸��� �ο��� ��

// #undef PI
// �̹� ���ǵ� ��ũ�� ����� �����մϴ�.

int main()
{
    char buf[MAX_STR_SIZE];

    printf("%lf\n", PI);
}