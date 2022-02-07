// 3_변수1 - 18 page

#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	struct Point p1;		// C스타일
	Point p2;				// 1. C++에서는 struct 없어도 된다.

	int n1 = 0x10;			// 2. 16진수 표기법
	int n2 = 0b10;			// 3. C++11, C11 부터 2진수 표기법 가능.
	int n3 = 1'000'0'0'0;	// 4. C++11 부터 자릿수 표기법 가능. (1000000 으로 인식함)
							//	  결국 ' 는 주석의 효과 - 컴파일러는 정수형 리터럴 사이의 ' 는 무시한다.

	// 5. 새로운 타입
	bool b = true;			// 또는 false / 0 또는 1. 크기 1 byte

	long long n = 0;		// 64bit (8 byte) 정수

}