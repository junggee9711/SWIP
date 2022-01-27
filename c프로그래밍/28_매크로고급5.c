#include <stdio.h>

// ��ũ�� ����
// => #, ##

// #: ���޵� ��ū�� ���ڿ��� �����մϴ�.
//  => 10 - "10"
//     ok -> "ok"

#define print_value(x) \
    printf("%s=%d\n", #x, x)

// ���ڿ��� �����ϴ� ��ũ�δ� ��ũ�� ����� ���� ġȯ�� ����� ������� �ʽ��ϴ�.
#define MAX 256
// #define TOSTR(x) #x

// ��ũ�� ����� ����� ġȯ�ǵ��� �ϱ� ���ؼ� �������� �����մϴ�.
#define _TOSTR(x) #x
#define TOSTR(x) _TOSTR(x)

int main()
{
    printf("%s\n", TOSTR(AAA)); // "AAA"
    printf("%s\n", TOSTR(MAX));
    // _TOSTR(256) => "256"

    return 0;
}

#if 0
int main()
{
    int value1 = 10;
    int value2 = 20;

    print_value(10);
    // => printf("%s\n", "10");

    print_value(value1);
    // => printf("%s\n", "value1");
}
#endif