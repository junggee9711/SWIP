// 15 page �Ʒ� �κ�

#include <iostream>
#include <iomanip> // 1. C++ �� "�پ��� ����� ������ �Լ�"�� ���� ���
				   //   -> "i/o manipulator (������)"

int main()
{
	int n = 10;

	std::cout << n << std::endl; // 10 ����

	std::cout << std::hex << n << std::endl; // 16 ����
	std::cout << std::dec << n << std::endl; // 10 ������ �ٽ� �ٲ�

	std::cout << std::setw(10) << n << std::endl; // n �� 10�ڸ��� ����

	std::cout << std::setw(10) << std::setfill('#') << n << std::endl; // n �� 10�ڸ��� ���߰� '#'���� ä��
}
// cppreference.com ���� "setw" ã�ƺ����� - 1��° ��ũ