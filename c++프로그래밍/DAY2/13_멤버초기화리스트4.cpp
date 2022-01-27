// 13_멤버초기화리스트4 88 page 제일 아래

#include <iostream>

class Point
{
public:
	int x;
	int y;

	// 멤버 데이터를 초기화 리스트에서 초기화 할 때 초기화 되는 순서는 리스트에 놓인 순서가 아니라 멤버가 놓인 순서로 초기화 됨.
	Point() : y(0), x(y) {}			// x 가 y 보다 먼저 선언 되었기 때문에 x(y) 이 y(0) 보다 먼저 실행 된다.

									// undefined (미정의 동작)
									// : "표준 문서에서는 사용하지 말라고만 되어있고,
									//    사용하면 어떻게 된다 고는 정의 한적이 없는것"
									//	=> 컴파일러마다 현상이 다르다.
									//  => x(y), y(0) 은 문제가 없을 것
};

int main()
{

	Point p1;

	std::cout << p1.x << std::endl;
	std::cout << p1.y << std::endl;
}