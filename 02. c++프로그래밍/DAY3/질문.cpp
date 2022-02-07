
struct Point
{
	int x;
	int y;

	Point(int a, int b) : x(a), y(b) {};
}
// Point p( 1, 1 );, Point p{ 1, 1 };, Point p = { 1, 1 )}; 

struct Point
{
	int x;
	int y;
}
// 1. ()
//  Point p( 1, 1 ); -> 왜 error?
// => C++ 문법 1) 생성자를 호출하여 초기화하는 문법

// 2. {}
// Point p{ 1, 1 };, Point p = { 1, 1 )}; 
// => C 문법 1) struct 초기화 하는 문법
//			 2) C++ 에 들어오면서 "생성자"가 있으면, 이걸 먼저 호출하여 초기화하는 문법으로 바뀜
