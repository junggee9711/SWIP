
#include <errno.h> // errno 전역 변수
#include <stdio.h>
#include <string.h> // strerror

// 1. errno
//  => 표준 함수에서 오류가 발생했을 때,
//     전역 변수 errno가 0이 아닌 값으로 변경됩니다.

// 2. strerror
//  => strerror 함수를 통해 errno가 어떤 의미인지 문자열을
//     얻을 수 있습니다.

// 3. perror
//  => errno / strerror를 하나의 함수로 처리해서 제공합니다.

// 4. 파일로부터 데이터를 읽을 때,
//  => Ctrl + D / Ctrl + Z : EOF(End of File)

// 5. fgets : 라인을 입력 받습니다.
// char * fgets(char * str, int size, FILE * stream);

int main()
{
    FILE* fp = fopen("1_시작.c", "r");
    if (fp == NULL) {
        // fprintf(stderr, "fopen 실패 - %d\n", errno);
        // char* reason = strerror(errno);
        // fprintf(stderr, "fopen 실패 - %s\n", reason);
        perror("fopen");
        return 1;
    }

    FILE* out = fopen("out.c", "w");
    if (out == NULL) {
        perror("fopen");
        return 1;
    }

    char buf[64] = {
        0,
    }; // 전체를 0으로 초기화
    while (1) {
        char* s = fgets(buf, sizeof buf, fp);
        if (s == NULL)
            break;
        // printf("%s", buf);
        // fputs(buf, stdout);

        fputs(buf, out);
    }

#if 0
    while (1) {
        // 파일의 끝에 도달하면, 입력을 종료해야 합니다.
        int ret = fscanf(fp, "%s", buf);
        if (ret == EOF) // -1
            break;

        printf("%s\n", buf);
    }
#endif

    fclose(out);
    fclose(fp);

    return 0;
}