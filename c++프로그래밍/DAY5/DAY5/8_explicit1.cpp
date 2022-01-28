// 8_explicit1

class Vector
{
	int size;
public:
	// explicit 생성자 : 해당 class 에 복사초기화는 사용할수 없고,
	//					 직접 초기화만 가능합니다.
	explicit Vector(int n) : size(n) {}
};

void f(Vector v) {}


int main()
{
	// 인자로 int 한개를 가지는 생성자가 있으면 아래 처럼 4가지 모양으로 객체생성됩니다.
	// C++98 시절 부터,
	Vector v1(10);			// direct initialization - 1
	Vector v2 = 10;			// copy initialization - 2 (복사초기화, = 을 사용하는 초기화 방법)

	// C++11 이후 부터,
	Vector v3{ 10 };		// direct initialization - 3
	Vector v4 = { 10 };		// copy initialization - 4

	f(10);					// ok. f(Vector v = 10) 이므로 2번에 의해서 가능
							// => 즉, 함수 인자 전달은 "복사 초기화"를 하는 표현식입니다.
							// 객체 f의 생성자가 explicit 생성자라면 error.
}