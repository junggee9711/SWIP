// 13_멤버초기화리스트2 87 page

// - 멤버 초기화 리스트가 반드시 필요한 경우 1


class Test
{
	int a;
	int b;
	const int c;		// 상수는 무조건 초기화 해야 하지만, 아래 : c(x) 에서 초기화 됨.

public:
	Test(int x) : c(x)	// * ok. 대입이 아닌 진짜 초기화.
	{
//		c = x;			// 초기화가 아닌 대입입니다.
						// error. 상수는 대입될수 없습니다.
	}
};

int main()
{
	Test t(10);			// * class 를 선언 할때 () 안에 초기화 함수 인자를 넣어서 초기화 하면 됩니다.
	Test t = { 10 };	
	Test t{ 10 };		
	Test t = 10;        // 이런 방식들으로도 초기화가 가능합니다. (마치 Test 가 타입 인것 같이!)

	
}