// 9_�ݺ���2.c
#include <stdio.h>

// ����ڰ� -1�� �Է��� ������ ��� ������ �Է¹޾Ƽ�,
// �Էµ� ��� ������ ���� ���ϴ� ���α׷��� �ۼ��غ��ô�.

int main()
{
    int n = 0;

    int sum = 0;

#if 1
    while (n != -1) {
        scanf("%d", &n);

        if (n != -1) {
            sum += n;
        }
    }
#endif

#if 0    
    while (1) {
        scanf("%d", &n);

        if (n == -1)
            break;

        sum += n;
    }
#endif

    printf("sum: %d\n", sum);

    return 0;
}