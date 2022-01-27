#include <stdio.h>

// stdin
// stdout => FILE* 입니다.
// stderr
// 1. fopen("파일 경로", "모드")
//   "r": 읽기 모드
//   => 경로에 파일이 존재하지 않으면, 실패합니다.
//   "w": 쓰기 모드
//   => 경로에 파일이 존재하지 않으면, 새로운 파일을 만듭니다.
//      경로에 파일이 존재하면, 파일의 크기를 0으로 변경해서
//      열어줍니다.

// 2. fprintf(FILE*, format, ...);
// 3. 파일은 자원이기 때문에, 반드시 fclose를 통해
//    닫아주어야 합니다.

int main()
{
    FILE* fp = fopen("a.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "File open error...\n");
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        fprintf(fp, "Hello\n");
    }

    fclose(fp);

    return 0;
}