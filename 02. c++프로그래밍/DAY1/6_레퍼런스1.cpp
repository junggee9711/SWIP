// 6_���۷���1 41 page


#include <iostream>

int main()
{
	int n = 10;

	// - Reference
	// 1) ������ ������ �̸��� �ϳ� �� �ο���.
	int* p = &n; 
	int& r = n;

	r = 20;

	std::cout << n  << std::endl;
	std::cout << &n << std::endl;
	std::cout << &r << std::endl; // r�� �ּҿ� n�� �ּҴ� ���� (���� ������ �̸��� �ϳ� �� �ο��� ���̹Ƿ�)

//	int& r1;					  // 2) error. ���۷���(����)�� �ݵ�� �ʱ�ȭ �Ǿ���Ѵ�.
}