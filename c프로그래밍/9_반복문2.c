// 9_반복문2.c
#include <stdio.h>

// 사용자가 -1을 입력할 때까지 계속 정수를 입력받아서,
// 입력된 모든 정수의 합을 구하는 프로그램을 작성해봅시다.

int main()
{
    int n = 0;

    int sum = 0;

#if 1
    while (n != -1) {
        scanf("%d", &n);

        if (n != -1) {
            sum += n;
        }
    }
#endif

#if 0    
    while (1) {
        scanf("%d", &n);

        if (n == -1)
            break;

        sum += n;
    }
#endif

    printf("sum: %d\n", sum);

    return 0;
}