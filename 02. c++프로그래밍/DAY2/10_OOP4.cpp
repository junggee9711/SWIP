// 10_OOP4

#include <iostream>

// - 멤버 함수의 메모리

struct Rect
{
	// 1) 멤버 데이터 (다른 언어는 필드(field) 라고도 합니다.)
	//   => Rect rc1, Rect rc2 를 선언하면 멤버 데이타만 각각 메모리에 저장됨.
	int left;
	int top;
	int right;
	int bottom;

	// 2) 멤버 함수 (다른 언어는 메소드(method) 라고도 합니다.)
	//   => Rect 를 여러번 선언해도 함수는 메모리에 한번만 저장됨.
	//   => 하나의 함수를 call 해서 '인자' 를 &rc1, &rc2 로 다른게 전달하는 것 뿐임.
	int getArea()								// int getArea(Rect* this). 컴파일러가 바꿔줌
	{
		return (right - left) * (bottom - top);	// (this->right - this->left)
	}											// this->right == *this = right

	void draw()									// void draw(Rect* this)
	{
		std::cout << "draw rect" << std::endl;
	}
};


int main()
{
	Rect rc1 = { 1,1,10,10 };
	Rect rc2 = { 2,2,5,5 };

	rc1.getArea();			// C++ 컴파일러가 객체를 "struct reference로" 함수 인자처럼 전달해 줍니다.
							// getArea(&rc1); / getArea(&rc2);
}