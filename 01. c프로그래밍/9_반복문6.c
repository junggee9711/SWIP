#include <stdio.h>

// for�� �Դϴ�.

#if 0
int main()
{
    // count ��� ������ 0���� 9���� �ݺ��ϴ� �����Դϴ�.
    // [0, 10): �ݰ� ����
#if 0
    int count = 0;
    while (count < 10) {
        printf("%d\n", count);
        ++count;
    }
#endif

    int count;
    for (count = 0; count < 10; ++count) {
        printf("%d\n", count);
    }

    return 0;
}
#endif

// continue
// : for / while�� ������ ���� �ٸ��ϴ�.

//   for: �ݺ��� Ƚ���� ��Ȯ�� ��� ����մϴ�.
// while: �ݺ��� Ƚ���� ��Ȯ���� ���� ��� ����մϴ�.

int main()
{
    int count = 0;

    // while (count < 10) {
    //     printf("%d\n", count);

    //     if (count == 5)
    //         continue;

    //     ++count;
    // }

    for (count = 0; count < 10; ++count) {
        printf("%d\n", count);

        if (count == 5)
            continue;

        //...
    }
}