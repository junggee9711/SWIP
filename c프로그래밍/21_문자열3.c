#include <stdio.h>
#include <string.h>

// 1. ���ڿ� �񱳸� ���� �ּҸ� ���ϴ� ����
//    ����� �׻� �ٸ��ϴ�.
// 2. ���ڿ� �� �Լ�
//    strcmp : string.h
//    : ���� ���ڿ��̸� 0�� ��ȯ�մϴ�.
//     ret == 0 : ���� ���ڿ�
//     ret < 0  : ���������� �տ� �����Ѵ�.
//     ret > 0  :         �ڿ� �����Ѵ�.

int main()
{
    char s1[] = "aello"; // -1
    // char s2[] = "hello";
    // const char* s1 = "hello";
    const char* s2 = "bello"; // 1

    printf("%d\n", strcmp(s2, s1));

    if (strcmp(s1, s2) == 0) {
        printf("���� ���ڿ� �Դϴ�..\n");
    }
    else {
        printf("�ٸ� ���ڿ� �Դϴ�..\n");
    }

#if 0
    if (s1 == s2) {
        printf("���� ���ڿ� �Դϴ�..\n");
    }
    else {
        printf("�ٸ� ���ڿ� �Դϴ�..\n");
    }
#endif
}