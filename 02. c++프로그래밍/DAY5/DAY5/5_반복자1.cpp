// 4_반복자1 - 220 page
#include <iostream>
#include <vector>
#include <list>

int main()
{
	int x[5] = { 1,2,3,4,5 };

	// 1. 배열은,
	// 1) [] 을 사용하거나
	// 2) 첫번째요소의 주소를 알면 모든 요소를 순회 할 수 있습니다.
	int* p1 = x;
	++p1;					// 3) 다음 요소로 이동 가능합니다.



	std::list<int> s = { 1,2,3,4,5 };

	// 2. STL 은 "반복자"만 있으면 ++로 모든 요소를 열거할수 있습니다.
	auto p2 = s.begin();	// => 이렇게 반복자를 return 할 수 있음.

	// 1) p2 는 진짜 포인터는 아니고, 객체지만,
	//    포인터처럼 동작하게 하려고 operator++(), operator*() 연산자가 재정의 되어있습니다.
	//   => p2 를 포인터처럼 생각하고 사용하면 됩니다.

	std::cout << *p2 << std::endl;

	++p2;					// 다음으로 이동.
	std::cout << *p2 << std::endl;
	
	// 2) 반복자 (iterator) 의미
	//   : 컨테이너의 내부구조에 상관없이 동일한 방식으로 열거하게 하자!
}



#if 0
// - 반복자의 개념 
class iterator
{
	// 멤버로 포인터가 있습니다.
	Node* current;
public:
	iterator(Node* p) : current(p) {}
};
iterator p2(100);
++p2;	// p2 는 객체이므로,
		// p2.operator++() 이라는 함수를 호출
		// => 이 함수를 만들어서 current 멤버가 다음요소로 이동하게 하면 됩니다.
		// => 이러한 iterator 객체가 "반복자"
		// => 이러한 객체를 각 컨테이너가 가지고 있음.
#endif