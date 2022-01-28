// 4_반복자2
#include <iostream>
#include <vector>
#include <list>

class vector_iterator {};


template<typename T> class vector
{
public:
	// class 안에 class 를 내포할수 있고,
	// 이것에 접근하려면 "std::vector<int>::iterator" 이런 표기법을 사용해야 함
	class iterator {};
	// 또는 typedef
	typedef vector_iterator iterator;
};


int main()
{
//	std::vector<int> c = { 1,2,3,4,5 };   // 1
//	std::list<int>   c = { 1,2,3,4,5 };   // 2

	int c[5] = { 1,2,3,4,5 };			  // 3

	// 1. 반복자의 정확한 타입 : "std::vector<int>::iterator"
	//	 - C++98 시절에는 이렇게 코딩했어야 합니다.
	//    단점 1) 너무 복잡해 보입니다.
	//         2) 컨테이너 변경시 코드가 수정되어야 합니다.
	std::vector<int>::iterator p = c.begin();		// <== 1, 2 로 적용 (3 이면 error)

	// 2. C++11 부터는 auto 가 편합니다.
	auto p = c.begin();								// <== 1, 2 로 적용 (3 이면 error)
	// => 모든 STL 컨테이너에 대해 동작하지만, c가 "일반 배열(raw array) 라면 error.

	// 3. 멤버함수 begin() 보다 일반 함수 begin()이 좋습니다.
	auto p = std::begin(c);							// <== 일반함수 begin() 적용.
	//	 1) c 가 STL 컨테이너라면, 처음을 가리키는 반복자 반환
	//   2) raw array 라면, 배열의 1번째 요소 주소 반환


	// <정리>
	// 1. 반복자를 꺼낼대 멤버함수 begin() 보다 일반함수 begin() 이 좋다.
	// 2. 반복자를 받을때 "정확한 타입"을 적는것 보다 "auto" 가 좋다.
	/* 시험문제 : std::vector<int>::iterator p = c.begin(); 이 표기법이 문제로 나오면 맞는 표기법임 */
}

// cppreference.com 에서 "std::begin" 해보세요 
// => <iostream> 에 raw array 를 위한 std::begin 이 있습니다.
