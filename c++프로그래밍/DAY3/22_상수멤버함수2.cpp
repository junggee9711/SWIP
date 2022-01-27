// 22_상수멤버함수2 122 page


// 상수 멤버 함수는 선택이 아닌 필수 문법입니다.

// 객체의 상태를 변경하지 않은 모든 멤버 함수 (getter) 는 반드시 상수멤버 함수로 만들어야 합니다.
// => 122 page 제일 아래 부분

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

	void move(int dx, int dy)				// 이런 함수는 값을 바꾸기 때문에 "상수 멤버 함수" 로 코딩하지 않고,
	{										// const Rect& r 와 같이 class 를 받는 곳에서는 사용하지 않습니다.
		x += dx;
		y += dy;
	}
	int getArea() const { return w * h; }	// "상수 멤버 함수"
};

//void f1(Rect r)							// user defined 일때 call by value : 복사본에 의한 메모리 오버헤드 발생.
void f1(const Rect& r)						// 상수 객체로 인자를 받았으므로,
{											// class Rect 에서 "객체의 상태를 변경하지 않은 모든 함수"는 
											// 무조건 const 를 붙여서 "상수 멤버 함수" 로 코딩 해야 합니다.
	int n = r.getArea();
}

int main()
{
	Rect r(1, 1, 3, 3);				// 상수 객체 아님.
	int n = r.getArea();			// ok.
	f1(r);
}