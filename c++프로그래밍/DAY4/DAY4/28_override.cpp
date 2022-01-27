// 28_overide

#include <iostream>

class Shape
{
public:
	virtual void draw() { std::cout << "Shape draw" << std::endl; }
};

class Rect : public Shape
{
public:
	// 1. 파생클래스에서 가상함수 재정의시 "virtual" 은 붙여도 되고 안붙여도 됩니다.
	//	  => 가독성 측면에서는 붙이세요...
	// virtual void draw() { std::cout << "Rect draw" << std::endl; }

	// 2. 가상함수 재정의시 오타 발생!!
	//	  => Draw() 함수를 새로운 함수라고 생각하기 때문에 컴파일에러 나지 않습니다.
	// virtual void Draw() { std::cout << "Rect draw" << std::endl; }

	// 3. 2번 문제가 너무 심각해서 C++11에서 "overide" 키워드 도입
	//	  : 컴파일러에게 새로운 함수가 아니라, 기반 클래스 함수를 재정의 한다고 알려주는것
	// virtual void Draw() override { std::cout << "Rect draw" << std::endl; }
	// ==> error. 컴파일 에러가 나도록 할수 있음.

};



int main()
{
	Shape* p = new Rect;
	p->draw();
	delete p;
}