#include <iostream>

int g = 0;

//int x[1000000] = { 1, 2, 3 };					// 실행파일의 .data 에 들어가서 실행파일 메모리가 커짐

int x[1000000];									// 초기값이 없으면 실행파일 메모리 변화 x
											    // 초기값이 없으면, 실행파일에서 메모리로 올릴때 배열의 크기를 할당.

int main()
{
	x[0] = 10;

	int n = 0;
	
	int* p = new int;

	const char* s = "Hello";					// s는 상수 메모리에 놓인 "Hello"를 가리킵니다.

	printf("전역변수 주소 : %p\n", &g);
	printf("지역변수 주소 : %p\n", &n);
	printf("동적할당 메모리 주소 : %p\n", p);		// &p 가 아닙니다. (p 가 가리키는 곳의 주소를 보고싶음)
	printf("main 함수주소 : %p\n", &main);
	printf("상수메모리 문자열주소 : %p\n", s);

	delete p;
}
// 실행 후 PEView 에서 확인해 보세요