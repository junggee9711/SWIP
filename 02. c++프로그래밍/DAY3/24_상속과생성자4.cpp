// 24_��Ӱ�������4

#include <string>


class Person			
{
	std::string name;
	int age;
public:
	// ����� �����Ҷ��� �� �ʱ�ȭ �ش޶�! - �����ϰ� ������ڴ� ��
	// => Person s; ó�� �����ϸ� ����, 
	//	  �����ڰ� �ƿ� ���ٸ� ����Ʈ �����ڸ� �θ�������,
	//	  �����ڰ� �����Ƿ� �ش� �����ڿ� ���ڸ� ���� �ؾ� ��.
	Person(const std::string& n, int a) : name(n), age(a) {}
};

class Student : public Person		
{									
	int id;		
public:
	// �Ʒ� ó�� �ϸ� ��� Ŭ������ ����Ʈ �����ڰ� ���� ������
	// ������ ���� �Դϴ�.
//	Student(int n) : id(n) {}			// Student(int n) : Person(), id(n) {}

	// Student �����ڸ� ���鶧 ��� Ŭ������ Person �� �䱸�ϴ� �̸��� ���̵� �޾ƾ� �մϴ�.
	Student(const std::string& name, int age, int n)
		: Person(name, age), id(n) {}	// ��� Ŭ������ "�����ϴ�" �����ڸ� ȣ���ϵ��� �ڵ�
};



int main()
{
//	Student s(10);
	Student s("lee", 25, 11);		// ok.
									// => �̷��� �ϸ�, Person �� ��� ���� name, age �� �ʱ�ȭ ����
}