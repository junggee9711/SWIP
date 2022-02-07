// 26 page


#include <iostream>
#include <string>


int main()
{
	// C언어 문자열 : char[] 또는 char* - 너무 불편합니다.
	char s1[] = "ABCD";
	char s2[5];

	// s2 = s1;				// error. strcpy() 필요

	if (s2 == s1) {}		// error 는 아니지만, 주소를 비교하므로 항상 false
							// strcmp(s2, s1) == 0 이면 서로 같은 문자열

	// 1. string 헤더를 사용한 문자열
	std::string s3 = "ABCD";
	std::string s4;

	s4 = s3;				// 1) 대입 가능
	s4 = s4 + s3;			// 2) 덧셈도 가능 (s4 = "ABCDABCD", 곱셈은 불가)

	if (s4 == s3) {}		// 3) 이렇게 비교도 가능

	std::cout << s4 << std::endl; // 4) 출력도 가능

	//	=> 즉, s3, s4 는 int 타입처럼 사용 가능하다


}