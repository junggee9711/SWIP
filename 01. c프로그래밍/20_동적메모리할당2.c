#include <stdio.h>


int* foo() {
	int score = { 10, 20, 30, 40, 50 };
	return score;
}

int main()
{
		
}// 20_�����޸��Ҵ�2.c
#include <stdio.h>

// 1. ���� �޸� �Ҵ�
//   malloc / free
// 2. ���� �޸� �Ҵ��� ����� �����Ͱ� ��ȯ�˴ϴ�.
// 3. ������ ���, NULL�� ��ȯ�մϴ�.
// 4. ���� ������ ���α׷��Ӱ� ���� �� �� �ִ�.
// 5. �޸� ������ ���� ���� ���, �޸� ������ �߻��ϰ�
//    ���Ŀ� ������ ������ �� �� �ֽ��ϴ�.
// 6. malloc�� �޸� �Ҵ� �߿� ���� ���� �ð��� �Ҹ�˴ϴ�.

#include <stdlib.h> // malloc, free, exit

int* foo()
{
    int score[5] = { 10, 20, 30, 40, 50 };
    return score;
}
// ������: ������ �޸��� �ּҸ� ��ȯ�մϴ�.
//  => ���� ������ �ּҸ� ��ȯ�ϸ� �ȵ˴ϴ�.

// 1. ���� ���� ����
// => �Լ��� ���� ���� �Ǵ� ���� ���� ������ �����ϴ� ���
//    �Լ��� �������� �Ұ����մϴ�.
//   : ������ ������, ���
int* goo()
{
    static int score[5] = { 10, 20, 30, 40, 50 };
    // ...
    return score;
}

// 2. ���� �޸� �Ҵ�
// => ������(reentrant) �����ϴ�.
// : ����ڰ� �ݵ�� free ���־�� �մϴ�.
int* hoo()
{
    // int[5]�� ����ϰڴٴ� �ǵ�
    int* score = (int*)malloc(sizeof(int) * 5);

    return score;
}

int main()
{
    int* p2 = hoo();
    p2[0] = 100;

    free(p2);

    // int* p = (int *)malloc(sizeof(int));
    int* p = NULL;

    // �̸� ���ǵ� ��ũ�θ� �����մϴ�.
    // __FILE__ / __LINE__ / __func__
    if (p == NULL) {
        printf("�޸� �Ҵ��� �����Ͽ����ϴ�.\n> %s:%d - %s\n",
            __FILE__, __LINE__, __func__);
        exit(1);
    }

    return 0;
}