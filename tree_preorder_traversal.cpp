/*

This algorithm prints out all the tree values in a simple pre-order tree traversal

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 09/05/2015

*/

#include <iostream>

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int value;
};

class Tree
{
private:
	TreeNode* node;

public:
	Tree()
	{
		node = NULL;
	}

	~Tree()
	{
		//TODO: Yet to define
	}

	// does pre-order tree traversal
	void pre_order( TreeNode* root );
};

void Tree::pre_order( TreeNode* current )
{
	if ( current == NULL )
	{
		return;
	}

	else
	{
		std::cout<<current->value<<", ";
		pre_order( current->left );
		pre_order( current->right );
	}
}

int main()
{

}

