// 3_STL5

#include <list>
#include <vector>
#include <iostream>

int main()
{
	std::list<int> s;
	std::cout << sizeof(s) << std::endl;	// 24 byte 
											// - linked list 의 첫번째 요소의 메모리 
											// - size, capacity 등 class 객체 멤버의 메모리 포함

	s.push_back(10);
	std::cout << sizeof(s) << std::endl;	// 24 byte	
											// - linked list 의 첫번째 요소의 메모리만 출력
	s.push_back(20);
	s.push_back(30);
	std::cout << sizeof(s) << std::endl;    // 24 byte
											// - linked list 의 첫번째 요소의 메모리만 출력
	//------------------------------------
	// 아래 구조를 생각해 봅시다.
	std::vector< std::list<int> > v(5);		// list<int> 가 5개 배열됨 
	std::cout << sizeof(v) << std::endl;    // 32 byte
	v[4].push_back(1);
	v[4].push_back(2);
	v[4].push_back(3);
	std::cout << sizeof(v) << std::endl;	// 24x5 = 120 byte
}