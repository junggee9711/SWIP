#include <stdio.h>
#include <string.h>

// 1. 문자열 비교를 위해 주소를 비교하는 것은
//    결과가 항상 다릅니다.
// 2. 문자열 비교 함수
//    strcmp : string.h
//    : 같은 문자열이면 0을 반환합니다.
//     ret == 0 : 같은 문자열
//     ret < 0  : 사전적으로 앞에 존재한다.
//     ret > 0  :         뒤에 존재한다.

int main()
{
    char s1[] = "aello"; // -1
    // char s2[] = "hello";
    // const char* s1 = "hello";
    const char* s2 = "bello"; // 1

    printf("%d\n", strcmp(s2, s1));

    if (strcmp(s1, s2) == 0) {
        printf("같은 문자열 입니다..\n");
    }
    else {
        printf("다른 문자열 입니다..\n");
    }

#if 0
    if (s1 == s2) {
        printf("같은 문자열 입니다..\n");
    }
    else {
        printf("다른 문자열 입니다..\n");
    }
#endif
}