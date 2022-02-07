//20_this1 126 page

#include <iostream>


// - this : 현재 함수를 호출할때 사용한 객체(p1, p2)의 주소 입니다.
//			=> python 에서 "self"

class Point
{
	int x;
	int y;
public:

	void set(int a, int b)
	{
		x = a;
		y = b;
	}
};



int main()
{
	Point p1;
	Point p2;
	p1.set(10, 20);				// set(&p1, 10, 20) 
	p2.set(10, 20);				// set(&p2, 10, 20) 처럼 컴파일러가 변경합니다. 즉, 3개의 인자 전달
								// => set 함수는 메모리에 p1, p2 각각 저장되는것이 아니기 때문에,
								//     &p1, &p2 를 전달

								// => 즉, 컴파일러가 멤버 함수 set 을 아래처럼 변경합니다.
#if 0
								void set(Point * this, int a, int b)
								{
									this->x = a;	// *(&p1).x = a;
									this->y = b;	// *(&p2).y = b;
													/* a->b == *(a).b */
								}
#endif
}