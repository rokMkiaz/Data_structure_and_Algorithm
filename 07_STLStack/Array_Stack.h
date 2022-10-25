#pragma once
#define MAX_STACK_COUNT 5

#include <stdio.h>
#include<assert.h>
#include<Windows.h>

template<typename T> class Stack
{
public:
	Stack()
	{
		memset(values, 0, sizeof(T) * MAX_STACK_COUNT);
		//ZeroMemory(values, sizeof(T) * MAX_STACK_COUNT); //memset�̶� �Ȱ���
	}

	void Push(T val)
	{
		assert(top +1  < MAX_STACK_COUNT);//Release��忡�� �ٳ��������⿡ ����

		values[++top] = val;
	}

	T Pop()
	{
		bool b = IsEmpty();
		assert(b == false);

		T val = values[top];
		memset(&values[top], 0, sizeof(T)); //�ʱ�ȭ ���ش�.

		top--;

		return val;
	}

	T Front()
	{
		return values[top]
	}

	T Back()
	{
		assert(top > -1);

		return values[0];
	}

	bool IsEmpty()
	{
		return top < 0 ? true : false;
	}

private:
	int top = -1; //top of point

	T values[MAX_STACK_COUNT];
};