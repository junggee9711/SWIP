// 18_static_member_function2

class Test
{
	int idata;
	static int sdata;
public:
	/* 시험문제 : 다음중 에러를 모두 고르세요. */
	// static 멤버 데이터 : 객체가 없어도 메모리에 있다. (전역변수와 유사)
	// static 멤버 함수	 : 객체없이 호출 가능 (객체가 없어도 메모리에 있다.)
	void f1()			// 이 함수를 호출 했다는 것은 객체가 있다는 의미!
	{
		idata = 10;		// 1
		sdata = 10;		// 2
		f2();			// 3
	}

	// *핵심 : static 멤버 함수에서는 static 멤버 데이터/함수 만 접근 가능합니다.
	//		  => 객체를 만들고 static 멤버 함수를 불러도,
	//			 "문법상(this3 에서 설명)" static 멤버 데이터/함수 이외엔 접근 불가능하게 되어있음.
	static void f2()	// 이 함수는 객체 없이 호출 가능
	{
		idata = 10;		// 4. error. idata 는 객체가 없으면 메모리에 없다.
		sdata = 10;		// 5. ok.    sdata 는 객체가 없어도 메모리에 있다.
		f1();			// 6. errpr. f1()  은 객체가 없으면 메모리에 없다.
	}
};
int Test::sdata = 0;

int main()
{
//	Test::f2();			// 객체 없이 호출시 4, 6 에서 error.

	Test t;
//	t.f2();				// 객체를 선언후 호출해도 4, 6 에서 error.
}