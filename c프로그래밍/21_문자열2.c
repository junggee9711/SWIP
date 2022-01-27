#include <stdio.h>

// 1. ���ڿ��� char �迭�� ǥ���˴ϴ�.
// 2. %s�� ���� ���ڿ��� ����� �� �ֽ��ϴ�.
// 3. C����� ��� ���ڿ��� �ݵ�� '\0'�� �������� �����մϴ�.
//  => ���ڿ� �Լ��� ���̸� ������ �ʿ䰡 �����ϴ�.

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
    str2[1] = 'X'; // ���� �Ұ����� ���ڿ��� �����߽��ϴ�.
    // error: read-only variable is not assignable

    printf("%s\n", str);
    print_str(str);

    return 0;
}