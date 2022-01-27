// 9_nullptr2

#include <iostream>


void f(int	 n) { std::cout << "int" << std::endl; } // 1
void f(void* n) { std::cout << "void" << std::endl; } // 2
void g(char* n) { std::cout << "char*" << std::endl; }


int main()
{

	// ���� �ڵ尡 ���� �Ϻ��� C++ �����Ϸ��� ����� �ִ� ����Դϴ�.
#ifdef __cplusplus	
	#define NULL 0				// NULL �� (void*)0 �� �ƴ϶� 0���� ����
#else
	#define NULL (void*)0
#endif

	f(NULL);				// 1 �Լ��� ��.
							// �ᱹ, NULL �� ������ 0���� ����ϰ� �;����� (2 �Լ��� ���� �;�����),
							// ����!!!!

	g(NULL);				// ok.

	// NULL �� �ƴ� ��¥ ������ 0 �� �ʿ��ߴ�.
	// �׷��� nullptr ���� ����.
	f(nullptr);				// 2 �Լ��� ��
	g(nullptr);				// ok.
}

// �� �ҽ��� �ٽ� : NULL�� define �ϴ� ���� ������.