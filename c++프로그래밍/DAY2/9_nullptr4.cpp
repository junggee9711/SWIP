#include <iostream>

void f(int    n) { std::cout << "int"    << std::endl; } // 1
void f(double n) { std::cout << "double" << std::endl; } // 2
void f(bool   n) { std::cout << "bool"   << std::endl; } // 3
void f(int*   n) { std::cout << "int*"   << std::endl; } // 4


// - nullptr �� ��ü

int main()
{	
	// 1) literal (���ͷ�) : ���α׷����� ���Ǵ� �̸� ���� '��' ��.
	f(0);			// 1 �� ��. 0�� ������ ���ͷ�, int Ÿ��.
	f(0.0);			// 2 �� ��. 0.0�� �Ǽ��� ���ͷ�, double Ÿ��.
	f(false);		// 3 �� ��. false �� bool �� ���ͷ�, �̸� ���ǵ� Ű����.
	f(nullptr);		// 4 �� ��. nullptr �� "�������� ���ͷ�", �̸� ���ǵ� Ű����.


	// 2) ��� ���ͷ��� Ÿ���� �ֽ��ϴ�.
	10;				// int Ÿ��
	3.4;			// double Ÿ��
	false;			// bool Ÿ��
	nullptr;		// std::nullptr_t ��� �̸��� Ÿ�� �Դϴ�.
					// => std::nullptr_t Ÿ���� "��� ������ ������" �� �Ͻ��� ����ȯ �ȴ�.
					//	  ��� ������ ������ �ֽ��ϴ�.

	// 3)
	std::nullptr_t a = nullptr; 

	// ���� ���� a �� nullptr �� ���� �뵵�� ��� �����մϴ�.
	// ��, nullptr �� std::nullptr_t �� ����Ű�� "������" �Դϴ�.

	int* p1 = a;	// nullptr �� int* �����ͷ� �Ͻ��� ����ȯ ��.
					// int* p1 = null ptr �� ����.
}