// 20_this3

#include <iostream>

class Test
{
	int data;
public:
	void f1()			// ������ ��, void f1(Test* this) �� ����
	{
		std::cout << this << std::endl;
		data = 10;		// ������ ��, this->data = 10; ���� ����
	}

	static void f2()	// ������ ��, void f2() �Դϴ�.
	{
//		std::cout << this << std::endl;		// error. this (��ü�� �ּ�)�� �����ϴ�.
//		data = 10;							// error. this->data = 10 ���� �����ؾ� �ϴµ�...
											// this �� �����ϴ�.
											// �׷���, static ��� �Լ������� �ν��Ͻ� ����� ������ �ȵǴ� �̴ϴ�!!!!!!!
	}
};

int main()
{
	Test t;
	t.f1();				// f1�� ȣ���Ϸ��� ��ü�� �ʿ��մϴ�.
						// ������ ��, f1(&t) �� ����Ǵ� ���� �Դϴ�.


	Test::f2();			// ��ü ���� ȣ���߽��ϴ�.
						// ����, ������ �Ǿ "f2()" �Դϴ�.
						// ��, class ��ü�� �ּ� ���ڰ� �߰� �ɼ� �����ϴ�.

}