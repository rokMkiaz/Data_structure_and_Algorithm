#pragma once
template<typename T>
class BTree
{
public:
	struct Node;

public:
	BTree()
	{

	}
	~BTree()
	{
		DestroyTree(root);
	}

	void Root(Node* node) { root = node; }

	void PreOrder(Node* node)
	{
		if (node == NULL)
			return;

		printf(" %c", node->Data); //Root
		PreOrder(node->Left); //Left
		PreOrder(node->Right); //Right
	}

	void InOrder(Node* node)
	{
		if (node == NULL)
			return;

		InOrder(node->Left); //Left
		printf(" %c", node->Data); //Root
		InOrder(node->Right); //Right
	}

	void PostOrder(Node* node)
	{
		if (node == NULL)
			return;

		PostOrder(node->Left); //Left
		PostOrder(node->Right); //Right
		printf(" %c", node->Data); //Root
	}

private:
	void DestroyTree(Node* node)
	{
		if (node == NULL)
			return;

		DestroyTree(node->Left);
		DestroyTree(node->Right);

		Destroy(node); //후위순회 하는 방식으로 노드삭제
	}

public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;
		
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
		Node* Left;
		Node* Right;

		T Data;
	};
private:
	Node* root;
};