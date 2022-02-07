// 2_연산자재정의6

// 라이브러리 설계자와 연산자 재정의
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
// string 이 이렇게 구현 되어있기 때문에 string 사이에 +, == 등의 연산자를 사용 가능한 것.

template<typename T>
class vector
{
public:
	T& operator[](int idx) { /*...*/ };
};
// vector 도 마찬가지.


int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";		
	std::string s3 = s1 + s2;		// s1.operator+(s2)
	s1 == s2;						// s1.operator==(s2)

	std::vector<int> v = { 1,2,3 };

	int n = v[0];					// v.opeartor[](0)

	// 연산자 재정의가 없다면 아래처럼 멤버함수로 접근 해야 합니다.
//	int n2 = v.getAt(0);
}