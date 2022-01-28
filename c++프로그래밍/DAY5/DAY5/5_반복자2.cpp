// 4_�ݺ���2
#include <iostream>
#include <vector>
#include <list>

class vector_iterator {};


template<typename T> class vector
{
public:
	// class �ȿ� class �� �����Ҽ� �ְ�,
	// �̰Ϳ� �����Ϸ��� "std::vector<int>::iterator" �̷� ǥ����� ����ؾ� ��
	class iterator {};
	// �Ǵ� typedef
	typedef vector_iterator iterator;
};


int main()
{
//	std::vector<int> c = { 1,2,3,4,5 };   // 1
//	std::list<int>   c = { 1,2,3,4,5 };   // 2

	int c[5] = { 1,2,3,4,5 };			  // 3

	// 1. �ݺ����� ��Ȯ�� Ÿ�� : "std::vector<int>::iterator"
	//	 - C++98 �������� �̷��� �ڵ��߾�� �մϴ�.
	//    ���� 1) �ʹ� ������ ���Դϴ�.
	//         2) �����̳� ����� �ڵ尡 �����Ǿ�� �մϴ�.
	std::vector<int>::iterator p = c.begin();		// <== 1, 2 �� ���� (3 �̸� error)

	// 2. C++11 ���ʹ� auto �� ���մϴ�.
	auto p = c.begin();								// <== 1, 2 �� ���� (3 �̸� error)
	// => ��� STL �����̳ʿ� ���� ����������, c�� "�Ϲ� �迭(raw array) ��� error.

	// 3. ����Լ� begin() ���� �Ϲ� �Լ� begin()�� �����ϴ�.
	auto p = std::begin(c);							// <== �Ϲ��Լ� begin() ����.
	//	 1) c �� STL �����̳ʶ��, ó���� ����Ű�� �ݺ��� ��ȯ
	//   2) raw array ���, �迭�� 1��° ��� �ּ� ��ȯ


	// <����>
	// 1. �ݺ��ڸ� ������ ����Լ� begin() ���� �Ϲ��Լ� begin() �� ����.
	// 2. �ݺ��ڸ� ������ "��Ȯ�� Ÿ��"�� ���°� ���� "auto" �� ����.
	/* ���蹮�� : std::vector<int>::iterator p = c.begin(); �� ǥ����� ������ ������ �´� ǥ����� */
}

// cppreference.com ���� "std::begin" �غ����� 
// => <iostream> �� raw array �� ���� std::begin �� �ֽ��ϴ�.
