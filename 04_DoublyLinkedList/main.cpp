#include <stdio.h>

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
	if ((*head) == NULL)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = *head;

		while (tail->Next != NULL) //뒷부분 찾기
			tail = tail->Next;

		tail->Next = node; //신규노드 이어주기
		node->Prev = tail; //앞부분 이어주기
	}
}

void Insert(Node* current, Node* node) //삽입, 삭제 구간은 무조건 손코딩 익히기
{
	node->Next = current->Next;
	node->Prev = current;

	if (current->Next != NULL)
		current->Next->Prev = node;

	current->Next = node;
}

void InsertHead(Node** head, Node* node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		(*head)->Prev = node;
		node->Next = *head;
		*head = node;
	}
}

void Remove(Node** head, Node* remove) 
{
	if (*head == remove)
	{
		*head = remove->Next;

		if (*head != NULL)
			(*head)->Prev = NULL;
	}
	else
	{
		Node* current = remove;

		remove->Prev->Next = current->Next;
		if (remove->Next != NULL)
			remove->Next->Prev = current->Prev;
	}

	remove->Prev = NULL;
	remove->Next = NULL;
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

	Node* newNode = NULL;
	{
		newNode = Create(-1);
		InsertHead(&head, newNode);

		newNode = Create(-2);
		InsertHead(&head, newNode);
	}

	int count = 0;
	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, i);
		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");


	newNode = Create(100);
	Push(&head, newNode);

	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, i);
		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");


	Node* current = GetNode(head, 2);
	newNode = Create(1000);

	Insert(current, newNode);

	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, i);
		printf("List[%d] : %d\n", i, current->Data);
	}
	printf("\n");


	count = GetNodeCount(head);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(head, 0);

		if (current != NULL)
		{
			Remove(&head, current);
			Destroy(current);
		}
	}
}