#include <stdio.h>

// 매크로 문법
// => #, ##

// #: 전달된 토큰을 문자열로 변경합니다.
//  => 10 - "10"
//     ok -> "ok"

#define print_value(x) \
    printf("%s=%d\n", #x, x)

// 문자열로 변경하는 매크로는 매크로 상수에 대한 치환이 제대로 수행되지 않습니다.
#define MAX 256
// #define TOSTR(x) #x

// 매크로 상수가 제대로 치환되도록 하기 위해서 이중으로 구성합니다.
#define _TOSTR(x) #x
#define TOSTR(x) _TOSTR(x)

int main()
{
    printf("%s\n", TOSTR(AAA)); // "AAA"
    printf("%s\n", TOSTR(MAX));
    // _TOSTR(256) => "256"

    return 0;
}

#if 0
int main()
{
    int value1 = 10;
    int value2 = 20;

    print_value(10);
    // => printf("%s\n", "10");

    print_value(value1);
    // => printf("%s\n", "value1");
}
#endif