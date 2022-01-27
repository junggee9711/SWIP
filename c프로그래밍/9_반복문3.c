#include <stdio.h>

// 반복문 - 중첩이 가능합니다.
// > 2중 중첩 위주로 많이 사용합니다.

int main()
{
    int i = 2;
    int j = 1;

    // i:  2   3   4   5   6   7   8   9
    // j: 1-9 1-9 1-9 1-9 1-9 1-9 1-9 1-9
    while (i <= 9) {

        j = 1;
        while (j <= 9) {
            printf("%d * %d = %d\n", i, j, i * j);
            ++j;
        }

        ++i;
    }

}