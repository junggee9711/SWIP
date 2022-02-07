// 25 page

struct Point
{
	int x;
	int y;
};

int main()
{
	Point pt = { 1,2 };
	int arr[3] = { 1,2,3 };

	// 1. C++17 부터 구조체나 배열에서 값을 꺼낼때 아래처럼 가능합니다.
	//	-> "structure bining" 이라는 문법입니다.
	auto [x, y] = pt;		// int x = pt.x
							// int y = py.y
							// 파이썬 : x, y = (1, 2) ==> unpacking
							// 구조체의 성분을 x와 y라는 변수로 분리해서 받음
	// int[x1, y1] = pt;	// error. auto 만 됩니다.

	auto [a, b, c] = arr;	// 배열의 경우에도 가능.
							// 단, 갯수가 일치해야 합니다.
	// auto [a2, b2] = arr;	// error. 갯수 다름

}