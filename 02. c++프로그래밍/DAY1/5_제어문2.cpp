// 5_���2 39 page

// 2. �ʱ�ȭ ������ ���� ���

int foo()
{
	return 0;
}

int main()
{
	int ret = foo();
	if (ret == 0) {
	}
	// ----------------------------

	// C++17 ���� "init if" ��� ���� ����
	// => ret ������ �Լ��� �������� �ƴ϶�, if ���� ������ �ٷ� �ı���
	if (int ret = foo(); ret == 0) {
	}

	switch (int n = foo(); n)
	{
		case 1: break;
		case 2: break;
	}
}