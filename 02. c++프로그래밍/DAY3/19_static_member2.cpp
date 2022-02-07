// 19_static_member2 

#include <iostream>


class Car
{
	int speed = 0;						// 인스턴스 멤버데이터는 C++11 부터 필드 초기화 가능.
//	static int cnt = 0;					// error. static 멤버 데이터는 반드시 외부 선언에서 초기화 해야함.

	static int cnt;						// 반드시 외부 선언 필요하고. 초기화도 외부선언에서.
										// java, c# 은 외부 선언이 필요 없습니다.
public:

	Car() { ++cnt; }
	~Car() { --cnt; }
	int get_count() { return cnt; }

};
int Car::cnt = 0;						

// C++17 에서 "inline static" 이라는 문법 등장
class Car
{
	int speed = 0;
	inline static int cnt = 0;			// 외부 선언이 필요 없고, 여기서도 초기화 가능		
										// 함수 inline 과는 다르게, inline 명령 필요 없음
public:

	Car() { ++cnt; }
	~Car() { --cnt; }
	int get_count() { return cnt; }
};
int Car::cnt = 0;

int main()
{

}
