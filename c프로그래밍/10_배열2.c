#include <stdio.h>

// ������ �迭

// 3���� 5������ ������ �Է¹ް� �ͽ��ϴ�.
// 1. ������ �迭
#if 0
int main()
{
    // [0 1 2 3 4][5 6 7 8 9][10 11 12 13 14]
    int score[15] = {
        0,
    };

    for (int i = 0; i < 15; ++i) {
        int person = i / 5;
        int subject = i % 5;

        scanf("%d", &score[i]);

        printf("%d ��° ��� / %d��° ����\n",
            person + 1, subject + 1);
    }
}
#endif

// 2. ������ �迭
// [0 1 2 3 4][5 6 7 8 9][10 11 12 13 14]
int main()
{
    int score[3][5];
    // [ int[5] ][ int[5] ][ int[5] ]
    //     0         1         2        : i
    //   01234     01234      01234     : j

    // �迭�� ������ŭ �ݺ��մϴ�.
    for (int i = 0; i < 3; ++i) {

        // �迭 ������ �迭�� ������ŭ �ݺ��մϴ�.
        for (int j = 0; j < 5; ++j) {
            printf("%d��° %d����\n", i + 1, j + 1);
        }
    }
}