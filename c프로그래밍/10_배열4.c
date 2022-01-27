// 10_�迭4.c
#include <stdio.h>

// C89: �迭�� ũ��� �ݵ�� ������ �ð��� �����Ǿ�� �մϴ�.
// C99: �迭�� ũ��� ������ ����� �� �ֽ��ϴ�.
#if 0
int main()
{
    int n = 10;

    int arr2[10];
    // > �迭�� ũ�Ⱑ ������ Ÿ�ӿ� �����˴ϴ�.

    scanf("%d", &n);
    int arr[n]; // ?
    // > �迭�� ũ�Ⱑ ��Ÿ�ӿ� �����˴ϴ�.

    // C89 ǥ���� ����
    // C99 ǥ���� Ok

    printf("%lu\n", sizeof(arr));
}
#endif

// �迭�� ũ�⸦ ��� ���.
// - sizeof
// �迭�� ������ ���ϴ� ���
// - sizeof(arr) / sizeof(int)
// - sizeof(arr) / sizeof(arr[0])
//  : �迭�� Ÿ���� ����Ǿ��� ���, ���� ǥ���Ŀ� ���ؼ� ������
//    ������ �ʿ����� �ʽ��ϴ�.
int main()
{
    int arr[20];
    // 4����Ʈ ũ�⸦ ������ �޸𸮸� 20�� �������� �Ҵ��մϴ�.
    // => 80byte

    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(arr) / sizeof(int)); // 1
    printf("%lu\n", sizeof(arr) / sizeof(arr[0])); // 2
}