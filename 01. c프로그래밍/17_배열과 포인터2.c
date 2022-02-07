#include <stdio.h>

// C언어에서 배열을 처리하는 함수를 설계할 때는
// 반드시 배열의 길이 정보도 전달 받아야 합니다.
// memcpy

// 배열을 함수를 통해 처리하는 방법.
// => sizeof(x) / sizeof(x[0])

// 배열의 모든 요소를 출력하는 함수
// void print_array(int x[5])
void print_array(int* x, int n)
{
    printf("%lu\n", sizeof(x)); // 8

    for (int i = 0; i < n; ++i)
        printf("%d\n", x[i]);
}

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };
    print_array(x, sizeof(x) / sizeof(x[0]));
    // 배열의 첫번째 원소의 시작 주소를 전달합니다.

    return 0;
}