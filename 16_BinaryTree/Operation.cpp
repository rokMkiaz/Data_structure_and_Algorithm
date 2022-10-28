#include <stdio.h>
#include "BTree.h"

#include <string>
using namespace std;

void Expression(const char* postfix, BTree<char>::Node** node)
{
	char* str = const_cast<char*>(postfix); //const_cast 허가없이 쓰면안됨.
	size_t length = strlen(str);

	char token = str[length - 1];
	str[length - 1] ='\0';

	switch (token)
	{
		case'+':case'-':case'/':case'*':case'%':
		{
			*node = BTree<char>::CreateNode(token);

			Expression(postfix, &(*node)->Right);
			Expression(postfix, &(*node)->Left);
		}
		break;

	    default: //숫자일 때 처리
	    {
	    	*node = BTree<char>::CreateNode(token);
	    }
	}
}

float Evaluate(BTree<char>::Node* node)
{
	if (node == NULL) return 0.0f;

	switch (node->Data)
	{
	case '+': case '-': case '*': case '/': case '%':
	{
		float left = Evaluate(node->Left);
		float right = Evaluate(node->Right);

		switch (node->Data)
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
		case '%': return (int)left % (int)right;
		}
	}
	break;

	default:
	{
		char temp[4];
		memset(temp, 0, sizeof(temp));

		temp[0] = node->Data;

		return atof(temp);
	}
	break;
	}

	return 0.0f;
}

void main()
{
	//(3*4) - (1+4)
	//34* 14+ -

	string postfix = "34/14+*";

	BTree<char>::Node* root = NULL;
	Expression(postfix.c_str(), &root);

	BTree<char>tree;
	tree.Root(root);

	printf("PreOrder\n");
	tree.InOrder(root);
	printf("\n\n");


	printf("PostOrder\n");
	tree.PostOrder(root);
	printf("\n\n");

	printf("Evalute : %f\n", Evaluate(root));
}