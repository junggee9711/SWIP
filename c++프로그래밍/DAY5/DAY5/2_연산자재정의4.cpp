// 2_연산자재정의4 - 187 page
// 
// #include <iostream>
#include <cstdio>

namespace std
{
	class ostream
	{
	public:
		// 실제 cout 은 prinf 가 아닌 "각 OS가 제공하는 화면 출력 함수" 사용.
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%f", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }

		// 이 외에도 실제 표준의 ostream 에는
		// 모든 표준 타입에 대해서 "opeartor<<" 를 제공하고 있습니다.
	};
	ostream cout;		// ostream class 의 전역객체 cout 을 선언
}

int main()
{
	int n = 10;
	double d = 3.4;

	std::cout << n << ", " << d << "\n";

	std::cout << n;		// cout.operator<<(int) 호출
	std::cout << d;		// cout.operator<<(double) 호출
						// => 연산자 재정의!!
}



