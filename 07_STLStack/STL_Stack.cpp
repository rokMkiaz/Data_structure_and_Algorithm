#include <stdio.h>
#include <stack>
using namespace std;

void main()
{
	stack<int> s;
	s.push(10);//�� ������ �� ���� s.emplace
	s.push(20);
	s.push(30);

	while (s.empty() == false)
	{
		int top = s.top(); //�������� ����x
		printf("Top : %d\n", top);

		s.pop(); //���������� �����ͼ� ����.
	}
}