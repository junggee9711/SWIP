#include <stdio.h>

// for문 입니다.

#if 0
int main()
{
    // count 라는 변수를 0부터 9까지 반복하는 구문입니다.
    // [0, 10): 반개 구간
#if 0
    int count = 0;
    while (count < 10) {
        printf("%d\n", count);
        ++count;
    }
#endif

    int count;
    for (count = 0; count < 10; ++count) {
        printf("%d\n", count);
    }

    return 0;
}
#endif

// continue
// : for / while의 동작이 조금 다릅니다.

//   for: 반복할 횟수가 명확한 경우 사용합니다.
// while: 반복의 횟수가 명확하지 않은 경우 사용합니다.

int main()
{
    int count = 0;

    // while (count < 10) {
    //     printf("%d\n", count);

    //     if (count == 5)
    //         continue;

    //     ++count;
    // }

    for (count = 0; count < 10; ++count) {
        printf("%d\n", count);

        if (count == 5)
            continue;

        //...
    }
}