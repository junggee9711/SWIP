// 29_�߻�Ŭ����

#include <iostream>


// �߻�Ŭ����(abstract class) : t���� �����Լ��� �Ѱ� �̻��� Ŭ����
// -   Ư¡    : ��ü�� �����Ҽ� ����.
// - ��� �ǵ� : Ư���� ��� �Լ��� �ݵ�� ������ �Ѵٰ� �����ϴ� ��!!!

class Shape
{
public:
	virtual void draw() = 0;	// ���� �����Լ� (pure virtual function)
								// �����ΰ� ����, "=0" ���� ������.
};

class Rect : public Shape
{
public:
	// �Ļ�Ŭ�������� Shape ���κ��� ��ӵ� "draw()" ���� �����Լ���
	//  1) �����θ� �������� ������ : Rect �� �߻�
	//  2)		   �����ϸ�        : Rect �� �߻� �ƴ�.
	virtual void draw() override {}
};



int main()
{
//	Shape s;					// error. �߻� Ŭ���� ��ü�� ����� ����.
	Shape* p;					// ok.	  ��ü�� �ƴ� �����ʹ� ����

	Rect r;						// ok.	  �Ļ�Ŭ�������� draw()�� �����θ� ���������Ƿ�
}