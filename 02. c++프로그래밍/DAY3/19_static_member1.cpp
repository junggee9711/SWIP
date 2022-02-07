// 19_static_member1 118 page

// - static member 의 파일 분할

#include <iostream>

// Car.h
class Car
{
	int speed;
	static int cnt;
public:

	Car();
	~Car();

	static int get_count();
};						
//-----------------------------------

// Car.cpp
#include "Car.h"

int Car::cnt = 0;							// * static 멤버 변수의 외부 선언은 소스파일 (.cpp) 에 있어야 합니다. (안정성)
Car::Car() { ++cnt; }
Car::~Car() { --cnt; }
int Car::get_count() { return cnt; }		// * static 멤버 함수는 외부 구현시 "static" 표기 안합니다.
//-----------------------------------


int main()
{
	
}
