#include <stdio.h>
#include <string.h>

// 1. strcmp: 문자열 비교 함수
// 2. strcpy(dest, src)
//  dest: 복사의 대상체 => 수정 가능한 메모리에 존재해야 합니다.
//  src: 복사 원본

// 2. strcat(dest, src)
//  dest의 뒤에 src가 이어집니다.
//  주의사항: 충분한 메모리가 확보되어 있어야 합니다.

int main()
{
    const char* s1 = "hello";
    char str[32] = "hello";
    // 문자열 리터럴을 통해 문자열 배열을 초기화할 수 있습니다.

    // str = "show me the money";
    // 대입을 통해 문자열 내용을 변경하는 것이 불가능합니다.
    strcpy(str, "show me the money");

    strcat(str, " hello");

    printf("%s\n", str);

    return 0;
}