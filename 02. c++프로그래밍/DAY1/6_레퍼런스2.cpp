// 43 page


// - Reference Ư¡
// 1) �Լ��� ���۷����� ���ڷ� �޴� ���

#include <iostream>

void inc1(int  n) { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }
 
int main()
{
	int a = 10, b = 10, c = 10;

	inc1(a);		// call by value	 => a �� ���� ����
	inc2(&b);		// call by pointer   => b �� ���� ����
	inc3(c);		// call by reference => c �� ���� ����
					// ���۷����� int& r = n; �� ���� �ʱ�ȭ �ϱ� ������ c ����
					// => inc3 �Լ����� int& r = c �� ���� ����
					// => c ���� �ּ��� �� �ٸ� �̸��� r ��� �ǹ�

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	int* p = 0;		// �ȴ�.
//	int& r;			// �ȵȴ�.
}


// 2) ������
void f1(int* p)
{
	// pointer : �����Ϸ��� if �� �ʿ�
	if (p != 0) {
		*p = 10;
	}
}

void f2(int& r)
{	
	// reference: if �� �ʿ����. �����ϴ�.
	r = 10; 
}



// ��� : �Լ��� ���鶧, 
//		  ���۷����� �޴°��� �����ͷ� �޴� �Ͱ� ����������,
//		  �� �� ���ϰ�, ������.
//		  ������ ��κ�, �����͸����ε� �� ���� �����ϴ�.