// 26_virtual1

#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; }		// 1
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }		
};

class Dog : public Animal
{
public:
	// override : ���Ŭ������ �������ִ� �Լ��� "�����̸�"���� �Ļ� Ŭ������ ���� �� �ִ�.
	// overloading : square(int), square(double) �� ���� �̸��� ���� ������ Ÿ���� �ٸ� ��
	void cry() { std::cout << "Dog cry" << std::endl; }				// 2
	virtual void cry2() { std::cout << "Dog cry2" << std::endl; }				
};



int main()
{
	Animal a;
	a.cry();				// 1�� �θ�
	Dog    d;
	d.cry();				// 2�� �θ�


	Animal* p = &d;			// d �� ���Ŭ���� �����ͷ� ������������?
	p->cry();				// (*p).cry();, �������� Dog�� cry �� �´�. (p�� ����Ű�� d�� Dog ��ü�̹Ƿ�)
							// �׷���, C++ ������ Animal�� cry �� �θ���.
	p->cry2();				// dynamic binding ���� Dog�� cry2()�� �θ�.
}

// p->cry() �� � �Լ��� ������ ���ΰ�?
// => "�Լ� ���ε�" ���� ( ���� 161 page )

// 1. static binding : �����Ϸ��� "������ �ð�"�� �Լ� ȣ���� ����.
//					   �����Ϸ��� p�� Ÿ���� "Animal*" �̶�� �͸� �˰�,
//					   ���� p�� ����Ű�� ��ü�� ���������� �� �� ����.
//					  => �׷��Ƿ� Animal �� cry() ȣ��.
// ������. �������� �ʴ�. C++/C#.

// 2. dynamic binding : �����Ϸ��� ������ �ÿ� p�� ����Ű�� �޸𸮸� �����ϴ� ���� �ڵ� ����
//						"�����" p�� ����Ű�� ���� ��ü�� ������ �� �Լ� ȣ�� ����.
//					  => �׷��Ƿ�, Dog �� ��ü �ȿ� �־��ٸ�, Dog �� cry() �� ȣ��.
// ������. �����̴�. java/python/swift �� ��κ��� ��ü���� ���.

// => C++ �� C# �� virtual Ű����� dynamic binding �� �ϰԲ� �Ѵ�!