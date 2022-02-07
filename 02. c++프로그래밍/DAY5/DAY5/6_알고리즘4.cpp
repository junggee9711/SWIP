// 5_알고리즘4


#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 


int foo(int a, int b)
{
	return a + b;
}

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5 };	// list 등 다른 컨테이너도 가능
	std::vector<int> v3 = { 0,0,0,0,0 };

	// - transform 알고리즘 : 2개의 컨테이너를 "주어진 연산" 후에 다른 컨테이너에 넣기

	std::transform(	v1.begin(), v1.end(),
					v2.rbegin(),			// v2 의 가장 뒤의 값부터 연산
					v3.begin(),				// end값은 v1 만으로 알수 있기때문에 v1 만 적음
					//foo);
					// [](int a, int b) {return a * b; });
					[](int a, int b) -> int {return a * b; });	// <== 후위반환타입 사용.
	// 1. "함수" 사용할때 : 이 경우 foo 의 return 값은 bool 이 아닌 "int" 여야 함.
	// 2. "람다표현식" 사용시,
	//	- 람다표현식 반환 타입 1) 생략시 컴파일러가 return 문으로 추론
	//						 2) 반환타입을 표기하려면 "suffix return type(후위반환타입)" 사용

	for (auto n : v3)
		std::cout << n << std::endl;
}



