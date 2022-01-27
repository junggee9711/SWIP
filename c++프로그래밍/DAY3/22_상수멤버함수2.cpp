// 22_�������Լ�2 122 page


// ��� ��� �Լ��� ������ �ƴ� �ʼ� �����Դϴ�.

// ��ü�� ���¸� �������� ���� ��� ��� �Լ� (getter) �� �ݵ�� ������ �Լ��� ������ �մϴ�.
// => 122 page ���� �Ʒ� �κ�

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

	void move(int dx, int dy)				// �̷� �Լ��� ���� �ٲٱ� ������ "��� ��� �Լ�" �� �ڵ����� �ʰ�,
	{										// const Rect& r �� ���� class �� �޴� �������� ������� �ʽ��ϴ�.
		x += dx;
		y += dy;
	}
	int getArea() const { return w * h; }	// "��� ��� �Լ�"
};

//void f1(Rect r)							// user defined �϶� call by value : ���纻�� ���� �޸� ������� �߻�.
void f1(const Rect& r)						// ��� ��ü�� ���ڸ� �޾����Ƿ�,
{											// class Rect ���� "��ü�� ���¸� �������� ���� ��� �Լ�"�� 
											// ������ const �� �ٿ��� "��� ��� �Լ�" �� �ڵ� �ؾ� �մϴ�.
	int n = r.getArea();
}

int main()
{
	Rect r(1, 1, 3, 3);				// ��� ��ü �ƴ�.
	int n = r.getArea();			// ok.
	f1(r);
}