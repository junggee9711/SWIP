// 23_���1 132 page

#include <string>


// 1. ��� : ���� Ÿ��(class)�� Ȯ���ؼ� ���ο� Ÿ���� �����ϴ� ����
//			�ڵ� �ߺ��� ���ϼ� �ְ�,
//			����� �پ��� ������ ���� �پ��� ������ Ȱ���Ҽ� �ִ�.

class Person						// => Base(���) class, super class, parent class ��� �� ��
{
	std::string name;
	int age;
};

// 2. 1) C++    - class Student : public Person
//	  2) C#     - class Student : Person
//	  3) Python - class Student(Person)
//    4) java   - class Student extends Person
class Student : public Person		// Person ���κ��� Person ���� "��� ��� ����/�Լ�"�� ��ӹ���
{									// => Derived(�Ļ�) class, sub class, child class ��� �� ��
	int id;							// 133 page �� �׸�(Ư�� ȭ��ǥ ����)�� �˾� �ξ�� �մϴ�.
};
class Professor : public Person
{
	int major;
};

int main()
{
	Student s;
	Professor p;
}