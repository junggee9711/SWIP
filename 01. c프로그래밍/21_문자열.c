// 21_���ڿ�.c
#include <stdio.h>

// 1. char Ÿ���� ���ڸ� ǥ���ϴ� Ÿ���Դϴ�.
// 2. %c�� ���ؼ� printf�� ���� ��� �����մϴ�.
// 3. ������ ���ڸ� �����ϸ�, ASCII �ڵ尪���� ����˴ϴ�.
//   'A': 65
//   'a': 97
//   '0': 48
// 4. �ѱ�
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