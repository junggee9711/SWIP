// 22_상수멤버함수3 

#include <iostream>
#include <vector>

class Test
{
	int value = 0;		
public:
	// 1) 동일 이름의 상수/비상수 멤버할수를 제공할 수 있습니다. (124 page 중간)
	int& foo() { std::cout << "foo" << std::endl; return value; }					// 1
	int  foo() const { std::cout << "foo const" << std::endl; return value;}		// 2
};

int main()
{
	const Test ct;		// 이렇게 사용하면 Test 안의 value 가 const 이기 때문에 value 초기화가 필요
	ct.foo();			// 2번만 가능. 상수객체는 상수 멤버 함수만 호출 가능.
//	ct.foo() = 10;		// error. return by reference.

	Test t;
	t.foo();			// 1번 호출, 1번이 없으면 2번 호출
	t.foo() = 10;		// ok. return by value.


	// 2) 상수객체와 비상수객체가 하는 일이 동일하면, 2번만 만드세요.
	//							하는 일이 다르면, 위처럼 2개 만드세요.

	std::vector<int>		vv = { 1,2,3 };
	const std::vector<int>	cv = { 1,2,3 };

	// 다음중 안돼야 하는 것은?
	int n1 = vv[0];		// 1
	int n1 = cv[0];		// 2
	vv[0] = 10;			// 3
//	cv[0] = 10;			// 4. error 나와야하고, error 나옵니다. 
						// => 같은 vector 함수인데 상수/비상수에 따라 다르게 동작

}