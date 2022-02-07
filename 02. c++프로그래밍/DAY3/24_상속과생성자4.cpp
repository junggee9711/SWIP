// 24_상속과생성자4

#include <string>


class Person			
{
	std::string name;
	int age;
public:
	// 사람을 생성할때는 꼭 초기화 해달라! - 안전하게 사용하자는 것
	// => Person s; 처럼 선언하면 에러, 
	//	  생성자가 아예 없다면 디폴트 생성자를 부르겠지만,
	//	  생성자가 있으므로 해당 생성자에 인자를 전달 해야 함.
	Person(const std::string& n, int a) : name(n), age(a) {}
};

class Student : public Person		
{									
	int id;		
public:
	// 아래 처럼 하면 기반 클래스에 디폴트 생성자가 없기 때문에
	// 컴파일 에러 입니다.
//	Student(int n) : id(n) {}			// Student(int n) : Person(), id(n) {}

	// Student 생성자를 만들때 기반 클래스인 Person 이 요구하는 이름과 나이도 받아야 합니다.
	Student(const std::string& name, int age, int n)
		: Person(name, age), id(n) {}	// 기반 클래스의 "존재하는" 생성자를 호출하도록 코딩
};



int main()
{
//	Student s(10);
	Student s("lee", 25, 11);		// ok.
									// => 이렇게 하면, Person 의 멤버 변수 name, age 도 초기화 가능
}