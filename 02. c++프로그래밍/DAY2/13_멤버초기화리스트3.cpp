// 13_멤버초기화리스트3 

#include <iostream>

class Point
{
	int x;
	int y;
public:
//	Point() { x = 0; y = 0; std::cout << "Point()" << std::endl; }
	Point(int a, int b) { x = 0; y = 0; std::cout << "Point(int, int)" << std::endl; }
};

// Point p1;		// error. 디폴트 생성자가 없다.
// Point p2(0, 0);  // ok.

class Rect
{
	Point ptFrom;			
	Point ptTo;				
public:
	// 88 page 제일 위의 박스
	// 아래 코드 꼭 기억해 두세요. 많은 C++ 개발자들이 잘 못하는 부분.
	// 1) Point() 라는 "디폴트 생성자"가 없기 때문에 Point ptFrom, Point ptTo 에서 생성자를 불러오지 못함
	// 2) 초기화 리스트에서 생성자를 불러와 초기화 시켜줌
	Rect(int x1, int y1, int x2, int y2) : ptFrom(x1, y1), ptTo(x2, y2) 
	{ 
		std::cout << "Rect()" << std::endl; 
	}
};


int main()
{
	Rect rc(1,1,10,10);				
}