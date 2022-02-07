// 6_���۷���4

#include <iostream>
#include <algorithm>			// �� �ȿ� �̹� ǥ�� swap �� �ֽ��ϴ�.

void swap(int* p1, int* p2)		// pointer �� ����
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// C++ ��� ����
namespace utils
{
	template<typename T>
	inline void swap(T& r1, T& r2)	// reference �� ����
	{
		int temp = r1;
		r1 = r2;
		r2 = temp;
	}
}

int main()
{
	int x = 10, y = 20;
//	swap(&x, &y);				
//	utils::swap<int>(x, y);
	std::swap<int>(x, y);			// <algorithm> ����� �ִ� std::swap ���

	std::cout << x << std::endl;
	std::cout << y << std::endl;
}