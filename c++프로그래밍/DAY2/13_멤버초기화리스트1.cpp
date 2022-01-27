// 13_����ʱ�ȭ����Ʈ1

#include <iostream>
#include <string>


class Person
{
	std::string name;
	int age;
public:
	// 1. ��� �ʱ�ȭ ����Ʈ 
	// => ������ () �ڿ� : �� ���� �ʱ�ȭ �ϴ� ��
	Person(const std::string& n, int a) : name(n), age(a)	// "�ʱ�ȭ �ڵ�" - ������ �̷��� ���!!
	{
//		name = n;
//		age = a;											// public ������ ���� �� ���� �ִ� "���� �ڵ�"
	}
};

int main()
{
	Person p("lee", 20);

	// 2. �ʱ�ȭ vs ����
	// 1) primitive type �̸� "���� �����ϴ�."
	int n1 = 10;			// "�ʱ�ȭ �ڵ�"
	int n2;
	n2 = 10;				// "���� �ڵ�"

	// 2) user define type �̸�,
	std::string s1("lee");	// string �� string() �����ڿ� ���� "lee"�� �޾Ƽ� 1ȸ ȣ���Ͽ� �ʱ�ȭ �ϴ� �ڵ�
							// string(const char*) ������ ȣ��

	std::string s2;			// ���� ���� ������ ȣ��
	s2 = "lee";				// s2.operator=("lee") ��� �Լ� ȣ�� (���� ������)

}
