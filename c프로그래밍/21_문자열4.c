#include <stdio.h>
#include <string.h>

// 1. strcmp: ���ڿ� �� �Լ�
// 2. strcpy(dest, src)
//  dest: ������ ���ü => ���� ������ �޸𸮿� �����ؾ� �մϴ�.
//  src: ���� ����

// 2. strcat(dest, src)
//  dest�� �ڿ� src�� �̾����ϴ�.
//  ���ǻ���: ����� �޸𸮰� Ȯ���Ǿ� �־�� �մϴ�.

int main()
{
    const char* s1 = "hello";
    char str[32] = "hello";
    // ���ڿ� ���ͷ��� ���� ���ڿ� �迭�� �ʱ�ȭ�� �� �ֽ��ϴ�.

    // str = "show me the money";
    // ������ ���� ���ڿ� ������ �����ϴ� ���� �Ұ����մϴ�.
    strcpy(str, "show me the money");

    strcat(str, " hello");

    printf("%s\n", str);

    return 0;
}