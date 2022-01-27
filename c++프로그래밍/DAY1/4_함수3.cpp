// 30 page

// C와 다른 C++함수의 특징 3. 함수 오버로딩

// - 함수 오버로딩
// 1) 인자의 타입이나 갯수가 다르면 "동일이름의 함수를 여러개"만들 수 있다.
// 2) 거의 모든 객체지향 언어가 제공하는 문법 except C 언어, Python

// - 함수 오버로딩 원리 - "name mangling"
// 1) name mangling : C++ 컴파일러가 컴파일 시간에 함수 이름과 인자의 형태를 가지고 새로운 이름으로 변경하는 것.
//					  결국, 소스에서는 이름이 동일하지만, 컴파일 후에는 달라진다.
// 2) C언어에는 함수 오버로딩이 없기 때문에,
//	  함수의 C 컴파일 단계에서 이름이 C++ 컴파일러와는 다르게 생성된다.
//	  => 그러므로 C로 컴파일된 함수를 C++ 로 불러와서 사용하려 하면 error.
//    => 이런 경우 extern "C" 를 헤더파일의 함수 선언 앞에 붙여서 사용함.
// 3) extern "C" : C++ 컴파일러에게 해당 심볼이 C언어라고 알려주는 것.
//				   name mangling 을 하지 말라는 것.
//				   => C에서는 컴파일 안됨.
// 4) C/C++ 을 모두 지원하는 헤더 => square.h 파일

#include <iostream>

int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}


int main()
{
	std::cout << square(3) << std::endl;
	std::cout << square(3.4) << std::endl;
	// 사용자 입장에서는 서로 같은 함수처럼 보인다는 장점이 있음
}