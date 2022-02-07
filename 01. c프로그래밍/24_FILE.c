// 24_FILE.c
#include <stdio.h>

// 표준 입출력 장치
// - stdin  => 표준 입력 장치 파일(키보드)
// - stdout => 표준 출력 장치 파일(모니터)
// - stderr => 표준 에러 장치 파일(모니터)

// => 버퍼링의 정책이 다릅니다.
//  stdout => Line 버퍼링
//           '\n'이 있어야 출력됩니다.
//  stderr => 버퍼링을 하지 않습니다.

int main()
{
    // printf("hello\n");
    fprintf(stderr, "hello");

    while (1)
        ;

    return 0;
}

#if 0
int main()
{
    int num;
    // scanf("%d", &num);
    fscanf(stdin, "%d", &num);

    printf("num: %d\n", num);

    // printf("Hello, world\n");
    // fprintf(stdout, "Hello, World\n");
    fprintf(stderr, "Hello, World\n");

    return 0;
}
#endif