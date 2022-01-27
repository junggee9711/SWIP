// 12_생성자2 78 page

#include <iostream>

class Point
{
	int x;
	int y;
public:
	// 1) 생성자는 2개 이상 만들수 있습니다.
	// 2) 사용자가 생성자를 한개도 만들지 않으면,
	//	  컴파일러가 인자 없는 생성자 Point() {} 제공 - "디폴트 생성자" 라고 합니다. (78 page 아래)
	//    가상함수가 있는 경우 "가상함수 테이블 초기화" 를 합니다.
	Point()				{ x = 0; y = 0; std::cout << "Point()" << std::endl; }			// 1
	Point(int a, int b) { x = 0; y = 0; std::cout << "Point(int, int)" << std::endl; }	// 2
};

int main()
{
	// 3) 모든 객체는 생성되면 반드시 생성자가 호출되어야 합니다.
	//	  => 타입을 불러온 횟수만큼 생성자 호출.
	Point p1;										// 1번 생성자 호출
//	Point p2(1, 2);									// 2번 생성자 호출

	Point arr1[5];									// 1번 생성자 5회 호출
	Point arr2[5] = { {1, 2}, {0, 0} };				// 2번 생성자 2회, 1번 생성자 3회
													// *타입을 불러온 횟수만큼 생성자 호출

	Point* p;										// 객체 생성 아님.. 생성자 호출 안됨

	p = static_cast<Point*>(malloc(sizeof(Point))); // 생성자 호출 안됨.
	free(p);										// Point 타입 전달이 아닌 "크기 8" 전달

	p = new Point;									// 1번 생성자 호출. 
	delete p;										// new 는 생성자 호출 됨.
													// Point 타입 전달.

	p = new Point(1, 2);							// 2번 생성자 호출
	delete p;

	// C++11 부터는 아래 표기도 가능
	Point p3(1, 1);									// C++98 시절 - 생성자에 인자를 전달해서 초기화한다는 의미
	Point p5{ 1,1 };								// C++11 direct initialization
	Point p6 = { 1,1 };								// C++11 copy initialization

	int a = 3;
	int b{ 3 };
	int c(3);										// * 이것은 생성자에 인자를 전달하는것이 아니라
													//   컴파일러가 c(3) => c{3} 바꾸는 것.
}