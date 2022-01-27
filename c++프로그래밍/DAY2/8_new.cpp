// 8_new1 52 page


#include <iostream>
#include <cstdlib>		// malloc 을 위해. visual c 는 없어도 되긴합니다.

int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	free(p1);

	// C++ 스타일의 동적 메모리 할당
	int* p2 = new int;				// "new 타입" 로 메모리 할당
	delete p2;

	int* p3 = new int[10];			// 배열 모양 할당 (sizeof(int)*10 아님)
	delete[] p3;					// => "delete[]" 로 제거해야 합니다.
}

//			    [정체]				[반환 타입]		   [인자]		[핵심]
// malloc :		 함수			void* (캐스팅 필요)		크기		생성자 호출 안됨
// new	  :	 키워드(연산자)		정확한 타입으로 반환		타입		 생성자 호출 됨

//		 => 키워드 : 컴파일러에 약속 되어있는 단어. 다르게 사용 불가.