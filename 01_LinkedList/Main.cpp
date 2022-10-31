#include <stdio.h>

struct Node
{
	int Data;
	
	Node* Next; //다음 포인터를 가리키는 주소
};

Node* Create(int data) //생성자
{
	Node* node = new Node();

	node->Data = data;
	node->Next = NULL; //다음노드는 없게하기위해 Null할당

	return node;
}

void Destroy(Node* node)
{
	delete node;
	node = NULL;
}

void Push(Node** head, Node* node) //데이터를 넣음
{
	if ((*head) == NULL)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = (*head);

		while (tail->Next != NULL) //리스트 끝 까지 검색
			tail = tail->Next;
		tail->Next = node;
	}
}
void InsertHead(Node** head, Node* node) //밀기
{
	if (*head == NULL)
		*head = node;
	else
	{
		node->Next = *head;
		*head = node;
	}
}
void Remove(Node** head, Node* remove) //구간 삭제
{
	if (*head == remove) //헤드와 remove가 같다면 헤드에 remove.Next를 가리키게 해준다.
	{
		*head = remove->Next;
	}
	else
	{
		Node* current = *head; 
		while (current != NULL && current->Next != remove)
		{
			//현재 노드가 remove대상을 찾을 때 까지 탐색
			current = current->Next;
		}
		if (current != NULL)
		{
			current->Next = remove->Next; //삭제할 대상의 다음을 가리킨다.
		}
	}
}

Node* GetNode(Node* head, int location)
{
	Node* current = head;

	while (current != NULL && --location >= 0)
		current = current->Next;

	return current;
}

int GetNodeCount(Node* head) //배열 갯수
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

int main()
{
	Node* list = NULL;
	for (int i = 0; i < 5; i++)
	{
		Node* node = Create(i);
		Push(&list, node);
	}

	int count = GetNodeCount(list);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(list, i);

		printf_s("List[%d] : %d\n", i, current->Data);
	}
	printf_s("\n");
	//////////////////////////////////////////////
	Node* temp = GetNode(list, 3);
	printf_s("List[%d] : %d\n", 3, temp->Data);
	printf_s("\n");
	//////////////////////////////////////////////
	Node* newNode = Create(-1);
	InsertHead(&list, newNode);

	count = GetNodeCount(list);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(list, i);

		printf_s("List[%d] : %d\n", i, current->Data);
	}
	printf_s("\n");

	//////////////////////////////////////////////
	Remove(&list, temp);
	count = GetNodeCount(list);

	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(list, i);
		printf_s("List[%d] : %d\n", i, current->Data);
	}
	printf_s("\n");


	return 0;
}