// 3_복사생성자1 92 page
#include <iostream>

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 1. 복사생성자 : 자신과 동일한 타입의 객체로 초기화 될때 사용
	//		=> 사용자가 만들지 않으면 컴파일러가 제공.
	//		=> 컴파일러는 아래 모양으로 제공합니다.
	// 컴파일러 제공 버전이 하는 일이 중요합니다.
	Point(const Point& p) : x(p.x), y(p.y)	// <== 이부분이 중요!!!
	{										// *인자로 받은 Point 의 모든 멤버변수를 복사 (bitwise copy)
	}

	// 2. 컴파일러가 생성하는 복사생성자 버전은 어떤 문제점이 있나요???
	//   1) 이 예제의 Point 클래스는 전혀 문제 없습니다... 그냥 사용하면 됩니다.
	//   2) 특정 형태의 클래스에서는 문제가 됩니다.


	/* 시험문제 : 컴파일러가 만들어주는 복사 생성자는 아무일도 하지 않는다. false. bitwise copy 수행 */
};
int main()
{
	// 아래 4줄을 생각해 보세요
	Point p1;			// ok.
//	Point p2(1);		// error. Point(int) 생성자가 필요하다.
	Point p3(1,2);		// ok.
	Point p4(p3);		// ok. Point(Point) 생성자가 필요하다.
						// => 이런 모양의 생성자를 "복사생성자" 라고 한다.
}

