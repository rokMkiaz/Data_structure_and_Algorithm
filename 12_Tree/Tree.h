#pragma once
template<typename T> class Tree
{
public:
	struct Node;

public:

	void AddChild(Node* parent, Node* child)
	{
		if (parent->LeftChild == NULL)
		{
			parent->LeftChild = child;
		}
		else
		{
			Node* node = parent->LeftChild;
			while (node->RightSibiling != NULL) //������ �������� ��� ������ Ÿ����.
				node = node->RightSibiling;

			node->RightSibiling = child;
		}
	}

	void PrintNode(Node* node, int depth)
	{
		for (int i = 0; i < depth; i++)
			printf("-");

		printf("%c\n", node->Data);

		if (node->LeftChild != NULL) //���� ��͸� Ÿ�� ��������
			PrintNode(node->LeftChild, depth + 1);

		if (node->RightSibiling != NULL)  //���� ��͸� ź��
			PrintNode(node->RightSibiling, depth);
	}

	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->LeftChild = node->RightSibiling = NULL;

		return node;
	}

	static void DestroyNode(Node* node)
	{
		delete node;
		node = NULL;
	}

public:
	struct Node
	{
		T Data;

		Node* LeftChild;
		Node* RightSibiling;
	};
};