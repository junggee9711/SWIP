// 19_static_member1 118 page

// - static member �� ���� ����

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

int Car::cnt = 0;							// * static ��� ������ �ܺ� ������ �ҽ����� (.cpp) �� �־�� �մϴ�. (������)
Car::Car() { ++cnt; }
Car::~Car() { --cnt; }
int Car::get_count() { return cnt; }		// * static ��� �Լ��� �ܺ� ������ "static" ǥ�� ���մϴ�.
//-----------------------------------


int main()
{
	
}
