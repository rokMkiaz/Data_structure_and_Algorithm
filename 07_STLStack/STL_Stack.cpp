#include <stdio.h>
#include <stack>
using namespace std;

void main()
{
	stack<int> s;
	s.push(10);//가 성능이 더 좋음 s.emplace
	s.push(20);
	s.push(30);

	while (s.empty() == false)
	{
		int top = s.top(); //가져오고 제거x
		printf("Top : %d\n", top);

		s.pop(); //맨위에꺼를 가져와서 버림.
	}
}