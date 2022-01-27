#include <iostream>

template<typename T>
T add(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << add<int>(1, 2)		<< std::endl; // ��Ȯ�� ǥ���

	// Ÿ������ ���� ���� (Ÿ�� �ڵ� �߷�)
	std::cout << add<(1, 2)		<< std::endl;
	std::cout << add(1.3, 2.8)  << std::endl; 


	std::cout << add(1, 2.8)		 << std::endl;	  // error. Ÿ���� �����Ҽ� ����.
	std::cout << add<double>(1, 2.8) << std::endl;	  // ok.
}