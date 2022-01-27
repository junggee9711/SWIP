
// assert: 단언문
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
#define assert(expr)                                \
    do {                                            \
        if (!(expr)) {                              \
            printf("assertion failed: %s, %s:%d\n", \
                #expr, __func__, __LINE__);         \
            abort();                                \
        }                                           \
    } while (0)
#endif

// 컴파일 시간에 표현식의 유효성을 확인하는 방법을 제공할 수 있습니다.
#define static_assert(expr) \
    char __static_assert_failed[(expr) ? 1 : -1];
// 컴파일 시간에 판단되는 표현식의 결과가
// 거짓인 경우, 음수 크기를 가지는 배열을 만들어서
// 의도적으로 컴파일 오류를 발생시키는 기법입니다.

int main()
{
    static_assert(sizeof(long) == 8);

    int age;
    scanf("%d", &age);

    int next;
    if (age > 0)
        next = next + 1;
    else
        next = 0;

    // 삼항 연산자
    next = (age > 0) ? next + 1 : 0;

    // age가 양수이어야만 제대로 동작하는 코드입니다.
    // if (age < 0)
    //   abort(); // 비정상 종료

    assert(age > 0);
    printf("run...\n");
}