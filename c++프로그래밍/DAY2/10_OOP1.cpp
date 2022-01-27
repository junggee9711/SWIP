// 10_OOP1

#include <iostream>


// 코드가 복잡한 이유
// : "사각형" 관련 작업을 하고 싶은데, "사각형 타입"이 없다.
//	 "사각형" 을 표현하기 위해 "int 변수 4개" 를 사용하기 때문에 복잡해진다.
 
//   => 쉬워지려면 "사각형 타입"이 있으면 된다.

// 좌표값이 주어지면 사각형의 면적을 구하고, 그림을 그리는 함수를 생각해 봅시다.
int getRectArea(int x1, int y1, int x2, int y2)
{
	return (x2 - x1) * (y2 - y1);
}

void drawRect(int x1, int y1, int x2, int y2)
{
	std::cout << "draw rect" << std::endl;
}

int main()
{
	int area = getRectArea(1, 1, 10, 10);
	
}