// 9_nullptr2

#include <iostream>

void f(int	 n) { std::cout << "int"   << std::endl; } // 1
void f(void* n) { std::cout << "void"  << std::endl; } // 2
void g(char* n) { std::cout << "char*" << std::endl; }

int main()
{
	f(0);				// 1 �Լ��� ��. 0�� ���� �Դϴ�. int Ÿ���� "�켱����"!.
	f((void*)0);		// 2 �Լ��� ��. (void*)0 �� NULL!

#define NULL (void*)0	// �̷� ��ũ�δ� �̹� define �Ǿ�����.
	f(NULL);			// 2 �Լ��� ��
//	g(NULL);			// error.
						// void* => char* ���� �Ͻ��� ����ȯ �ʿ�.
						// => C���� �Ͻ��� ��ȯ ���
						// => C++�� ��� �ȵ�
	

}