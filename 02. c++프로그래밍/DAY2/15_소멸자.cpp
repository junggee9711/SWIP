// 15_소멸자1 82 page

#include <iostream>

class Point
{
	int x = 0;
	int y = 0;
public:
	Point() { std::cout << "Point()" << std::endl; };

	// 1. 소멸자 - "~클래스 이름" 모양의 함수
	//			- 인자와 반환값이 모두 없다.
	//			- 한개만 만들수 있다.
	//			- 객체가 "파괴될 때" 호출된다.
	//	=> 필요한 경우만 만들면 되고, 필요 없다면 만들 필요 없다. /* 시험 문제 : 소멸자는 인자를 가질수 있다? (false) */
	~Point() { std::cout << "Point()" << std::endl; };
};

int main()
{
	{
		Point pt;
	}	// <== pt 파괴. 소멸자가 호출됨.
	std::cout << "---------------" << std::endl;
}