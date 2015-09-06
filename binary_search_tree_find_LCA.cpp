/*

This program is used to find the lowest common ancestor in a binary search tree

It is assumed that both the values already exist in the tree

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
	TreeNode* root;

public:
	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		// TODO: Yet to define
	}

	// Find the Lowest Common Ancestor between two given values 
	TreeNode* find_LCA( TreeNode* root, int value1, int value2 );
};

TreeNode* Tree::find_LCA( TreeNode* root, int value1, int value2 )
{
	if ( root == NULL )
	{
		return NULL;
	}
	else
	{
		if ( value1 <= root->value && value2 <= root->value )
		{
			find_LCA( root->left, value1, value2 );
		}

		else if ( value1 > root->value && value2 > root->value )
		{
			find_LCA( root->right, value1, value2 );
		}

		else
		{
			return root;
		}
	}
}

int main()
{

}