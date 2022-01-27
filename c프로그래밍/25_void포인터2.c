#include <stdio.h>

// Ÿ�Կ� �Ϲ����� swap �� ���� �� �ֽ��ϴ�.
// 1. ��ũ�� �Լ� Ȱ��
// 2. void* Ȱ��

// ��ũ�� �Լ��� �ۼ��� ��,
// ���� ���� ������ �ϳ��� �Լ��� �ۼ��Ѵٸ�
// => do-while(0) �� ����մϴ�. (����, �����ݷ� ����)
#define SWAP(a, b, type) do {\
	type temp = a;		\
	a = b;				\
	b = temp;			\
}while(0)

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{

	int a = 10;
	int b = 20;

	SWAP(a, b, int); // �̿Ͱ��� int �� �Է����� ���� �ִ°� ��ũ���Լ��� 'ġȯ' ���� �۵��ϱ� ������!

	printf("%d, %d\n", a, b);

	double da = 10;
	double db = 20;

	SWAP(da, db, double); // define ���� �����ݷ��� �����߱� ������ �����ݷ��� ������

	if (b < a)
		SWAP(a, b, int);

	printf("%d, %d\n", a, b);
	return 0;
}
