// 22_�������Լ�3 

#include <iostream>
#include <vector>

class Test
{
	int value = 0;		
public:
	// 1) ���� �̸��� ���/���� ����Ҽ��� ������ �� �ֽ��ϴ�. (124 page �߰�)
	int& foo() { std::cout << "foo" << std::endl; return value; }					// 1
	int  foo() const { std::cout << "foo const" << std::endl; return value;}		// 2
};

int main()
{
	const Test ct;		// �̷��� ����ϸ� Test ���� value �� const �̱� ������ value �ʱ�ȭ�� �ʿ�
	ct.foo();			// 2���� ����. �����ü�� ��� ��� �Լ��� ȣ�� ����.
//	ct.foo() = 10;		// error. return by reference.

	Test t;
	t.foo();			// 1�� ȣ��, 1���� ������ 2�� ȣ��
	t.foo() = 10;		// ok. return by value.


	// 2) �����ü�� ������ü�� �ϴ� ���� �����ϸ�, 2���� ���弼��.
	//							�ϴ� ���� �ٸ���, ��ó�� 2�� ���弼��.

	std::vector<int>		vv = { 1,2,3 };
	const std::vector<int>	cv = { 1,2,3 };

	// ������ �ȵž� �ϴ� ����?
	int n1 = vv[0];		// 1
	int n1 = cv[0];		// 2
	vv[0] = 10;			// 3
//	cv[0] = 10;			// 4. error ���;��ϰ�, error ���ɴϴ�. 
						// => ���� vector �Լ��ε� ���/������ ���� �ٸ��� ����

}