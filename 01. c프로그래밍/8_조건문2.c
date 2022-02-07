
#include <stdio.h>

// 조건문
// 1. if
// 2. switch
// fallthrough
//  : 특정 라벨로 점프해서 밑의 구문을 계속 수행합니다.
// - break 문을 통해서 탈출이 가능합니다/
#if 0
switch (값)
{
case 1: // 값 == 1

case 2: // 값 == 2

default: // 나머지(else)

}

#endif

int main()
{
    int n = 0;
    scanf("%d", &n);

    switch (n) {
    case 1:
        printf("1 입니다.\n");
        break;
        
    case 2:
        printf("2 입니다.\n");
        break;
        
    default:
        printf("나머지 입니다.\n");
    }

    return 0;
}
