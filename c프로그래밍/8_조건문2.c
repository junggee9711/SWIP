
#include <stdio.h>

// ���ǹ�
// 1. if
// 2. switch
// fallthrough
//  : Ư�� �󺧷� �����ؼ� ���� ������ ��� �����մϴ�.
// - break ���� ���ؼ� Ż���� �����մϴ�/
#if 0
switch (��)
{
case 1: // �� == 1

case 2: // �� == 2

default: // ������(else)

}

#endif

int main()
{
    int n = 0;
    scanf("%d", &n);

    switch (n) {
    case 1:
        printf("1 �Դϴ�.\n");
        break;
        
    case 2:
        printf("2 �Դϴ�.\n");
        break;
        
    default:
        printf("������ �Դϴ�.\n");
    }

    return 0;
}
