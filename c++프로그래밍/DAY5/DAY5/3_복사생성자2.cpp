#include <iostream>

class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}
};
int main()
{
	// ���� vs ����
	Point p1;		
	Point p2(p1);	
	Point p3 = p1;  
	
	Point p4;
	p4 = p1;
}
