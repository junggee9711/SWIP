// 1_friend.cpp - 75 page
class Bike
{
	int gear;
public:

	// friend 함수 : 멤버 함수는 아니지만, 해당 함수에서 private 멤버 변수/함수에 접근하는 것을 허용해 달라.
	// 1. 멤버함수로 하면 되는데 왜 일반함수로 만드나요?
	//	  => 멤버 함수로 만들수 없을때가 있습니다. (연산자 재정의에서 다룸)
	//
	// 2. getGear(), setGear() 함수를 만들면 되지 않나요?
	//    => 모든 함수에서 접근을 허용하게 됩니다.
	//	  => 특정 함수에서만 접근 허용하고 싶을때가 있습니다.
	friend void fixBike();
};

void fixBike()		// Bike class 의 멤버 함수 아님..
{
	Bike b;
	b.gear = 10;	// friend 함수로 지정하지 않으면, gear 가 Bike 의 private 이기 때문에 접근 불가
}

int main()
{
	fixBike();
}