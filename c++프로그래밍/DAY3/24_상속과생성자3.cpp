// 24_��Ӱ�������3

#include <iostream>

class Base
{
	int data1;
public:
//	Base()		{}
	Base(int a) {}
	~Base()		{}
};
class Derived : public Base
{
	int data2;
public:
	// ��� Ŭ������ "����Ʈ �����ڰ� ���� ��" �Ʒ� ó���� ����� ������ �����Դϴ�.
//	Derived()      {}		// Derived() : Base() {}
//	Derived(int a) {}		// Derived(int a) : Base() {}
							// => Base() �� �ּ�ó������ error �߻�
							// => Base(int a) ������ ���ּ� �����ڸ� �ƿ� ���ָ�,
							//    �����Ϸ��� Base() �� �ڵ� �����ؼ� ok.
	~Derived()	   {}

	// �ذ�å�� ����ڰ� ���� "�����ϴ�" ��� Ŭ���� �����ڸ� ȣ���ϴ� �ڵ带 �����ؾ� �մϴ�.
	Derived()	   : Base(0) {}
	Derived(int a) : Base(a) {}
};

int main()
{
	//	Derived d1;
	Derived d1(5);
}

// Base �� �����ڰ� ���� �Ҹ��� Derived �� �����ڰ� ���߿� �Ҹ��µ�, Base �� �����ڴ� ����Ʈ �����ڰ� �Ҹ�.