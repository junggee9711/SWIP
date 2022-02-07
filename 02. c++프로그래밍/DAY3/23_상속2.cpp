// 23_���2 134 page



// - ���� ������ ����
// 1) C++ : private, protected, public
// 2) �ٸ� ���� : �� 3�� + internal, package ���� ������ �ֱ⵵ �մϴ�.


class Base
{
private:   int a;			// "�ڽ��� ��� �Լ�"�� ���� ����	+ friend �Լ�
protected: int b;			// "�ڽ��� ��� + �Ļ� Ŭ���� ���" �� ���� ���� + friend �Լ�
public:    int c;			// "������" ���� ����
};

	/* ���� ���� : ���� ���� ������ �߿��� �ڽŰ� �Ļ� Ŭ���� ������ ���� ������ ���� �����ڴ�? protected*/

class Derived : public Base
{
public:
	void f()
	{
//		a = 10;				// error. ��� Ŭ������ private ����� �Ļ� Ŭ�������� ���� �Ұ�.
							//		 => ���� �Ϸ��� ��� Ŭ������ �ִ� �Լ��� �ҷ��� �����ؾ� �Ѵ�.
		c = 10;				// ok.
	}
};
// Derived d; ==> a, c �� �޸𸮿� ������ "Derived�� �ִ� �Լ��� ���� �ȵ�"



int main()
{
	Base base;
//	base.a = 10;			// error. private �̱� ����
	base.c = 10;			// ok.


}
