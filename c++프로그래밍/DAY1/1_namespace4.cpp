// 10 page

//#include <stdio.h> // C��� ���. namespace ��� ����(::)�� ����� �� ����.
#include <cstdio> // C++ �� ���. printf �� std ��� ��� ����.



//	C ���		  C++���
// <xxxx.h>   ==> <cxxxx>
// <stdio.h>  ==> <cstdio>
// <stdlib.h> ==> <cstdlub>
// <string.h> ==> <cstring>

// C++ ǥ�� ��� : .h �� ������� �ʴ´�.
//				  ��, ����ڰ� ���鶧�� .h �� �ٿ��� �ȴ�. (ǥ�ذ� �����ϱ� ���� ���̴°� ����)



int main()
{
	printf("hello\n"); // ok
	std::printf("hello\n"); // <cstdio> ����� include �ϸ� namespace ���� (::) ��� ����.
							// printf �� Cǥ��������, C++ ǥ���̱⵵ �մϴ�.
}