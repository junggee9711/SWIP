// 43 page


// - Reference 특징
// 1) 함수가 레퍼런스를 인자로 받는 경우

#include <iostream>

void inc1(int  n) { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }
 
int main()
{
	int a = 10, b = 10, c = 10;

	inc1(a);		// call by value	 => a 값 변경 실패
	inc2(&b);		// call by pointer   => b 값 변경 성공
	inc3(c);		// call by reference => c 값 변경 성공
					// 레퍼런스는 int& r = n; 와 같이 초기화 하기 때문에 c 전달
					// => inc3 함수에는 int& r = c 와 같이 전달
					// => c 변수 주소의 또 다른 이름이 r 라는 의미

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	int* p = 0;		// 된다.
//	int& r;			// 안된다.
}


// 2) 안정성
void f1(int* p)
{
	// pointer : 안전하려면 if 문 필요
	if (p != 0) {
		*p = 10;
	}
}

void f2(int& r)
{	
	// reference: if 문 필요없다. 안전하다.
	r = 10; 
}



// 결론 : 함수를 만들때, 
//		  레퍼런스로 받는것은 포인터로 받는 것과 유사하지만,
//		  좀 더 편리하고, 안전다.
//		  하지만 대부분, 포인터만으로도 다 구현 가능하다.