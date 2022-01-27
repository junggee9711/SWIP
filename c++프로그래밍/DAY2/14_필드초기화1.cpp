// 14_필드초기화1 91 page

class Point
{
	int x = 0;
	int y = 0;		// - 필드(field) 초기화
					//	: C++ 부터 이 코드가 허용됩니다.
public:
	Point()							 {}
	Point(int a) : x(a)				 {}
	Point(int a, int b) : x(a), y(b) {}
};
// 필드 초기화후 멤버 초기화를 하는 것일까?
// => 위처럼 만들면 컴파일러가 아래 처럼 변경하는 원리 입니다.

class Point
{
	int x; /* = 0; */
	int y; /* = 0; */
					
public:
	Point()			    /* : x(0), y(0) */ {}
	Point(int a)		: x(a) /*, y(0) */ {}
	Point(int a, int b) : x(a), y(b) {}
};


int main()
{
	Point p(1);		// x = 1, y = 0
}