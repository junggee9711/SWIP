#include <iostream>

template<typename T>
T add(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << add<int>(1, 2)		<< std::endl; // 정확한 표기법

	// 타입인자 생략 가능 (타입 자동 추론)
	std::cout << add<(1, 2)		<< std::endl;
	std::cout << add(1.3, 2.8)  << std::endl; 


	std::cout << add(1, 2.8)		 << std::endl;	  // error. 타입을 결정할수 없다.
	std::cout << add<double>(1, 2.8) << std::endl;	  // ok.
}