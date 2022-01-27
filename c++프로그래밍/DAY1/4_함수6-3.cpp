#include <iostream>

template<typename T1, typename T2>
// ?? add(T1 a, T2 b)						// 1) ?? 부분은 T1, T2 가 어떤 type 인지에 따라 달라지기 때문에 채우기 어려움
// decltype(a+b) add(T1 a, T2 b)			// 2) 이 코드는 왜 에러일까요?
											//    인자 a, b 의 선언보다 decltype(a+b) 에서 변수 사용이 앞서 있기 때문에.
// auto add(T1 a, T2 b) -> decltype(a+b)	// 4) 후위 반환 타입을 사용하여 해결 가능. (C++11 스타일)
auto add(T1 a, T2 b)						// 5) C++14 부터는 후위 반환 타입코드 생략도 가능
{
	return a + b;
}

int main()
{
	std::cout << add<int, double>(1, 2.2) << std::endl; // 정확한 표기법

	std::cout << add(1, 2.2)			  << std::endl; // 타입 생략 가능.
														// 함수 인자로 타입 결정.

}