// 10_배열4.c
#include <stdio.h>

// C89: 배열의 크기는 반드시 컴파일 시간에 결정되어야 합니다.
// C99: 배열의 크기로 변수를 사용할 수 있습니다.
#if 0
int main()
{
    int n = 10;

    int arr2[10];
    // > 배열의 크기가 컴파일 타임에 결정됩니다.

    scanf("%d", &n);
    int arr[n]; // ?
    // > 배열의 크기가 런타임에 결정됩니다.

    // C89 표준은 에러
    // C99 표준은 Ok

    printf("%lu\n", sizeof(arr));
}
#endif

// 배열의 크기를 얻는 방법.
// - sizeof
// 배열의 개수를 구하는 방법
// - sizeof(arr) / sizeof(int)
// - sizeof(arr) / sizeof(arr[0])
//  : 배열의 타입이 변경되었을 경우, 위의 표현식에 대해서 별도의
//    수정이 필요하지 않습니다.
int main()
{
    int arr[20];
    // 4바이트 크기를 가지는 메모리를 20개 연속으로 할당합니다.
    // => 80byte

    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(arr) / sizeof(int)); // 1
    printf("%lu\n", sizeof(arr) / sizeof(arr[0])); // 2
}