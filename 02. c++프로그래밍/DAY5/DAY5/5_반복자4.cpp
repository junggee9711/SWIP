// 4_반복자4

#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. 정방향 반복자
//	auto p1 = s.begin();		
//	auto p2 = s.end();			

	// 2. 역방향 반복자
//	auto p1 = s.rbegin();		// 가장 뒤에가 시작점
//	auto p2 = s.rend();			// 가장 앞이 끝점

	// 3. 상수, 정방향 반복자
	auto p1 = s.cbegin();		// std::cbegine(s) <== 일반함수 버전
	auto p2 = s.cend();		

//	*p1 = 10;					// error. 상수 반복자는 읽기만 가능.

	// 4. 상수, 역방향 반복자
	auto p1 = s.crbegin();		// std::crbegin(s)
	auto p2 = s.crend();		

//  *p1 = 10;					// error. 상수 역방향 반복자는 읽기만 가능.


	while (p1 != p2)	
	{
		std::cout << *p1 << std::endl;
		++p1;					// p1 이 reverse iterator 라면 ++연산은 뒤->앞으로 이동
	}

}


