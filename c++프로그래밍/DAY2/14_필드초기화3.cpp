// 14_필드초기화3

#include <iostream>

class Point
{
	int x;
	int y;
public:
//	Point()				{ x = 0; y = 0; std::cout << "Point" << std::endl; }
	Point(int a, int b) { x = 0; y = 0; std::cout << "Point(int, int)" << std::endl; }
};


class Rect
{
//	Point ptFrom(0,0);		// 구문 해석시 "출력 타입 함수명(인자)" 와 같은 "함수모양"으로 해석해서 실패
	Point ptFrom{ 0,0 };	// ok. 중괄호 표기법을 사용하면 됩니다.
	Point ptTo{ 0,0 };
public:
	// Point 에 디폴트 생성자가 없기 때문에 동작하지 않을것 같지만,
	// 컴파일러가 필드 초기화를 통해 아래와 같이 바꾸기 때문에 동작함.
	Rect() /* : ptFrom(0, 0), ptTo(0, 0) */ {}

	Rect(int x1, int y1, int x2, int y2) : ptFrom(x1, y1), ptTo(x2, y2)
	{
		std::cout << "Rect()" << std::endl;
	}
};


int main()
{
	Rect rc1;
	Rect rc2(1, 1, 10, 10);
}

// 91 page 아래부분 - 멤버 데이터를 초기화 하는 3가지 방법!
// 1) 필드초기화 2) 초기화리스트 3) 대입