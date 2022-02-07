// 5_알고리즘3


#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

int main()
{
	std::list<int>   s = { 1,6,3,4,5 };

	// ex1. s에서 처음나오는 짝수를 찾아보세요.. "람다표현식"으로 하세요

//	auto p2 = std::find_if(s.begin(), s.end(), [](int n) { return n % 2 == 0; });

	int num;
	std::cin >> num;

	// ex2. s에서 1번째 나오는 num 의 배수를 찾아보세요.
	// => 람다 표현식에서 지역변수에 접근하려면 "지역변수를 캡쳐(capture)" 해야 합니다.
	// => 지역변수 캡쳐 - [] 안에 num 을 넣습니다.
	//				   - [a, b, c] : 여러개 캡쳐
	//				   - [=]       : 모든 지역변수 캡쳐
	//				   - [&a]	   : 참조로 캡쳐, 지역변수 변경 가능
	//				   - [am &b]   : a는 참조 아님, b는 참조
	//				   - [&]	   : 모든 지역변수 참조 캡쳐
	//				   - [&, a]    : 모든 지역변수 참조 캡쳐, a는 value 캡쳐
	//				   - [=, &b]   : 모든 지역변수 value 캡쳐, b는 참조 캡쳐
	auto p2 = std::find_if(s.begin(), s.end(), [num](int n) { return n % num == 0; }); 


	if (p2 == s.end())
		std::cout << "검색 실패 " << std::endl;
	else
		std::cout << "검색 성공 " << *p2 << std::endl;

}



