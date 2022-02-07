// 27_shape5

#include <iostream>
#include <vector>

class Shape
{
	int color;
public:

	void setColor(int c) { color = c; }

	// 1. �����Լ��� ����� �� : �Ļ�Ŭ������ ������ ������ ���̽�Ŭ������ ������ �����ְڴٴ°�.
	// 2. ���� �����Լ��� ����°� : �������� �����Ű�, �Ļ�Ŭ�������� "��" ������ ��Ű�� ��.

//	virtual void draw() { std::cout << "Draw Shape" << std::endl; }
	virtual void draw() = 0;
	virtual Shape* clone() const = 0;
	// 1) "Shape" �� �׸���, �����Ҽ� �ִ°� �ƴϹǷ� ���� �����Լ��� ����ϴ°� ����.

	// 2) �Ʒ� �ǹ̴� "getArea()" �� �������� ���� ������ ���� "-1�� ��ȯ�ȴ�"
	//  => �������� ������ �ʿ��ϱ⶧���� �����Լ��� ����
	virtual double getArea() const { return -1; }
};

class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "Draw Rect" << std::endl; }
	
	// 3. �����Լ� �����ǽ� "��ȯ Ÿ��"�� ��Ӱ��� Ÿ�Գ��� ���� �����մϴ�.
	//    �Ʒ� �ڵ忡�� "int*" �������� ������ �ȵ˴ϴ�.
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
			std::cout << "���° ������� ������ �����ұ�� >> ";
			int k;
			std::cin >> k;

			Shape* p = v[k - 1]->clone();
			v.push_back(p);
		}
		else if (cmd == -1)
			break;
	}

	for (auto p : v)
		delete p;					// new �� �����Ҵ��� �޸� ����
}


