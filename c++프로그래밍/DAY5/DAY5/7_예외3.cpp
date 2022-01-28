// 8_예외3


#include <iostream>

// 3. 예외를 던질때도 사용자 정의 타입을 만들어서 던지는 것이 규칙입니다.
class DisconnectWifi
{
	// 다양한 에러 정보를 담아서 전달하세요
};
class MemoryException
{
	// 다양한 에러 정보를 담아서 전달하세요
};

int ConnectServer()
{
	if (1) {
//		throw 1;			
		MemoryException e;
		throw e;
	}

	return 0;
}


int main()
{


	try
	{
		int ret = ConnectServer();
		std::cout << "위에서 예외가 발생하지 않아야 여기가 실행 됩니다." << std::endl;
	}
	catch (const MemoryException& e)
	{
		std::cout << "예외 발생" << std::endl;

	}
	catch (const DisconnectWifi& e)
	{
	}
//	catch (...)	// 위에서 잡히지 않은 모든 예외 처리

	std::cout << "프로그램 계속 실행" << std::endl;

}