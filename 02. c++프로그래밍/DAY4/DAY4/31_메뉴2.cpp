// 31_�޴�2

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

// 2. C++ ����

// "�޴�"��� Ÿ���� ������ ���ô�.

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}	// user defined �̹Ƿ� "const Ÿ��&" ���� ���� ����

	std::string getTitle() const { return title; }

	// �޴� ���ý� ȣ��Ǵ� �Լ�
	void command()
	{
		std::cout << getTitle() << "�޴��� ���õ�" << std::endl;
		_getch();	// Ű���带 ���������� ��� �����ϴ� �Լ�
	}
};

int main()
{
	MenuItem m1("���󺯰�", 11);
	MenuItem m2("�ɼ�", 12);
	m2.command();  // �޴� ���ý� �� �Լ��� ȣ���ϱ�� ����մϴ�.
}