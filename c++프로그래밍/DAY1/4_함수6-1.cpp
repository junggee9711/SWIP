// 37 page

// C와 다른 C++함수의 특징 6. 후위 반환 타입



int add1(int a, int b)
{
	return a + b;
}

// - suffix return type 또는 trailing return type
// 1) C++11 부터 나온 새로운 함수 모양
// 2) Python 에서 def add(a:int, b:int) -> int: 와 같음

auto add2(int a, int b) -> int // add1, add2 는 같음
{
	return a + b;
}

int main()
{
	int n = add1(1, 2);
}