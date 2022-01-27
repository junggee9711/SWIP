// 23_상속1 132 page

#include <string>


// 1. 상속 : 기존 타입(class)를 확장해서 새로운 타입을 설계하는 문법
//			코드 중복을 줄일수 있고,
//			상속의 다양한 문법을 배우면 다양한 장점을 활용할수 있다.

class Person						// => Base(기반) class, super class, parent class 라는 용어를 씀
{
	std::string name;
	int age;
};

// 2. 1) C++    - class Student : public Person
//	  2) C#     - class Student : Person
//	  3) Python - class Student(Person)
//    4) java   - class Student extends Person
class Student : public Person		// Person 으로부터 Person 안의 "모든 멤버 변수/함수"를 상속받음
{									// => Derived(파생) class, sub class, child class 라는 용어를 씀
	int id;							// 133 page 의 그림(특히 화살표 방향)을 알아 두어야 합니다.
};
class Professor : public Person
{
	int major;
};

int main()
{
	Student s;
	Professor p;
}