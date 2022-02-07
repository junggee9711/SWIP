#include <stdio.h>

int main()
{
    int i = 2;
    int j = 1;

    for (i = 2; i <= 9; ++i) {
        for (j = 1; j <= 9; ++j) {
            printf("%d * %d = %d\n", i, j, i * j);
        }
    }

#if 0
    while (i <= 9) {
        j = 1;
        while (j <= 9) {
            printf("%d * %d = %d\n", i, j, i * j);
            ++j;
        }

        ++i;
    }
#endif

    return 0;
}