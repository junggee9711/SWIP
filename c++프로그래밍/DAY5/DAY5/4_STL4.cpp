// 3_STL4

#include <iostream>
#include <vector>
#include <list>				
#include <set>			
#include <unordered_set>


int main()
{
	// 컨테이너가 primitive 타입을 저장하기도 하지만..
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	// 컨테이너가 컨테이너를 저장하는 아주 훌륭한 코드가 가능합니다.
	std::vector< std::list<int> > v2(10);	// 10개짜리 vector(배열), 각 요소는 list

	v[0] = 10;
	v2[0];
	v2[0].push_back(1);
	v2[0].push_back(2);
	v2[0].push_back(3);
	v2[1].push_back(20);
	v2[1].push_back(30);


	// 컨테이너끼리 조합하면, 아주 재미있는 구조를 만들수 있습니다.
	// STL 의 아주 좋은 장점..
	std::vector< std::set<int> > v(3);		// 10개짜리 vector(배열), 각 요소는 tree(set)

	std::vector< std::vector<int> > matrix(3, std::vector<int>(3));
	// => "std::vector<int>(3)" 임시 객체라는 표기법 (안배움)
	matrix[0][0] = 10;						// ok.
}






