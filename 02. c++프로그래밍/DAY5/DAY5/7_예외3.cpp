// 8_����3


#include <iostream>

// 3. ���ܸ� �������� ����� ���� Ÿ���� ���� ������ ���� ��Ģ�Դϴ�.
class DisconnectWifi
{
	// �پ��� ���� ������ ��Ƽ� �����ϼ���
};
class MemoryException
{
	// �پ��� ���� ������ ��Ƽ� �����ϼ���
};

int ConnectServer()
{
	if (1) {
//		throw 1;			
		MemoryException e;
		throw e;
	}

	return 0;
}


int main()
{


	try
	{
		int ret = ConnectServer();
		std::cout << "������ ���ܰ� �߻����� �ʾƾ� ���Ⱑ ���� �˴ϴ�." << std::endl;
	}
	catch (const MemoryException& e)
	{
		std::cout << "���� �߻�" << std::endl;

	}
	catch (const DisconnectWifi& e)
	{
	}
//	catch (...)	// ������ ������ ���� ��� ���� ó��

	std::cout << "���α׷� ��� ����" << std::endl;

}