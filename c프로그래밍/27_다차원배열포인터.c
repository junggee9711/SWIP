
#include <stdio.h>

int main()
{
    int x[3] = {
        1,
        2,
    };

    int* p1 = x;
    int(*p2)[3] = &x;

    int y[3][2] = {
        { 1, 2 },
        { 3, 4 },
        { 5, 6 }, // Trailing Comma
    };

    int(*p2)[2] = y; // Decay �� ��
    // N-1�� �迭�� ����Ű�� ������ ������ ����ϴ�.

    int(*p3)[3][2] = &y; // Decay �� �ȵ� (�迭 ��ü�� ����Ŵ)

    int z[1][2][3] = {};

    int(*p4)[2][3];
    p4 = z;

    int(*p5)[1][2][3] = &z;
}