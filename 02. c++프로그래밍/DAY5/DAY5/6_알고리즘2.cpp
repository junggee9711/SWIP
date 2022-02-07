// 5_알고리즘2 - 227page


#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::list<int>   s = { 1,6,3,4,5 };

	// 1. 주어진 구간에서 3을 찾고 싶다. => "값 검색"
	//	=> std::find() : "값 검색"
	auto p1 = std::find(s.begin(), s.end(), 3);

	// 2. 주어진 구간에서 처음 나오는 3의 배수를 찾고 싶다. => "조건 검색"
	//  => std::find _if() : "조건 검색"
	// auto p2 = std::find(s.begin(), s.end(), "함수" );
	//  => "조건"을 "함수"로 전달

	auto p2 = std::find_if(s.begin(), s.end(), foo );
	//  => foo() 함수는 인자를 list 의 "요소 type" 으로 받고, "bool" 을 return 한다.

	// 3. C++ 부터, 함수 보다 "람다표현식"을 사용하는 것이 좋습니다.
	//  => [] : 람다표현식이 시작됨을 알리는 "lambda introducer"
	auto p2 = std::find_if(s.begin(), s.end(), [](int n) { return n % 3 == 0; });
	//  => "[](함수인자) { 함수내용 }" 의 형태로 람다 표현식 사용
	//  => 가독성이 좋고, 진짜 함수를 사용하는 것보다 약간 더 빠릅니다. 
	//     (컴파일러가 자동으로 해당 함수를 만들고, find_if 내부에서 인라인 치환됩니다.)


	if (p2 == s.end())
		std::cout << "검색 실패 " << std::endl;
	else
		std::cout << "검색 성공 " << *p2 << std::endl;

}



