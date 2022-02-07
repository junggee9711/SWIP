#include <stdio.h>

// 다차원 배열

// 3명의 5과목의 점수를 입력받고 싶습니다.
// 1. 일차원 배열
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

        printf("%d 번째 사람 / %d번째 과목\n",
            person + 1, subject + 1);
    }
}
#endif

// 2. 다차원 배열
// [0 1 2 3 4][5 6 7 8 9][10 11 12 13 14]
int main()
{
    int score[3][5];
    // [ int[5] ][ int[5] ][ int[5] ]
    //     0         1         2        : i
    //   01234     01234      01234     : j

    // 배열의 개수만큼 반복합니다.
    for (int i = 0; i < 3; ++i) {

        // 배열 내부의 배열의 개수만큼 반복합니다.
        for (int j = 0; j < 5; ++j) {
            printf("%d번째 %d과목\n", i + 1, j + 1);
        }
    }
}