// 2_������������6

// ���̺귯�� �����ڿ� ������ ������
#include <iostream>
#include <string>
#include <vector>


class string
{
public:
	string operator+(const string& s)
	{
		//...
	}
	bool operator==(const string& s)
	{
		//..
	}
};
// string �� �̷��� ���� �Ǿ��ֱ� ������ string ���̿� +, == ���� �����ڸ� ��� ������ ��.

template<typename T>
class vector
{
public:
	T& operator[](int idx) { /*...*/ };
};
// vector �� ��������.


int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";		
	std::string s3 = s1 + s2;		// s1.operator+(s2)
	s1 == s2;						// s1.operator==(s2)

	std::vector<int> v = { 1,2,3 };

	int n = v[0];					// v.opeartor[](0)

	// ������ �����ǰ� ���ٸ� �Ʒ�ó�� ����Լ��� ���� �ؾ� �մϴ�.
//	int n2 = v.getAt(0);
}