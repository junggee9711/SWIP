#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	int type;
	void setColor(int c) { color = c; }
	virtual double getArea() const { return 0; }

	virtual void draw() { std::cout << "Draw Shape" << std::endl; }
};
class Rect : public Shape
{
public:
	Rect() { type = 1; }
	virtual void draw() { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	Circle() { type = 2; }
	virtual void draw() { std::cout << "Draw Circle" << std::endl; }
};
class Triangle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Triangle" << std::endl; }
};
int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			Shape* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 만들었던 도형을 복제할까요 >> ";
			int k;
			std::cin >> k;

			// k번째 만들었던 도형의 복제본을 만들어서 v에 추가하려고 합니다.
			// 그런데, k 번째 도형은 뭘까요 ?
			// 어떻게 해야 할까요 ?
			// decltype(v[k - 1]); //는 무슨타입일까요 ? 1. Rect 또는 Circle
								//					 2. Shape*

			// 아래 코드는 OCP를 만족할수 없습니다.
			// 즉, Triangle 추가시 아래 코드도 수정되어야 합니다.
			switch (v[k - 1]->type)
			{
			case 1: v.push_back(new Rect);   break;
			case 2: v.push_back(new Circle); break;
			}
		}
	}
}