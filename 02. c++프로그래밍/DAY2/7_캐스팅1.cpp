// 7_캐스팅1 48 page

#include <iostream>


// C 스타일의 () 캐스팅 : 대부분의 경우 성공한다.
//						 그런데, 너무 위험하다.
int main()
{
	double d = 3.4;
//	int n = d;						// ok. but, 경고 발생.
	int n = (int)d;					// ok. 경고 없음.

	// void* => int* 로 변경 : 필요한 작업.
	int* p = (int*)malloc(100);
	free(p);




//	double* p1 = &n;				// error. n 은 원래 4byte 를 가리키고 있었는데,
									//	double 로 바꿔서 8byte 를 가리키게 됨
									//  => 4byte 가 추가되면서 다른 메모리 영역을 침범할수 있음.

	// int* => double* 로 변환 : 너무 위험하다.
	//							그런데, c캐스팅은 허용.
	double* p1 = (double*)&n;		// ok. 캐스팅하면 허용하기 때문에 위험함.
	*p1 = 3.4;





	const int c = 10;
//	int* p2 = &c;					// error. 상수를 비상수를 가리키는 포인터에 담을수 없다.
	int* p2 = (int*)&c;				// ok. 캐스팅하면 허용하기 때문에 위험함.
	*p2 = 20;
		
	std::cout << c << std::endl;	// 10 - 컴파일러가 10 을 메모리에 저장하는 것이 아니라, '치환' 하여 출력
	std::cout << *p2 << std::endl;	// 20
}