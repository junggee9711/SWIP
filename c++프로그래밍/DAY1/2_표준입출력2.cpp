// 15 page 아래 부분

#include <iostream>
#include <iomanip> // 1. C++ 의 "다양한 입출력 조정자 함수"를 위한 헤더
				   //   -> "i/o manipulator (조정자)"

int main()
{
	int n = 10;

	std::cout << n << std::endl; // 10 진수

	std::cout << std::hex << n << std::endl; // 16 진수
	std::cout << std::dec << n << std::endl; // 10 진수로 다시 바꿈

	std::cout << std::setw(10) << n << std::endl; // n 을 10자리에 맞춤

	std::cout << std::setw(10) << std::setfill('#') << n << std::endl; // n 을 10자리에 맞추고 '#'으로 채움
}
// cppreference.com 에서 "setw" 찾아보세요 - 1번째 링크