// 31_메뉴4

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>


// 모든 메뉴의 공통의 기반클래스를 만듬
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	std::string getTitle() const { return title; }

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		std::cout << getTitle() << "메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			system("cls");		

			int sz = v.size();	

			for (int i = 0; i < sz; i++) {
				std::cout << i + 1 << ". " << v[i]->getTitle() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택해 주세요 >>";
			int cmd;
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1) 
				continue;

			if (cmd == sz + 1) 
				break;		   

			v[cmd - 1]->command();
		}
	}
};

int main()
{
	PopupMenu* menuBar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("색상변경");
	PopupMenu* p2 = new PopupMenu("해상도변경");

	menuBar->addMenu(p1);
	menuBar->addMenu(p2);

	p1->addMenu(new MenuItem("Red", 11));
	p1->addMenu(new MenuItem("Green", 11));
	p1->addMenu(new MenuItem("Blue", 11));

	p2->addMenu(new MenuItem("HD", 11));
	p2->addMenu(new MenuItem("FHD", 11));
	p2->addMenu(new MenuItem("UHD", 11));

	// 이제 시작하려면 ??
	menuBar->command();
}