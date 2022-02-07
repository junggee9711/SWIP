// 9_nullptr2

#include <iostream>


void f(int	 n) { std::cout << "int" << std::endl; } // 1
void f(void* n) { std::cout << "void" << std::endl; } // 2
void g(char* n) { std::cout << "char*" << std::endl; }


int main()
{

	// ㅇ래 코드가 현재 일부의 C++ 컴파일러가 만들고 있는 모양입니다.
#ifdef __cplusplus	
	#define NULL 0				// NULL 이 (void*)0 이 아니라 0으로 정의
#else
	#define NULL (void*)0
#endif

	f(NULL);				// 1 함수로 감.
							// 결국, NULL 을 포인터 0으로 사용하고 싶었으나 (2 함수로 가고 싶었으나),
							// 실패!!!!

	g(NULL);				// ok.

	// NULL 이 아닌 진짜 포인터 0 가 필요했다.
	// 그래서 nullptr 새로 도입.
	f(nullptr);				// 2 함수로 감
	g(nullptr);				// ok.
}

// 이 소스의 핵심 : NULL을 define 하는 법과 문제점.