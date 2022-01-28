// 8_����2
 
// 2. C++ : throw & catch ���

#include <iostream>

int ConnectServer()
{
	if (1)
		throw 1;				// �Լ��� �����ϸ�,
								// "���ܶ�� ���� �����ϴ�."
								// => ��ȯ ���� ������ �и��˴ϴ�.

	return 0;
}


int main()
{
	// �Ʒ��� ���� ȣ���ڰ� "������ ����" �� ó������(����) ������ ���α׷��� ������ ���� �˴ϴ�.
//	int ret = ConnectServer();

	try
	{
		int ret = ConnectServer();
		std::cout << "������ ���ܰ� �߻����� �ʾƾ� ���Ⱑ ���� �˴ϴ�." << std::endl;
	}
	catch (int n)			// <== ConnectServer() ���� throw �� ���� ���ڷ� ����
	{
		std::cout << "���� �߻�" << std::endl;
		// ���� �Ұ����� ���ܶ�� ���⼭ �����ϼ���. exit(-1) ���� ����ؼ� ����.
		// ���� �����ϸ� �����ϼ���.
	}
	std::cout << "���α׷� ��� ����" << std::endl;

	/* ���蹮�� : ���ܸ� ������/������ ���� Ű���带 ������. throw/catch */
}