
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

    int(*p2)[2] = y; // Decay 가 됨
    // N-1차 배열을 가르키는 포인터 변수를 만듭니다.

    int(*p3)[3][2] = &y; // Decay 가 안됨 (배열 전체를 가리킴)

    int z[1][2][3] = {};

    int(*p4)[2][3];
    p4 = z;

    int(*p5)[1][2][3] = &z;
}