#include <stdio.h>

#if 0
int main()
{
    int a, b, c, d, e;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);

    return 0;
}
#endif

// �迭: ������ Ÿ���� ���� ���� �޸𸮸� ���������� �Ҵ��մϴ�.
// - �ϳ��� �̸��� �ϳ��� �ε����� ���� �ش� �޸𸮿� ������ �����մϴ�.
#if 0
int main()
{
    int n; // int
    int arr[5]; // int[5];

    // int Ÿ�� �޸𸮸� 5�� �������� �Ҵ��մϴ�.
    // ������ �޸𸮸� �ε��� ÷�� ������ ���� ������ �� �ֽ��ϴ�.
    // arr[0] / arr[1] / arr[2] / arr[3] / arr[4]

    int i;
    for (i = 0; i < 5; ++i) {
        scanf("%d", &arr[i]);
    }

    return 0;
}
#endif

// �迭�� �ʱ�ȭ
int main()
{
    int i = 0;

    int x1[5];
    // �����Ⱚ�� ������ ���·� �ʱ�ȭ�˴ϴ�.
    printf("%d\n", x1[3]);

    int x2[5] = {
        1,
        2,
        3,
        4,
        5,
        // 6,
    };

    for (i = 0; i < 5; ++i) {
        printf("%d\n", x2[i]);
    }

    int x3[5] = { 1, 2, 3 };
    // �������� 0���� �ʱ�ȭ�˴ϴ�.

    int x4[5] = {
        0,
    };

    for (i = 0; i < 5; ++i) {
        printf("%d\n", x4[i]);
    }

    return 0;
}