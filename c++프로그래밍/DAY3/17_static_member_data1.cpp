// 17_static_member_data1 110 page

#include <iostream>


// Car 객체가 몇개나 생성되었는지 조사하고 싶다.

// 방법 1. 멤버 데이터 (cnt) 사용
//		  => 멤버 데이터(cnt)는 객체당 한개 ( 100 page 그림 ) 가 생성된다.
//		  => 객체의 갯수 파악 실패!
class Car
{
	int speed;
public:
	int cnt = 0;
	Car() { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

	std::cout << c1.cnt << std::endl;		// c1 과 c2 에 각각 서로 다른 cnt 가 있기 때문에,
											// 2가 아니라 1이 나온다. - 틀림.

}