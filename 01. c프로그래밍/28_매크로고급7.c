
// assert: �ܾ�
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
#define assert(expr)                                \
    do {                                            \
        if (!(expr)) {                              \
            printf("assertion failed: %s, %s:%d\n", \
                #expr, __func__, __LINE__);         \
            abort();                                \
        }                                           \
    } while (0)
#endif

// ������ �ð��� ǥ������ ��ȿ���� Ȯ���ϴ� ����� ������ �� �ֽ��ϴ�.
#define static_assert(expr) \
    char __static_assert_failed[(expr) ? 1 : -1];
// ������ �ð��� �ǴܵǴ� ǥ������ �����
// ������ ���, ���� ũ�⸦ ������ �迭�� ����
// �ǵ������� ������ ������ �߻���Ű�� ����Դϴ�.

int main()
{
    static_assert(sizeof(long) == 8);

    int age;
    scanf("%d", &age);

    int next;
    if (age > 0)
        next = next + 1;
    else
        next = 0;

    // ���� ������
    next = (age > 0) ? next + 1 : 0;

    // age�� ����̾�߸� ����� �����ϴ� �ڵ��Դϴ�.
    // if (age < 0)
    //   abort(); // ������ ����

    assert(age > 0);
    printf("run...\n");
}