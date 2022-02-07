// 17_static_member_data4 
#include <iostream>

// - 멤버데이터와 static 멤버 데이터의 차이 
//	=> class 객체끼리 공유하는가 아닌가!

class Car
{
	int speed;				// "객체당 한개"(같은이름을 객체당 한개씩 사용), "인스턴스 필드(멤버데이타)" 라는 용어 사용.
public:
	static int cnt;			// 모든 Car 객체가 공유 
							// = 클래스당 한개(같은이름을 클래스당 한개씩 사용), "클래스 필드(멤버데이터)" 라는 용어 사용.

	Car() { ++cnt; }
	~Car() { --cnt; }
};
int Car::cnt = 0;


class Truck
{
	int speed;
public:
	static int cnt;

	Truck() { ++cnt; }
	~Truck() { --cnt; }
};
int Truck::cnt = 0;



int main()
{
}
