// 12_������3 78 page

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
	Point ptFrom;			// Rect rc; �� �����߱� ������ ptFrom �� �ҷ��� Point Ÿ���� ������ ȣ��
	Point ptTo;				//								ptTo �� �ҷ��� Point Ÿ���� ������ ȣ��
public:
	Rect() { std::cout << "Rect()" << std::endl; }
};


int main()
{
	Rect rc;				// Point()\n Point(int, int)\n, Rect()\n ���
}