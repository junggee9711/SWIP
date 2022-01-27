// 22_상수멤버함수1

#include <iostream>

class Point
{
public:
	int x;
	int y;
	Point(int x, int y) : x(x), y(y) {}

	void set(int a, int b)
	{
		x = a;
		y = b;
	}

	// - 상수 멤버 함수 : 멤버 함수안에서 멤버데이터를 수정하지 않을것이라고
	//				     컴파일러에게 알려 주는것
	//				   => 멤버 값을 수정하는 코드가 있으면 에러!
	void print() const
	{ 
//		x = 10;					// error.
		std::cout << x << ", " << y << std::endl; 
	}
};

int main()
{
	const Point pt(1, 2);		// ** Point 를 "타입" 으로 생각하면 "const 변수" 와 같은 맥락으로 생각 가능
								// Point 내의 멤버변수들이 const 가 됨 (멤버 함수는 사실 함수가 변하지 않으므로 무관)

//	pt.x = 10;					// error. public 에 있지만 상수 객체이므로 변경 불가.
//	pt.set(10, 20);				// error. 위와 같은 이유
	pt.print();					// 상수 멤버 함수가 아니면 error.
								// 상수 멤버 함수였다면 ok.
								// => 컴파일러는 print 함수 안을 보는 것이 아니라, 
								//    선언만 보고 const 객체를 바꿀지도 모른다고 생각하고 error 출력
								//    그러므로, 함수 선언에 const 가 없다면 error 출력.
}

// 핵심 : 상수 객체는 상수 멤버 함수만 호출할수 있다. (121 page 아래 부분)
