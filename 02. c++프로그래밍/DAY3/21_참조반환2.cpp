// 21_������ȯ2

#include <iostream>

struct Point
{
	int x, y;

	~Point() { std::cout << "~Point()" << std::endl; }
};

Point pt = { 1, 2 };

Point f1()				// ����ü Point �� return �ϴ� �Լ� f1()
{						// return by "value" 
	return pt;			// => return �� �ӽ� ��ü�� ����
}

Point& f2()				// return by "reference"
{						// => return �� �ӽ� ��ü�� ������ ����
	return pt;			
}

int main()
{
//	f1().x = 10;		// error.
						//	(���Ͽ����θ�������ӽð�ü).x = 10;
						// - �ӽð�ü Ư¡
						// 1. ��ȣ�� ���ʿ� �ü� ����.
						// 2. �Լ� ȣ�⹮���� ������ �ı� �ȴ�.
	std::cout << "----------" << std::endl;
	f1();				// <== �ӽð�ü�� ��ȯ and �ı� (�Ҹ��� ȣ��)
//	f2();				// pt ��ü�� ��ȯ

//	f2().x = 10;		// ok.
						// pt.x = 10;

	std::cout << "----------" << std::endl;
} // <== ���⼭ �������� pt �ı� (�Ҹ��� ȣ��)

#if 0
Point foo()
{
	Point p;
	return p;			// �Լ� ȣ���� ������ �������� p �� ��� �ɱ��?
						// 1. return �� ���� p �� ������ ������ �ӽð�ü�� ����� ����
						// 2. p �ı� (�Ҹ��� ȣ��)
						// 3. ���Ͽ� �ӽð�ü ��ȯ
						// 4. ���Ͽ� �ӽð�ü�� �Լ�ȣ���� ������ �ٷ� �ı�.

						// => �ᱹ ����ڰ� ������ �ʾ����� "��ü�� ����/�ı�"�ǰ� �ֽ��ϴ�.
}

// *���� !! ���� ���������� return by reference ���� ������
Point& f4()
{
	Point p;
	return p;			// �����Դϴ�. "undefined" �߻�.
}
#endif