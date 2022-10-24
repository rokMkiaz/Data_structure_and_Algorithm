#include<stdio.h>

struct Node
{
	Node* Prev;
	int Data;
	Node* Next;
};

Node* Create(int data)
{
	Node* node = new Node();

	node->Data = data;
	node->Prev = node->Next = NULL;

	return node;
}
void Destroy(Node* node)
{
	delete node;
	node = NULL;
}

void Push(Node** head, Node* node)
{
	if (*head == NULL)
	{
		*head = node;
		(*head)->Next = *head;
		(*head)->Prev = *head; //앞뒤연결이 없으므로 붙힘
	}
	else
	{
		Node* tail = (*head)->Prev;

		tail->Next->Prev = node;
		tail->Next = node;

		node->Next = (*head);
		node->Prev = tail;
	}
}

void Insert(Node* current, Node* node)
{
	node->Next = current->Next;
	node->Prev = current;

	current->Next->Prev = node;
	current->Next = node;
}

void Remove(Node** head, Node* remove)
{
	if (*head == remove)
	{
		(*head)->Prev->Next = remove->Next;
		(*head)->Next->Prev = remove->Prev;

		*head = remove->Next;
	}
	else
	{
		Node* temp = remove;
		remove->Prev->Next = temp->Next;
		remove->Next->Prev = temp->Prev;

	}

	remove->Prev = remove->Next = NULL;
}

Node* GetNode(Node* head, int location)
{
	Node* current = head;

	while (current != NULL && (--location) >= 0)
		current = current->Next;

	return current;
}

int GetNodeCount(Node* head)
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


void main()
{
	Node* head = NULL;
	for (int i = 0; i < 5; i++)
	{
		Node* node = Create(i);
		Push(&head, node);
	}

	//Node* newNode = NULL;
	//{
	//	newNode = Create(-1);
	//
	//}

	int count = 0;
	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, i);
		printf_s("List[%d] : %d\n", i, current->Data);
	}
	printf_s("\n");

}