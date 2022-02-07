// 6_레퍼런스4

#include <iostream>
#include <algorithm>			// 이 안에 이미 표준 swap 이 있습니다.

void swap(int* p1, int* p2)		// pointer 로 구현
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// C++ 언어 버전
namespace utils
{
	template<typename T>
	inline void swap(T& r1, T& r2)	// reference 로 구현
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
	std::swap<int>(x, y);			// <algorithm> 헤더에 있는 std::swap 사용

	std::cout << x << std::endl;
	std::cout << y << std::endl;
}