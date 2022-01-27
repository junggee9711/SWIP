// 31_메뉴2

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

// 2. C++ 구현

// "메뉴"라는 타입을 설계해 봅시다.

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}	// user defined 이므로 "const 타입&" 으로 인자 받음

	std::string getTitle() const { return title; }

	// 메뉴 선택시 호출되는 함수
	void command()
	{
		std::cout << getTitle() << "메뉴가 선택됨" << std::endl;
		_getch();	// 키보드를 누를때까지 잠시 정지하는 함수
	}
};

int main()
{
	MenuItem m1("색상변경", 11);
	MenuItem m2("옵션", 12);
	m2.command();  // 메뉴 선택시 이 함수를 호출하기로 약속합니다.
}