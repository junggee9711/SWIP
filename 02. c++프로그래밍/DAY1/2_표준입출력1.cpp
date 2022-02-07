// 2_표준입출력1.cpp - 12 page

#include <cstdio>
#include <iostream> // 1. std::cout, std::cin 을 위한 헤더, printf 도 포함

int main()
{
	int	n = 10;
	double d = 3.4;

	// C 표준 출력 함수
	printf("%\n", n);

	// C++ 표준 출력 "객체" - printf 라는 함수를 불러오는 것이 아니라, std::cout 객체를 불러옴
	std::cout << n << ", " << d << std::endl; // '\n'; 대신 std::endl 을 사용하는 것을 권장
											  // %d 와 같은 변수 타입 지정 필요 없음

	// 표준 입력
	scanf_s("%d", &n); // C

	std::cin >> n; // C++
				   // 핵심 : "&n" 이 아니라 "n"
				   //        ">>" 방향에 주의 하세요.
}