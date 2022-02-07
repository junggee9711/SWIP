// 12_생성자3 78 page

#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() { x = 0; y = 0; std::cout << "Point()" << std::endl; }						
	Point(int a, int b) { x = 0; y = 0; std::cout << "Point(int, int)" << std::endl; }	
};

class Rect
{
	Point ptFrom;			// Rect rc; 를 선언했기 때문에 ptFrom 이 불러온 Point 타입의 생성자 호출
	Point ptTo;				//								ptTo 이 불러온 Point 타입의 생성자 호출
public:
	Rect() { std::cout << "Rect()" << std::endl; }
};


int main()
{
	Rect rc;				// Point()\n Point(int, int)\n, Rect()\n 출력
}