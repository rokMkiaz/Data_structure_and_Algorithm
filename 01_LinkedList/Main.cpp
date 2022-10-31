#include <stdio.h>

struct Node
{
	int Data;
	
	Node* Next; //���� �����͸� ����Ű�� �ּ�
};

Node* Create(int data) //������
{
	Node* node = new Node();

	node->Data = data;
	node->Next = NULL; //�������� �����ϱ����� Null�Ҵ�

	return node;
}

void Destroy(Node* node)
{
	delete node;
	node = NULL;
}

void Push(Node** head, Node* node) //�����͸� ����
{
	if ((*head) == NULL)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = (*head);

		while (tail->Next != NULL) //����Ʈ �� ���� �˻�
			tail = tail->Next;
		tail->Next = node;
	}
}
void InsertHead(Node** head, Node* node) //�б�
{
	if (*head == NULL)
		*head = node;
	else
	{
		node->Next = *head;
		*head = node;
	}
}
void Remove(Node** head, Node* remove) //���� ����
{
	if (*head == remove) //���� remove�� ���ٸ� ��忡 remove.Next�� ����Ű�� ���ش�.
	{
		*head = remove->Next;
	}
	else
	{
		Node* current = *head; 
		while (current != NULL && current->Next != remove)
		{
			//���� ��尡 remove����� ã�� �� ���� Ž��
			current = current->Next;
		}
		if (current != NULL)
		{
			current->Next = remove->Next; //������ ����� ������ ����Ų��.
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

int GetNodeCount(Node* head) //�迭 ����
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