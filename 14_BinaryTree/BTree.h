#pragma

template<typename T>
class BTree
{
public:
	struct  Node;

public:
	BTree()
	{

	}

	~BTree()
	{

	}
	void PreOrder(Node* node) //전위
	{
		if (node == NULL)return;

		printf("%c", node->Data);//root->Left->Right
		PreOrder(node->Left);
		PreOrder(node->Right);
	}

	void InOrder(Node* node) // 중위
	{
		if (node == NULL)return;

		InOrder(node->Left); //Left->root->Right
		printf("%c", node->Data);
		InOrder(node->Right);
	}

	void PostOrder(Node* node) //후위
	{
		if (node == NULL)return;

		PostOrder(node->Left); //Left->Right->root
		PostOrder(node->Right);
		printf("%c", node->Data);
	}

	void Root(Node* node) { root = node; }
private:
	void Destroy(Node* node)
	{
		if (node == NULL)return;

		Destroy(node->Left);
		Destroy(node->Right);

		DestroyNode(node);
	}



public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;

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
		Node* Left;
		Node* Right;
	};
private:
	Node* root; 

};
