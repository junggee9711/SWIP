#include <stdio.h>
#include <string.h>

// 토큰을 분리하는 함수 => strtok
// : 내부적으로 정적 메모리(전역 변수, 내부 정적 변수)를 사용합니다.
#if 0
char* strtok(char* str, const char* sep);
#endif

int main()
{
    char str[] = "hello    world show me the money";

    for (char* p = strtok(str, " ");
        p != NULL;
        p = strtok(NULL, " ")) {
        printf("%s\n", p);
    }

#if 0
    char* p = strtok(str, " ");
    printf("%s\n", p);

    p = strtok(NULL, " ");
    printf("%s\n", p);

    p = strtok(NULL, " ");
    printf("%s\n", p);
#endif

    return 0;
}