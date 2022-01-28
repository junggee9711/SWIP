// QA

#include <iostream>

int x = 0;
int f1()  { return x; }
int& f2() { return x; }

int main()
{
	f1();	// 반환값은 "값 5"
	f2();	// 반환값은 x 메모리의 별명

	int n = 3;

	int ret = ++n * ++n;			// ++n 은 return by reference 입니다.

	std::cout << ret << std::endl;  // 결과 예측해 보세요 => undefined. but, 대부분 25

	std::cout << ++n  << ", " << ++n << std::endl;	// return by reference 이므로 5, 5 출력

	// 질문처럼 반복자뿐 아니라 raw pointer (진짜 포인터) 도 같은 방식입니다.
	int x[5] = { 1,2,3,4,5 };
	int* p = x;

	std::cout << *p << ", " << *++p << std::endl;	// p가 x[0] 을 가리 & return by reference 이므로 2, 2 출력


	// *위 내용들은 사실 모두 undefined 이기때문에 사용하지 마세요!
}