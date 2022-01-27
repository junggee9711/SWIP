// 10 page

//#include <stdio.h> // C언어 헤더. namespace 라는 문법(::)을 사용할 수 없음.
#include <cstdio> // C++ 용 헤더. printf 와 std 모두 사용 가능.



//	C 헤더		  C++헤더
// <xxxx.h>   ==> <cxxxx>
// <stdio.h>  ==> <cstdio>
// <stdlib.h> ==> <cstdlub>
// <string.h> ==> <cstring>

// C++ 표준 헤더 : .h 를 사용하지 않는다.
//				  단, 사용자가 만들때는 .h 를 붙여도 된다. (표준과 구별하기 위해 붙이는것 권장)



int main()
{
	printf("hello\n"); // ok
	std::printf("hello\n"); // <cstdio> 헤더를 include 하면 namespace 문법 (::) 사용 가능.
							// printf 는 C표준이지만, C++ 표준이기도 합니다.
}