// 5_알고리즘1 - 225 page

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>	// find() 와 같은 "일반함수(알고리즘)" 템플릿 

int main()
{
	std::list<int>   s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	// 1. 위 컨테이너에서 '3'을 찾아 봅시다.
//	s.find(3);
//	v.find(3);			// 이런 멤버함수가 있다면 사용하기 쉽고, 직관적입니다.
						// 하지만, 이렇게 만들면, 모든 컨테이너에 find 를 만들어야 합니다.

	// 2. C++ 은 "반복자" 를 모든 컨테이너에 만들고, 
	//   find()와 같은 함수를 "일반함수" (not, 멤버함수) 로 만들어, 여기에 "반복자"를 사용할 생각을 함.

	// 3. find 는 모든 "선형컨테이너"에 사용가능한, 멤버함수가 아닌 "일반함수"입니다.
	//   => 이런 함수를 STL 에서 "알고리즘"이라고 합니다. 
	//   => <algorithm> 헤더에 포함되어있습니다.
	auto ret1 = std::find(s.begin(), s.end(), 3);
	auto ret2 = std::find(v.begin(), v.end(), 3);

	// 4. find()의 반환값은,	
	//   1) 검색 성공시 요소를 가리키는 반복자 (포인터라고 생각)
	//   2)	   	 실패시 "past the end" 입니다 (s.end() 입니다)

	if (ret1 == s.end())
		std::cout << "검색 실패" << std::endl;
	else
		std::cout << "검색 성공" << *ret1 << std::endl;
	// ret1 을 포인터로 생각하기 때문에, *ret1 으로 출력

	/* 시험문제 : "STL의 알고리즘은 다양한 컨테이너들이 제공하는 "멤버함수"들을 말한다." 
				 false. 알고리즘은 멤버함수가 아닌 "일반함수"임 */
}



