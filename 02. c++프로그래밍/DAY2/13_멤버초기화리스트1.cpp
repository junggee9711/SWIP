// 13_멤버초기화리스트1

#include <iostream>
#include <string>


class Person
{
	std::string name;
	int age;
public:
	// 1. 멤버 초기화 리스트 
	// => 생성자 () 뒤에 : 를 적고 초기화 하는 것
	Person(const std::string& n, int a) : name(n), age(a)	// "초기화 코드" - 무조건 이렇게 사용!!
	{
//		name = n;
//		age = a;											// public 위에서 선언 후 값을 넣는 "대입 코드"
	}
};

int main()
{
	Person p("lee", 20);

	// 2. 초기화 vs 대입
	// 1) primitive type 이면 "거의 동일하다."
	int n1 = 10;			// "초기화 코드"
	int n2;
	n2 = 10;				// "대입 코드"

	// 2) user define type 이면,
	std::string s1("lee");	// string 이 string() 생성자에 인자 "lee"를 받아서 1회 호출하여 초기화 하는 코드
							// string(const char*) 생성자 호출

	std::string s2;			// 인자 없는 생성자 호출
	s2 = "lee";				// s2.operator=("lee") 라는 함수 호출 (대입 연산자)

}
