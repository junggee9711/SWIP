// 3_STL2

#include <iostream>
#include <vector>
#include <list>
#include <set>		// tree 자료구조. (그중에서도 heap)

int main()
{
	// * data 를 메모리에 어떻게 보관할 것인가?
//  1) 요소를 (배열처럼) 한줄로 보관 (sequence container)
//	  - vector : 연속된 메모리
//	  - list   : 모든 요소가 떨어진 메모리 (떨어졌지만 liked list로 한줄)
//  2) 한줄이 아닌 형태로 보관 (associative contatiner)
//	  - tree

	// 1. vector : 연속된 메모리. 
	//	1) 단점 : vector 중간에 삽입/삭제시 오버헤드(성능저하)가 있다.
	//			=> +1 메모리를 새로 할당하고, 삽입해야하기때문
	//  2) 장점 : 요소 순회(range for 등)가 빠르고, 
	//			  캐쉬 적중률이 높다. (연속된 메모리여서 캐쉬메모리에 한번에 올리기 좋다)
	std::vector<int> v = { 1,2,3,4,5 };
		
	// 2. list : 모든 요소가 떨어진 메모리 (linked list로 구현)
	//  1) 장점 : 중간에 삽입/삭제가 빠르다.
	//  2) 단점 : 요소 순회가 느리고, 캐쉬 적중률도 낮다.
	std::list<int> s = { 1,2,3,4,5 };

	std::set<int> s = { 10, 30, 60, 70, 20 };	// tree 를 만들면서 입력(초기화)
	
	std::set<int> s1;							// 만든후에 입력
	s1.insert(50);
	s1.insert(30);
	s1.insert(60);
	// 3. set : 요소가 tree(heap) 의 형태로 저장되는 메모리
	//  1) 장점 : 검색을 빠르게 할 수 있다.
	//  2) 단점 : 입력순서가 기록되지 않는다.
}





