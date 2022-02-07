v#include <stdio.h>

// 2차원 배열과 포인터

// int *x[5]
// [ int* ][ int* ][ int* ][ int* ][ int* ]
// => 포인터 배열

// int (*x)[5]
//  [ x ] --------> int[5]
//  8byte
// => 배열 포인터

void print_array(int(*x)[5], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            // printf("%d", *(*(x + i) + j));
            printf("%d", x[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // [ int[5] ][ int[5] ][ int[5] ]
    int x[3][5] = {
        1, 2, 3, 4, 5, //
        1, 2, 3, 4, 5, //
        1, 2, 3, 4, 5, //
    };

    printf("%lu\n", sizeof(x) / sizeof(x[0]));
    print_array(x, 3);
}