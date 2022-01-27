#include <iostream>

// void f1(int arr[3])			
void f1(int* p, int size)
{

}

template<typename T, int N>		// 템플릿의 typename 대신 정수도 가능
int size(T (&arr)[N])
{
	return N;
}
int main()
{
	int x[3] = { 1,2,3 }		// 1) error. 배열은 복사될 수 없으므로!!

	f1(&x[0], 3);				// 2) 배열의 1번째 요소의 주소 전달
								//	  => 배열의 크기를 전달 해야함.
	f1(x, 3);					//	  => Decay 적용					

	int n = size(x);			// 3) C++ 에서는 배열의 크기를 구하는 함수도 만들 수 있습니다.

	for (auto n : x)			// 4) x 의 갯수를 구하는 원리가 위와 유사합니다.
	{

	}
}