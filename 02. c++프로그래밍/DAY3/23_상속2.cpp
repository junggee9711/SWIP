// 23_상속2 134 page



// - 접근 지정자 종류
// 1) C++ : private, protected, public
// 2) 다른 언어들 : 위 3개 + internal, package 등의 개념이 있기도 합니다.


class Base
{
private:   int a;			// "자신의 멤버 함수"만 접근 가능	+ friend 함수
protected: int b;			// "자신의 멤버 + 파생 클래스 멤버" 가 접근 가능 + friend 함수
public:    int c;			// "누구나" 접근 가능
};

	/* 시험 문제 : 다음 접근 지정자 중에서 자신과 파생 클래스 에서만 접근 가능한 접근 지정자는? protected*/

class Derived : public Base
{
public:
	void f()
	{
//		a = 10;				// error. 기반 클래스의 private 멤버는 파생 클래스에서 접근 불가.
							//		 => 접근 하려면 기반 클래스에 있는 함수를 불러서 접근해야 한다.
		c = 10;				// ok.
	}
};
// Derived d; ==> a, c 가 메모리에 있지만 "Derived에 있는 함수는 접근 안됨"



int main()
{
	Base base;
//	base.a = 10;			// error. private 이기 때문
	base.c = 10;			// ok.


}
