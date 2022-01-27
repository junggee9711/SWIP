// 27_shape1 152 page

#include <iostream>
#include <vector>

// - �Ŀ�����Ʈ�� ���� ����
// 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.
// 2. ��� ������ ������ ��� Ŭ����(Shape)�� �ִٸ�, ��� ���� �Ҽ� �ִ�. (upcasting �� ����)

// 3. ��� ������ ������ �Լ�(draw) �� �ݵ�� ��� Ŭ�������� �־�� �Ѵ�.
//	  �׷���, ��� Ŭ���� Ÿ������ ��� ����Ҷ� �ش� �Լ��� ����� �� �ִ�.
//	  ( static binding ������� �ϱ� ������ )
//	  => �׷�����, �̷��� �ϸ� ���Ŭ������ �Լ��� ����ϰ� �ȴ�.

// 4. �׷��Ƿ�, ��� Ŭ���� ��� �Լ���, �Ļ�Ŭ������ ������(override) �ϰ� �Ǵ� �Լ���
//	  �ݵ�� �����Լ�(virtual) �� �Ǿ�� �Ѵ�.

class Shape
{
	int color;
public:
	// �Ʒ� ��� �Լ��� "virtual" �� �� �ʿ� �������? No. �������� �ٸ��� ����Ǵ� �Լ��� �ƴ�.
	void setColor(int c) {color = c;}
	// �Ʒ� ������ ���ϴ� �Լ��� �������� �ٸ��ϴ�. ��, override �Ǿ�� �մϴ�.
	// = virtual �� �Ǿ�� �մϴ�.
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
			// Rect r; ==> �̷��� ����� {} ����� �ٷ� �ı��Դϴ�.
			Shape* p = new Rect;		// �̷��� �ؾ� �ı����� �ʽ��ϴ�.
			v.push_back(p);
		}
		else if (cmd == 2) {
			v.push_back(new Circle);	// �� ������ ���ٷ� ��������ϴ�.
		}
		else if (cmd == 9) {
			for (auto p : v)			
				p->draw();				// auto = shape*
										// shape �� draw() �� virtual �� �ƴϸ� �׻� shape �� draw() �� �θ�
		}

	}
}

