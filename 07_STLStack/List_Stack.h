#pragma once

#include <Windows.h>
#include <string>
using namespace std;

template<typename T> class Stack
{
public:
	struct Node;

public:
	Node* Top() { return top; }
	bool IsEmpty() { return head == NULL; }

	void Push(Node* node)
	{
		if (head != NULL)
		{
			Node* tail = head;

			while (tail->Next != NULL)
				tail = tail->Next;

			tail->Next = node;
		}
		else
		{
			head = node;
		}

		top = node; //���� ��尡 ž��������.
	}

	Node* Pop()
	{
		Node* temp = top;

		if (head == top) //�ƹ��͵� ���� ����
		{
			head = NULL;
			top = NULL;
		}
		else
		{
			Node* tail = head;
			while (tail != NULL && tail->Next != top)
				tail = tail->Next;

			top = tail;
			tail->Next = NULL;
		}

		return temp;
	}

	int Size()
	{
		int count = 0;
		Node* current = head;

		while (current != NULL)
		{
			current = current->Next;
			count++;
		}

		return count;
	}

	//Ŭ���� ������ ���� ���� ����, Ŭ���� �� ������ ������� �����Ƿ� ������.
	static Node* Create(T data) 
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}

	static void Destroy(Node* node)
	{
		delete node;
		node = NULL;
	}

public:
	struct Node
	{
		Node* Next;

		T Data;
	};

private:
	Node* head = NULL;
	Node* top = NULL;
};