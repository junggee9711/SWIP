// 37 page

// C�� �ٸ� C++�Լ��� Ư¡ 6. ���� ��ȯ Ÿ��



int add1(int a, int b)
{
	return a + b;
}

// - suffix return type �Ǵ� trailing return type
// 1) C++11 ���� ���� ���ο� �Լ� ���
// 2) Python ���� def add(a:int, b:int) -> int: �� ����

auto add2(int a, int b) -> int // add1, add2 �� ����
{
	return a + b;
}

int main()
{
	int n = add1(1, 2);
}