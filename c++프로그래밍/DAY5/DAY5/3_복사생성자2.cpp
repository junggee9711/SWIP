// 3_복사생성자2

#include <iostream>

// - 복사 생성자가 호출되는 3가지 경우
class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}

	Point(const Point& p) : x(p.x), y(p.y)
	{
		std::cout << "Point(const Point&)" << std::endl;
	}
};
//void f1(Point pt) {}
void f1(const Point& pt) {}

Point pt;
Point f2()
{
	return pt;				// 이 순간,
							// 리턴용임시객체 temp(pt); 생성 <== "복사 생성자" 호출
							// return temp;
}	
Point& f3()					// "참조반환" 이므로 임시객체 생성 안됨.
{							// "복사 생성자" 호출 안됨.
	return pt;
}

int main()
{
	// 복사 vs 대입
	Point p1;		

	// 1. 객체가 자신과 동일한 타입으로 초기화 될때
	Point p2(p1);			// "복사 생성자" 호출	
	Point p3 = p1;			// "복사 생성자" 호출
	
	// * 주의 : 아래 코드는 "대입" 입니다.
	Point p4;				// "디폴트 생성자" 호출
	p4 = p1;				// "대입연산자라"는 함수 호출 p4.operator=(p1)

	// 2.  함수가 객체를 call by value 로 받을때
	f1(p1);					// Point pt = p1 의 모양으로 f1 함수에 인자가 전달됨.
							// "복사 생성자" 호출
							// f1 의 인자를 const Point& pt 로 바꾸면 복자 생성자가 호출 안됨/

	// 3. 함수가 객체를 값으로 반환할 때 (return by value)
	f2();					// "복사 생성자" 호출
	f3();					


	/* 시험문제 : 복자 생성자가 호출되지 않는 경우를 찾으세요 (3개는 호출, 1개는 호출 안됨)
				  call by value/reference, return by value/reference 등의 보기중 1개 고름 */

}
