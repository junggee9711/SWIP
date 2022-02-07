#include <iostream>

void f(int    n) { std::cout << "int"    << std::endl; } // 1
void f(double n) { std::cout << "double" << std::endl; } // 2
void f(bool   n) { std::cout << "bool"   << std::endl; } // 3
void f(int*   n) { std::cout << "int*"   << std::endl; } // 4


// - nullptr 의 정체

int main()
{	
	// 1) literal (리터럴) : 프로그램에서 사용되는 이름 없는 '값' 들.
	f(0);			// 1 로 감. 0은 정수형 리터럴, int 타입.
	f(0.0);			// 2 로 감. 0.0은 실수형 리터럴, double 타입.
	f(false);		// 3 로 감. false 는 bool 형 리터럴, 미리 정의된 키워드.
	f(nullptr);		// 4 로 감. nullptr 은 "포인터형 리터럴", 미리 정의된 키워드.


	// 2) 모든 리터럴은 타입이 있습니다.
	10;				// int 타입
	3.4;			// double 타입
	false;			// bool 타입
	nullptr;		// std::nullptr_t 라는 이름의 타입 입니다.
					// => std::nullptr_t 타입은 "모든 종류의 포인터" 로 암시적 형변환 된다.
					//	  라는 문법을 가지고 있습니다.

	// 3)
	std::nullptr_t a = nullptr; 

	// 이제 변수 a 는 nullptr 과 같은 용도로 사용 가능합니다.
	// 즉, nullptr 은 std::nullptr_t 를 가리키는 "포인터" 입니다.

	int* p1 = a;	// nullptr 이 int* 포인터로 암시적 형변환 됨.
					// int* p1 = null ptr 과 동일.
}