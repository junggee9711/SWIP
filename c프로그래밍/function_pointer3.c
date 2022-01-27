

#include <stdio.h>
#include <stdlib.h> // malloc, free, exit

// 복잡한 표현식
// => 배열 포인터
//    함수 포인터

// 배열이 타입 그대로 해석됩니다.
// => sizeof / &

// 사용자가 전달한 크기 만큼의 배열을 만들어줍니다.
// 하나의 원소는 int[3] 입니다.

// int (*p)[3] = malloc(sizeof(int[3]) * 5)

typedef int(*ARR3)[3];

// int (*foo(int n))[3]
ARR3 foo(int n)
{
    // int(*arr)[3] = (int(*)[3])malloc(sizeof(int[3] * n));
    ARR3 arr = (ARR3)malloc(sizeof(int[3]) * n);

    // static int arr[n][3];
    // 5개 짜리
    // => int arr[5][3];

    return arr;
}

int main()
{
    ARR3 p3 = foo(10); // int[10][3];
    p3[0][2] = 42;
    printf("%d\n", p3[0][2]);

    int x[5] = { 1, 2, 3, 4, 5 };
    int* p = x; // &x[0]

    int(*p2)[5] = &x; //

    //-------
}