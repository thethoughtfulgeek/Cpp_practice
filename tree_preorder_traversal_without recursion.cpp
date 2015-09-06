/* 

This program does preorder tree traversal without recursion
It can be done without recursion using a stack

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 09/05/2015

*/

#include <iostream>
#include <stack>

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int value;
};

class Tree : public std::stack<TreeNode*>
{
private:
	TreeNode* root;

public:

	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		//todo: define constructor
	}

	// Does preorder tree traversal without recursion
	void preorder_traversal( TreeNode* root );
};

void Tree::preorder_traversal( TreeNode* root )
{
	if ( root != NULL )
	{
		stack stack1;
		stack1.push( root );

		TreeNode* current = root;

		while( current != NULL )
		{
			std::cout<<stack1.top()->value<<", ";
			current = stack1.top();
			stack1.pop();
			if ( current->right != NULL )
			{
				stack1.push( current->right );			
			}
			if ( current->left != NULL )
			{
				stack1.push( current->left );
			}
		}
	}
}


int main()
{

}