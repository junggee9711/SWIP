// 12_생성자1
#include <iostream>


class Bike
{
private:
	int speed;
	int gear;

public:
	// 생성자 : 객체를 생성하면 자동으로 호출되는 함수
	//	(특징) - 클래스 이름과 동일.
	//	       - 반환타입을 적지 않고, 반환할수도 없다.
	//         - 인자는 있어도 되고 없어도 된다.
	Bike()
	{
		std::cout << "Bike()" << std::endl;
		speed = 20;
		gear = 10;
	}
};

int main()
{
//	Bike b = { 30,10 };			// 데이터가 public 에 있으면 이렇게 초기화가 가능합니다.
								// 결국, class 도 struct 와 (거의) 동일하므로
								// 하지만, private 에 있다면 에러.

	Bike b;
//	b.init();					// 생성자로 인해 class 내 Bike() 함수가 자동 호출되어 값 초기화.
}