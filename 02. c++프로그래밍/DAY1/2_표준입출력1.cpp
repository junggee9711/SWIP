// 2_ǥ�������1.cpp - 12 page

#include <cstdio>
#include <iostream> // 1. std::cout, std::cin �� ���� ���, printf �� ����

int main()
{
	int	n = 10;
	double d = 3.4;

	// C ǥ�� ��� �Լ�
	printf("%\n", n);

	// C++ ǥ�� ��� "��ü" - printf ��� �Լ��� �ҷ����� ���� �ƴ϶�, std::cout ��ü�� �ҷ���
	std::cout << n << ", " << d << std::endl; // '\n'; ��� std::endl �� ����ϴ� ���� ����
											  // %d �� ���� ���� Ÿ�� ���� �ʿ� ����

	// ǥ�� �Է�
	scanf_s("%d", &n); // C

	std::cin >> n; // C++
				   // �ٽ� : "&n" �� �ƴ϶� "n"
				   //        ">>" ���⿡ ���� �ϼ���.
}