// C와 다른 C++함수의 특징 4-2. 함수 템플릿2

#include <cstdio>

template<typename T>
T square(T a)
{
	return a * a;
}


int main()
{

	square(3);						
	square(3.4);					

	printf("%p\n", &square);		// error. square 는 메모리에 존재하는 함수가 아니고,
									//		  컴파일 시간에 컴파일러가 사용하는 "틀" 이기 때문에
									//		  메모리에 놓이는 것이 아니므로 주소는 구할수 없습니다.

	printf("%p\n", &square<int>);	// ok.	  (해당 함수의 주소는 위에서 선언한 square(3); 의 주소와 같음)
									// square<int> 는 틀을 사용해서 만든 함수입니다.
									// 메모리에 있으므로 주소를 구할수 있습니다.

}

// C++ 언어에서 가장중요한 것 : 객체 지향 + generic(template)