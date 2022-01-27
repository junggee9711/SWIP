// 6_레퍼런스5 45 page


struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};

// 1. call by value 는 인자의 값을 변경하지 않겠다는 약속.
//	  하지만, 복사본에 의한 메모리 오버헤드가 존재 한다.
// 2. const reference 를 사용하면 복사본 없이
//	  인자의 값을 변경하지 않겠다고 약속할 수 있다. 
//	  (call by value 처럼 메모리를 추가로 사용하지 않으면서)

//void foo(? r)
void foo(const Rect& r)
{
//	r.left = 10;			// error. 발생 시킬수 있음
}

int main()
{
	Rect r = { 1, 1, 10, 10 };
	foo(r);					// 조건 : foo 는 절대로 r의 상태를 변경해서 입력 받으면 안된다.
}




// 다음중 좋은 코드는 ?
void foo(int n) {}			// 1. 좋은 코드 
							//	- 위의 설명으로는 2번이 좋은 코드 같지만, 아님.
							//  - primitive type 은 사용 메모리가 작고, 최적화가 잘 적용되기 때문.
void foo(const int& n) {}	// 2. 좋지 않다.


// 결론 : 함수 인자를 받는 방법
//		1. 인자값을 변경하려면,
//		   => 포인터도 좋고, reference 도 좋습니다.
//			  요즘은 "reference 가 좀더 널리 사용"
//			  swap(int*, int*)
//			  swap(int&, int&)
//
//		2. 인자값을 변경하지 않겠다면,
//		   A. primitive type (int, double..) : "call by value" 
//											=> ex. void foo(int n)
//		   B. user define type (struct..)    : "const reference"
//											=> ex. void foo(const Rect& r)



// 구글 "C++ core guideline" 검색해 보세요 - 1번째링크