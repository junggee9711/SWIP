#include <stdio.h>

// Unix / Linux => POSIX ǥ��

// printf("...") : ���۸� => FILE*
//   |
//  write => int 80 / syscall 80
//   |
// ----------- ������� -> Ŀ�θ��
//   |
// sys_write
//   |
// do_write
//   |
//  ����� / ���� �ý��� / ���� / ����̽� ����

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