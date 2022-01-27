#include <stdio.h>

// 1. 문자열은 char 배열로 표현됩니다.
// 2. %s를 통해 문자열을 출력할 수 있습니다.
// 3. C언어의 모든 문자열은 반드시 '\0'가 마지막에 존재합니다.
//  => 문자열 함수에 길이를 전달할 필요가 없습니다.

void print_str(char* str)
{
    while (*str) {
        printf("%c", *str++);
    }

#if 0
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
#endif
}

int main()
{
    // char str[] = { 'A', 'B', 'C', '\0' };
    // char str[] = { 65, 66, 67, 0 };
    char str[] = "ABC";
    str[1] = 'X'; // OK!

    const char* str2 = "ABC";
    str2[1] = 'X'; // 수정 불가능한 문자열을 수정했습니다.
    // error: read-only variable is not assignable

    printf("%s\n", str);
    print_str(str);

    return 0;
}