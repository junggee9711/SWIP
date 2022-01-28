// 3_STL1 - 213 page

#include <iostream>
#include <vector>
#include <list>

int main()
{
	// - 배열 vs vector
	//  1. 배열 단점 : 크기 변경이 안된다.
	int x[5] = { 1,2,3,4,5 };

	//  2. vector 
	//	 1) 배열처럼 연속된 메모리, []로 접근 가능
	std::vector<int> v = { 1,2,3,4,5 };

	v[0] = 10;
	v.resize(10);				// 2) vector 는 크기 변경 가능

	std::vector<int> v2(10, 2); // 크기 10, 10개를 모두 2로 초기화..


	v2.resize(7);				// 크기 7로 줄이기..
								// 실제 메모리는 줄지(7로 재할당하지) 않습니다. 
								// 다만, class 내 size 변수를 7로 바꿈
	std::cout << v2.size()     << std::endl;	// 7
	std::cout << v2.capacity() << std::endl;	// 10 (메모리 사용량)

	v2.push_back(5);			// 끝에 5 라는 값 한개 추가. 비싼(expensive) 연산 일까요?
								//							싼(cheap) 연산 일까요?
								//	=> 8번째 자리에 추가만 하면 되고, 따로 메모리할당 없음 = "싼"연산
	std::cout << v2.size() << std::endl;		// 8
	std::cout << v2.capacity() << std::endl;	// 10 (메모리 사용량)

	v2.shrink_to_fit();			// 여분의 메모리를 제거해 달라.
								// => 8개 메모리를 따로 할당 후, 값을 복사해서 저장
	std::cout << v2.size() << std::endl;		// 8
	std::cout << v2.capacity() << std::endl;	// 8 (메모리 사용량)

	v2.push_back(3);			// 끝에 3 이라는 값 한개 추가.
								// => 메모리를 새로 할당하므로 "비싼"연산
								// => 메모리를 1 늘리는 것이 아니라, 여유롭게 1.5배 or 2배로 늘려놓음
								// why?) 값을 추가할때마다 메모리를 할당하면 비싼 연산이 되므로, 미리 할당. 
	std::cout << v2.size() << std::endl;		// 9
	std::cout << v2.capacity() << std::endl;	// ?? (메모리 사용량)

	// capacity : 실제 메모리 사용량
	// size		: 요소의 갯수
	// => 이 둘은 모두 vector class 의 멤버변수

	std::vector<int> v3;		// 메모리 할당 안함
	v3.push_back(1);			// 이때 1개 버퍼 할당
	v3.push_back(1);			// 2개 버퍼
	v3.push_back(1);			// 4개 버퍼 (컴파일러에따라 2배 or 1.5배로 다를수 있음)	

	v3.reserve(100);			// 메모리는 100개로 키워 놓아라!!
								// => 앞으로 요소추가가 많을것이라는 예상이 있다면 capacity 를 키움
	std::cout << v3.size()     << std::endl;	// 3
	std::cout << v3.capacity() << std::endl;	// 100 (메모리 사용량)

}





