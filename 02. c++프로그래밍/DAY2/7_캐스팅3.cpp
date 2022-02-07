// 7_캐스팅3

#include <iostream>

// 2. reinterpret_cast
//	  1) 좌변/우변 서로 다른 타입의 "주소" 캐스팅.
//	  2) 정수 <=> 주소 사이의 캐스팅.

int main()
{
	int n = 10;

//	double* p1 = static_cast<double*>(&n);			// error.
	double* p1 = reinterpret_cast<double*>(&n);		// ok. 의도적으로 이것이 가능하게 해서 해당 부분을 명시함

//	*p1 = 3.4;		// 단, 캐스팅 되어도 이렇게 사용하지는 말아야함.

//	int* p2 = 1000;									// error. pointer 는 0 이외 정수로 초기화 불가.
	int* p2 = (int*)1000;							// ok. 위험하다.
//	int* p2 = static_cast<int*>(1000);				// error. 정수를 주소로 저장하는것은 합리적이지 않음.
	int* p2 = reinterpret_cast<int*>(1000);			// ok.


	int n2 = reinterpret_cast<int>(3.4);			// error. 주소 관련 캐스팅만 가능.
													// static_cast 를 사용하거나,
													// 캐스팅을 안하면 ok.

}