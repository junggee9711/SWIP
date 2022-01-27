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

void print2(int(**p)[4])
{
    int(*arr)[4] = *p;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

int main()
{
    // int arr[3][4]
    int(*arr)[4] = malloc(sizeof(int[4]) * 3);

    // int[4]
    print(arr, 3);
    print2(&arr); // p -> int(**p)[4]
    return 0;
}