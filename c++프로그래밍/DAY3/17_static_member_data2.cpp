// 17_static_member_data2 
#include <iostream>


// Car 객체가 몇개나 생성되었는지 조사하고 싶다.

// 방법 2. 전역변수 (cnt) 사용
//		  => 모든 객체가 공유한다.
//		  => Car 객체의 갯수 파악 성공!!
//	단점 1) 전역변수는 누구나 접근 가능하므로 안전하지 않다.
//		   => Car 의 멤버만 접근할수 있도록 보호 할수 없을까?
//	       => 즉, 전역변수에 private 을 사용할수 없을까? -> 전역변수는 멤버가 아니므로 안됨.
//  단점 2) 만약 다른 Truck 클래스도 갯수를 파악 하려면 역시 전역변수 필요
//		   => "cnt" 말고 다른 이름이 또 필요해짐
int cnt = 0;

class Car
{
	int speed;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }
};

int main()
{

	Car c1;
	Car c2;

	cnt = 100;		// 사용자가 이런식으로 접근할수 있어서, 안정성이 떨어짐
	
	std::cout << cnt << std::endl;	

}
