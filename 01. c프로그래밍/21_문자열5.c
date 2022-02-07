#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strcmp, strcpy, strcat, strlen

// 1. ���ڿ� ���� �Լ�
//  => strlen

// 2. ���ڿ� ���� �Լ�
//  => ���� �޸� �Ҵ��� ���� ���ڿ��� �����մϴ�.
//  => strdup
//  => �ݵ�� free ����� �մϴ�.

int main()
{
    char str[32] = "hello";
    printf("%lu\n", sizeof(str)); // 32 byte
    printf("%lu\n", strlen(str));

    // ���� �޸� �Ҵ��� ���� ���ڿ��� �Ҵ��ϰ� �ʹ�.
    // 1. ���ڿ� ���� + 1 ��ŭ�� �޸𸮸� �Ҵ��մϴ�.
    char* p = (char*)malloc(strlen(str) + 1); // 6 byte �Ҵ�
    // 2. ���ڿ� ����
    strcpy(p, str);
    printf("%s\n", p);

    char* p2 = strdup(str);
    printf("%s\n", p2);

    // 3. �޸� ����
    free(p);
    free(p2);

    return 0;
}