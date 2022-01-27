// 18_static_member_function1 114 page

#include <iostream>

class Car
{
	int speed;
	static int cnt;
public:

	Car() { ++cnt; }
	~Car() { --cnt; }

//	int get_count() { return cnt; }			// 1. 인스턴스 메소드
											//  1) 반드시 객체가 있어야 호출 가능하다.
											//  2) c1.get_count()

	static int get_count() { return cnt; }	// 2. 정적 메소드(클래스)
											//  1) 객체 없이 호출 가능한 멤버 함수(메소드)
											//  2) 일반적인 함수와 같다. 다만, class의 private 에 접근 가능!!
											//  3) Car::get_count() 로 호출
};
int Car::cnt = 0;							// * private 에 있어도 static 멤버 데이터의 외부 초기화는 허용됩니다.
											// * Car::cnt 를 초기화 하는 부분이 "static int get_count()" 이전에 있으면 안됩니다.


int main()
{
	std::cout << Car::get_count() << std::endl;

	Car c1;
	Car c2;

	//  4) static 멤버 함수는 아래 두가지 방법으로 접근 가능함
	std::cout << Car::get_count() << std::endl;	 // 권장!!
	std::cout << c1.get_count() << std::endl;	

}
