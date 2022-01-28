// 2_연산자재정의5-1

#include <cstdio>

namespace std
{
	class ostream
	{
		// 실제 ostream 은 다양한 멤버 데이터가 있습니다.
		char* buff;
		int size;
		int count;
	public:
		// 그리고, opeartor<<() 함수 안에서 멤버데이터를 수정하는 코드가 있습니다.
		// => 그래서, operator<<() 함수는 상수 멤버 함수가 될 수 없습니다.
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%f", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }

	};
	ostream cout;		
}

int main()
{
	std::ostream& os = std::cout;

	os << "hello";			// os 는 결국 std::cout 의 별명

	const std::ostream& os2 = std::cout;

//	os2 << "hello";			// error. os2.operator<<("hello") 인데.
							// os2 는 상수 객체이므로 상수 멤버 함수만 호출 가능합니다.
							// 그런데, operator<<(const char*)는 상수 멤버함수가 아닙니다.
}



