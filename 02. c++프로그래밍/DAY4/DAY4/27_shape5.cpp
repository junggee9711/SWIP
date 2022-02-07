// 27_shape5

#include <iostream>
#include <vector>

class Shape
{
	int color;
public:

	void setColor(int c) { color = c; }

	// 1. 가상함수로 만드는 것 : 파생클래스가 만들지 않으면 베이스클래스의 구현을 물려주겠다는것.
	// 2. 순수 가상함수로 만드는것 : 물려주지 않을거고, 파생클래스에게 "꼭" 만들라고 시키는 것.

//	virtual void draw() { std::cout << "Draw Shape" << std::endl; }
	virtual void draw() = 0;
	virtual Shape* clone() const = 0;
	// 1) "Shape" 은 그리고, 복제할수 있는게 아니므로 순수 가상함수를 사용하는게 좋음.

	// 2) 아래 의미는 "getArea()" 를 제공하지 않은 도형의 경우는 "-1이 반환된다"
	//  => 이정도의 도움말은 필요하기때문에 가상함수로 만듬
	virtual double getArea() const { return -1; }
};

class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "Draw Rect" << std::endl; }
	
	// 3. 가상함수 재정의시 "반환 타입"을 상속관계 타입끼리 변경 가능합니다.
	//    아래 코드에서 "int*" 등으로의 변경은 안됩니다.
//  virtual Shape*clone() const override
	virtual Rect* clone() const override
	{
		Shape* p = new Rect;
		return p;
	}
};

class Circle : public Shape
{
public:
	virtual void draw() override  { std::cout << "Draw Circle" << std::endl; }
	virtual Circle* clone() const override
	{
		Shape* p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) {

			Shape* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2) {
			v.push_back(new Circle);
		}
		else if (cmd == 9) {
			for (auto p : v)
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 만들었던 도형을 복제할까요 >> ";
			int k;
			std::cin >> k;

			Shape* p = v[k - 1]->clone();
			v.push_back(p);
		}
		else if (cmd == -1)
			break;
	}

	for (auto p : v)
		delete p;					// new 로 동적할당한 메모리 제거
}


