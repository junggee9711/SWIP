// 24_FILE.c
#include <stdio.h>

// ǥ�� ����� ��ġ
// - stdin  => ǥ�� �Է� ��ġ ����(Ű����)
// - stdout => ǥ�� ��� ��ġ ����(�����)
// - stderr => ǥ�� ���� ��ġ ����(�����)

// => ���۸��� ��å�� �ٸ��ϴ�.
//  stdout => Line ���۸�
//           '\n'�� �־�� ��µ˴ϴ�.
//  stderr => ���۸��� ���� �ʽ��ϴ�.

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