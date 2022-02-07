#pragma once
// => 비주얼스튜디오에서 제공하는 간편한 전처리기로써,
//    어떠한 코드나 헤더파일이 다른 코드나 헤더에서 include 될때,
//    중복되어 복사되는 것을 방지하는 기능을 한다.


// Point.h 파일을 만들어서 선언을 넣으세요
class Point
{
	int x;
	int y;
public:
	// 클래스 안에는 멤버함수의 선언만 제공합니다.
	Point(int a, int b);
	~Point();
	void set(int a, int b);
};
