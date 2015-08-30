/* 

This program is used to implement a program that checks if a binary tree is balanced or not.
If a binary tree is balanced, the height difference between the left and right subtrees of any node 
won't be more than 1

We won't go into the implementation details of the tree itself 
(for example, inserting a node, making a tree, deleting a node, searching for a node etc)
We will assume that pointer to the root of a binary tree is already provided to us. 
We just have to check if the tree is balanced or not

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/30/2015

*/

#include <iostream>
#include <cmath>

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

	// Internal function that recursively returns the height of each subtree starting from root
	int checkTreeHeight( TreeNode* leaf );

public:
	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		// Destructor yet to define
	}

	// Checking if the overall tree is balanced or not
	bool is_tree_balanced();

};

int Tree::checkTreeHeight( TreeNode* leaf )
{
	if ( leaf == NULL )
	{
		// Height of the tree/subtree is zero
		return 0;
	}

	// Checking height of the left subtree
	int left_tree_height = checkTreeHeight( leaf->left_ );
	if ( left_tree_height == -1 )
	{
		// Tree not balanced
		return -1;
	}

	// Checking height of the right subtree
	int right_tree_height = checkTreeHeight( leaf->right_ );
	if ( right_tree_height == -1 )
	{
		// Tree not balanced
		return -1;
	}

	// Checking nodes at the same level
	int height_diff = std::abs( left_tree_height - right_tree_height );
	if ( height_diff > 1 )
	{
		// Tree not balanced
		return -1;
	}
	else
	{
		return std::max( left_tree_height, right_tree_height ) + 1;
	}

}


bool Tree::is_tree_balanced()
{

	if ( checkTreeHeight( root ) == -1 )
	{
		return false;
	}

	else
	{
		return true;
	}
}

int main()
{

}

