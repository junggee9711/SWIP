

#include <stdio.h>
#include <stdlib.h> // malloc, free, exit

// ������ ǥ����
// => �迭 ������
//    �Լ� ������

// �迭�� Ÿ�� �״�� �ؼ��˴ϴ�.
// => sizeof / &

// ����ڰ� ������ ũ�� ��ŭ�� �迭�� ������ݴϴ�.
// �ϳ��� ���Ҵ� int[3] �Դϴ�.

// int (*p)[3] = malloc(sizeof(int[3]) * 5)

typedef int(*ARR3)[3];

// int (*foo(int n))[3]
ARR3 foo(int n)
{
    // int(*arr)[3] = (int(*)[3])malloc(sizeof(int[3] * n));
    ARR3 arr = (ARR3)malloc(sizeof(int[3]) * n);

    // static int arr[n][3];
    // 5�� ¥��
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