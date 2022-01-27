// 21_문자열.c
#include <stdio.h>

// 1. char 타입이 문자를 표현하는 타입입니다.
// 2. %c를 통해서 printf를 통해 출력 가능합니다.
// 3. 변수에 문자를 저장하면, ASCII 코드값으로 저장됩니다.
//   'A': 65
//   'a': 97
//   '0': 48
// 4. 한글
//   => euc-kr(CP949): Windows / MBCS(Multi Byte Character Set)
//      UTF-16: Windows
//      UTF-8: Linux - *

int main()
{
    char c = 'A';
    printf("%c\n", c); // 'A'

    printf("%d\n", c); // 65

    return 0;
}