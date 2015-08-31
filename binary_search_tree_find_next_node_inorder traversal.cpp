/*

This program is used to design an algorithm to find the next node of a given node
in a binary search tree. (Next node as per inorder tree traversal)

It is assumed that each node has a link to its parent

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/30/2015

*/

#include <iostream>

struct TreeNode
{
	int data_;

	TreeNode* left_;

	TreeNode* right_;

	TreeNode* parent_;
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
		//TODO: Yet to define the destructor
	}

	// Gives the successor to a given node
	TreeNode* giveNextNode( TreeNode* leaf ); 
};

TreeNode* Tree::giveNextNode( TreeNode* leaf )
{
	int parent_value = leaf->parent_->data_;

	if ( leaf->right_ != NULL )
	{
		return leaf->right_;
	}

	else
	{
		if ( leaf->data_ <= parent_value )
		{
			return leaf->parent_;
		}
		else if ( leaf->data_ > parent_value )
		{
			if ( leaf->data_ > leaf->parent_->parent_->data_ )
			{
				// END of tree
				return NULL;
			}
			else
			{
				return leaf->parent_->parent_;
			}
		}
	}
}

int main()
{

}