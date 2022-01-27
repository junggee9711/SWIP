// 9_nullptr2

#include <iostream>

void f(int	 n) { std::cout << "int"   << std::endl; } // 1
void f(void* n) { std::cout << "void"  << std::endl; } // 2
void g(char* n) { std::cout << "char*" << std::endl; }

int main()
{
	f(0);				// 1 함수로 감. 0은 정수 입니다. int 타입이 "우선순위"!.
	f((void*)0);		// 2 함수로 감. (void*)0 가 NULL!

#define NULL (void*)0	// 이런 매크로는 이미 define 되어있음.
	f(NULL);			// 2 함수로 감
//	g(NULL);			// error.
						// void* => char* 로의 암시적 형변환 필요.
						// => C언어는 암시적 변환 허용
						// => C++은 허용 안됨
	

}