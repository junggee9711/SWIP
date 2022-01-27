#include <stdio.h>

// Unix / Linux => POSIX 표준

// printf("...") : 버퍼링 => FILE*
//   |
//  write => int 80 / syscall 80
//   |
// ----------- 유저모드 -> 커널모드
//   |
// sys_write
//   |
// do_write
//   |
//  모니터 / 파일 시스템 / 소켓 / 디바이스 파일

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
    // printf("hello\n");
    write(1, "hello\n", 7);

    FILE* fp = fopen("a.txt", "w");
    write(3, "hello xxxxxx\n", strlen("hello xxxxxx\n"));
    // fprintf(fp, "hello\n");

    // fclose(fp);
    // close(3);
}