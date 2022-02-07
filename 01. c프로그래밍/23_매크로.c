
#include <stdio.h>

// 매크로 상수
// => 대문자_대문자 형식을 사용합니다.

#define PI 3.14
#define MAX_STR_SIZE 32

// 1) 배열의 크기를 관리할 때
// 2) 상수 값에 의미 있는 이름을 부여할 때

// #undef PI
// 이미 정의된 매크로 상수를 제거합니다.

int main()
{
    char buf[MAX_STR_SIZE];

    printf("%lf\n", PI);
}