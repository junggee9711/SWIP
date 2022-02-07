// 10_¹è¿­3.c

#include <stdio.h>

int main()
{
    int block[4][4] = {
        1, 0, 0, 0, // y=0
        1, 0, 0, 0, // y=1
        1, 0, 0, 0, // y=2
        1, 0, 0, 0, // y=3
    };

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (block[y][x] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}