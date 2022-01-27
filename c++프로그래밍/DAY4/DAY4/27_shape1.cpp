// 27_shape1 152 page

#include <iostream>
#include <vector>

// - 파워포인트의 도형 구현
// 1. 모든 도형을 타입화 하면 편리하다.
// 2. 모든 도형의 공통의 기반 클래스(Shape)가 있다면, 묶어서 관리 할수 있다. (upcasting 에 의해)

// 3. 모든 도형의 공통의 함수(draw) 는 반드시 기반 클래스에도 있어야 한다.
//	  그래야, 기반 클래스 타입으로 묶어서 사용할때 해당 함수를 사용할 수 있다.
//	  ( static binding 방식으로 하기 때문에 )
//	  => 그렇지만, 이렇게 하면 기반클래스의 함수만 사용하게 된다.

// 4. 그러므로, 기반 클래스 멤버 함수중, 파생클래스가 재정의(override) 하게 되는 함수는
//	  반드시 가상함수(virtual) 가 되어야 한다.

class Shape
{
	int color;
public:
	// 아래 멤버 함수는 "virtual" 이 될 필요 있을까요? No. 도형마다 다르게 적용되는 함수가 아님.
	void setColor(int c) {color = c;}
	// 아래 면적을 구하는 함수는 도형마다 다릅니다. 즉, override 되어야 합니다.
	// = virtual 이 되어야 합니다.
	virtual double getArea() const { return 0; }
	virtual void draw() { std::cout << "Draw Shape" << std::endl; }
};



class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) {
			// Rect r; ==> 이렇게 만들면 {} 벗어날때 바로 파괴입니다.
			Shape* p = new Rect;		// 이렇게 해야 파괴되지 않습니다.
			v.push_back(p);
		}
		else if (cmd == 2) {
			v.push_back(new Circle);	// 위 두줄을 한줄로 만들었습니다.
		}
		else if (cmd == 9) {
			for (auto p : v)			
				p->draw();				// auto = shape*
										// shape 의 draw() 가 virtual 이 아니면 항상 shape 의 draw() 만 부름
		}

	}
}

