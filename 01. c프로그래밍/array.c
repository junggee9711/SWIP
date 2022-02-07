#include <stdio.h>
#include <stdlib.h>

#if 0
int main()
{
    int arr[3][4] = {
        { 1, 2, 3, 4 },
        { 11, 12, 13, 14 },
        { 21, 22, 23, 24 },
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }

    return 0;
}
#endif

void print(int(*arr)[4], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

void print2(int(*p)[3][4])
{
    int(*arr)[4] = *p;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

void print3(int(*p)[3][4])
{
    int n = sizeof(*p) / sizeof((*p)[0]);
    int m = sizeof((*p)[0]) / sizeof((*p)[0][0]);
    printf("%d %d\n", n, m);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("arr[%d][%d] = %d\n", i, j, (*p)[i][j]);
        }
    }
}

int main()
{
#if 1
    int arr[3][4] = {
        { 1, 2, 3, 4 },
        { 11, 12, 13, 14 },
        { 21, 22, 23, 24 },
    };
#endif

    // int[4]
    print(arr, 3);
    print3(&arr); // int (*p)[3][4]

    return 0;
}