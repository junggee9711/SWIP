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
	// override : 기반클래스가 가지고있는 함수를 "같은이름"으로 파생 클래스가 가질 수 있다.
	// overloading : square(int), square(double) 과 같이 이름은 같고 인자의 타입은 다른 것
	void cry() { std::cout << "Dog cry" << std::endl; }				// 2
	virtual void cry2() { std::cout << "Dog cry2" << std::endl; }				
};



int main()
{
	Animal a;
	a.cry();				// 1을 부름
	Dog    d;
	d.cry();				// 2를 부름


	Animal* p = &d;			// d 를 기반클래스 포인터로 가리켰을때는?
	p->cry();				// (*p).cry();, 논리적으로 Dog의 cry 가 맞다. (p가 가리키는 d가 Dog 객체이므로)
							// 그런데, C++ 에서는 Animal의 cry 를 부른다.
	p->cry2();				// dynamic binding 으로 Dog의 cry2()를 부름.
}

// p->cry() 를 어떤 함수와 연결할 것인가?
// => "함수 바인딩" 문제 ( 교재 161 page )

// 1. static binding : 컴파일러가 "컴파일 시간"에 함수 호출을 결정.
//					   컴파일러는 p의 타입이 "Animal*" 이라는 것만 알고,
//					   실제 p가 가리키는 객체가 무엇인지는 알 수 없다.
//					  => 그러므로 Animal 의 cry() 호출.
// 빠르다. 논리적이지 않다. C++/C#.

// 2. dynamic binding : 컴파일러가 컴파일 시에 p가 가리키는 메모리를 조사하는 기계어 코드 생성
//						"실행시" p가 가리키는 곳의 객체를 조사한 후 함수 호출 결정.
//					  => 그러므로, Dog 가 객체 안에 있었다면, Dog 의 cry() 를 호출.
// 느리다. 논리적이다. java/python/swift 등 대부분의 객체지향 언어.

// => C++ 과 C# 의 virtual 키워드는 dynamic binding 을 하게끔 한다!