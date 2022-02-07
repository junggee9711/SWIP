#include <stdio.h>

#if 0
int main()
{
    int a, b, c, d, e;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);

    return 0;
}
#endif

// 배열: 동일한 타입의 여러 개의 메모리를 연속적으로 할당합니다.
// - 하나의 이름과 하나의 인덱스를 통해 해당 메모리에 접근이 가능합니다.
#if 0
int main()
{
    int n; // int
    int arr[5]; // int[5];

    // int 타입 메모리를 5개 연속으로 할당합니다.
    // 각각의 메모리를 인덱스 첨자 연산을 통해 접근할 수 있습니다.
    // arr[0] / arr[1] / arr[2] / arr[3] / arr[4]

    int i;
    for (i = 0; i < 5; ++i) {
        scanf("%d", &arr[i]);
    }

    return 0;
}
#endif

// 배열의 초기화
int main()
{
    int i = 0;

    int x1[5];
    // 쓰레기값을 가지는 형태로 초기화됩니다.
    printf("%d\n", x1[3]);

    int x2[5] = {
        1,
        2,
        3,
        4,
        5,
        // 6,
    };

    for (i = 0; i < 5; ++i) {
        printf("%d\n", x2[i]);
    }

    int x3[5] = { 1, 2, 3 };
    // 나머지는 0으로 초기화됩니다.

    int x4[5] = {
        0,
    };

    for (i = 0; i < 5; ++i) {
        printf("%d\n", x4[i]);
    }

    return 0;
}