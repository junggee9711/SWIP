
#include <errno.h> // errno ���� ����
#include <stdio.h>
#include <string.h> // strerror

// 1. errno
//  => ǥ�� �Լ����� ������ �߻����� ��,
//     ���� ���� errno�� 0�� �ƴ� ������ ����˴ϴ�.

// 2. strerror
//  => strerror �Լ��� ���� errno�� � �ǹ����� ���ڿ���
//     ���� �� �ֽ��ϴ�.

// 3. perror
//  => errno / strerror�� �ϳ��� �Լ��� ó���ؼ� �����մϴ�.

// 4. ���Ϸκ��� �����͸� ���� ��,
//  => Ctrl + D / Ctrl + Z : EOF(End of File)

// 5. fgets : ������ �Է� �޽��ϴ�.
// char * fgets(char * str, int size, FILE * stream);

int main()
{
    FILE* fp = fopen("1_����.c", "r");
    if (fp == NULL) {
        // fprintf(stderr, "fopen ���� - %d\n", errno);
        // char* reason = strerror(errno);
        // fprintf(stderr, "fopen ���� - %s\n", reason);
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
    }; // ��ü�� 0���� �ʱ�ȭ
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
        // ������ ���� �����ϸ�, �Է��� �����ؾ� �մϴ�.
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