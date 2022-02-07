// 6_레퍼런스1 41 page


#include <iostream>

int main()
{
	int n = 10;

	// - Reference
	// 1) 기존의 변수에 이름을 하나 더 부여함.
	int* p = &n; 
	int& r = n;

	r = 20;

	std::cout << n  << std::endl;
	std::cout << &n << std::endl;
	std::cout << &r << std::endl; // r의 주소와 n의 주소는 같음 (같은 변수에 이름을 하나 더 부여한 것이므로)

//	int& r1;					  // 2) error. 레퍼런스(참조)는 반드시 초기화 되어야한다.
}