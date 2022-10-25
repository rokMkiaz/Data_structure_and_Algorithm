#include <iostream>
#include <stdio.h>
using namespace std;

template<typename T> void Print(T data)
{
	cout << "함수 : " << data << endl;
}

template<typename T> void Print(int data) //특수화
{
	printf("특수화 : %d\n", data);
}

template<typename T> void Print(char data)
{
	printf("특수화 : %c\n", data);
}


void main()
{
	int i = 10;
	Print<int>(i);

	char b = 'A';
	Print<char>(b);

	float t = 20.0f;
	Print<float>(t);

	/*두가지 템플릿으로 다가기 때문에 오류 발생
	Print<int>(td);
	double td = 20.0L; 
	Print<int>(td);

	float td = 20.0L; 
	*/
}