// 복사 생성자 92 page 입니다.
#include <iostream>

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	// 아래 4줄을 생각해 보세요
	Point p1;		
	Point p2(1);	
	Point p3(1,2);	
	Point p4(p3);	
}


// 3:00 부터 이어집니다.
