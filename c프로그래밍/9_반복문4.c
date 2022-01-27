// 9_¹Ýº¹¹®4.c

#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;

#if 0
    while (i < 10) {

        j = 0;
        while (j <= i) {
            printf("*");
            ++j;
        }

        printf("\n");
        ++i;
    }
#endif

    while (i < 10) {
        j = 0;
        while (j < 10 - i) {
            printf("*");
            ++j;
        }

        printf("\n");
        ++i;
    }

    return 0;
}