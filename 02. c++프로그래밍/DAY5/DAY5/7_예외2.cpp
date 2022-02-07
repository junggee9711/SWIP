// 8_예외2
 
// 2. C++ : throw & catch 사용

#include <iostream>

int ConnectServer()
{
	if (1)
		throw 1;				// 함수가 실패하면,
								// "예외라는 것을 던집니다."
								// => 반환 값과 완전히 분리됩니다.

	return 0;
}


int main()
{
	// 아래와 같이 호출자가 "던져진 예외" 를 처리하지(잡지) 않으면 프로그램은 비정상 종료 됩니다.
//	int ret = ConnectServer();

	try
	{
		int ret = ConnectServer();
		std::cout << "위에서 예외가 발생하지 않아야 여기가 실행 됩니다." << std::endl;
	}
	catch (int n)			// <== ConnectServer() 에서 throw 한 값을 인자로 받음
	{
		std::cout << "예외 발생" << std::endl;
		// 복구 불가능한 예외라면 여기서 종료하세요. exit(-1) 등을 사용해서 종료.
		// 복구 가능하면 복구하세요.
	}
	std::cout << "프로그램 계속 실행" << std::endl;

	/* 시험문제 : 예외를 던질때/잡을때 쓰는 키워드를 고르세요. throw/catch */
}