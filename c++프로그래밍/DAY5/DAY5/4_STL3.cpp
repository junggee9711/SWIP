// 3_STL3 - 216 page

#include <iostream>

// 1. 컨테이너(Container) : 여러개의 요소를 보관하는 자료구조를 클래스로 만든것
//						  => 다른 언어에서는 "컬랙션(collection)" 이라고 합니다
//   1) 선형 컨테이너 3개
#include <vector>
#include <list>				// (linked) list
#include <deque>			// vector 여러개를 linked list 로 연결한 구조 (vector + list)

//   2) 비선형 컨테이너 2개
#include <set>				// tree : data 를 저장할때 크기 순서로 비교해서 저장
							//       => 검색도 빠르고, 크기순으로 정렬되어있음.
#include <unordered_set>	// hash : 데이터를 hash 함수를 통과시켜 주소를 얻어 저장 
							//       => 결과 주소가 같으면 linked list 로 연결
							//		 => 검색이 가장 빠름, 하지만 크기순으로 정렬 안됨.


int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	// 2. 핵심
	//  1) 컨테이너의 대부분 템플릿으로 만들어져 있다.
	//	   - Standard Template Library => "STL"
	//  2) 컨테이너들은 멤버 함수가 저의 동일하다 - 217 page 그림 참고
	v.push_back(20);
	s.push_back(20);

	//  3) 유일하게 선형 컨테이너중 vector 는 앞에 넣을수 없습니다.
	s.push_front(30);
//	v.push_front(30);		// error.
							// vector 앞에 넣으려면 성능저하가 너무 크기때문에,
							// 의도적으로 제공하지 않습니다.
	std::deque<int> d = { 1,2,3 };
	d.push_front(30);		// ok.

	//  4) 제거와 반환을 동시에 하는 멤버 함수는 없습니다. (Python 은 가능)
	int n = s.back();		// 반환만 합니다. 제거 안됩니다.
	s.pop_back();			// 제거만 합니다. 반환 안됩니다.

//	int n2 = s.pop_back();	// error. pop_back 은 void를 반환합니다.

	// 5) [] 연산은 연속된 메모리 컨테이너만 제공합니다. (vector, deque)
	v[0] = 0;				// ok.    vector 는 가능
	s[0] = 0;				// error. list 는 안됨
	d[0] = 0;				// ok.	  deque(덱, 디큐)는 가능


	/* 시험 문제 : 아래 내용 ! */
	// 3. 컨테이너의 사용
	//   1) [] 를 사용하고 싶은데, 앞에 삽입은 필요없다. : vector
	//   2) [] 를 사용하고 싶은데, 앞에 삽입은 필요하다. : deque
	//   3) 중간에 삽입/삭제를 많이 한다. : list
	//   4) 검색이 빨라야 하는데, 크기순서(not, 입력순서) 정렬이 필요하다 : tree (set)
	//   5) 무조건 검색이 중요하다. : hash (unordered_set)
}


// 비전공자분들은 "자료구조(data structure)" 꼭 학습해 보세요.



