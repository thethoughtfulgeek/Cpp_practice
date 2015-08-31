/* 

This program is used to determine if a given binary tree is a binary search tree or not

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/30/2015

*/

#include <iostream>
#include <climits>

struct TreeNode
{
	int data_;

	TreeNode* left_;

	TreeNode* right_;
};

class Tree
{
private:
	TreeNode* root;

	// Checks whether a given tree is a Binary Search Tree or not
	bool checkforBinarySearchTree( TreeNode* leaf, int min, int max );

public: 
	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		// destructor. TODO: Yet to define
	}
	
	// public interface function to check if a tree is Binary Search Tree
	bool isBinarySearchTree();
};

bool Tree::checkforBinarySearchTree( TreeNode* leaf, int min, int max )
{
	if ( leaf != NULL )
	{
		if ( leaf->data_ < min || leaf->data_ >= max )
		{
			return false;
		}

		else
		{
			if ( ( checkforBinarySearchTree( leaf->left_, min, leaf->data_ ) ) && ( checkforBinarySearchTree( leaf->right_, leaf->data_, max ) ) )
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	else
	{
		return true;
	}
}

bool Tree::isBinarySearchTree()
{
	return checkforBinarySearchTree( root, INT_MIN, INT_MAX );
}

int main()
{
	
}