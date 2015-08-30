/*

This program is used to implement a binary search tree
It has subroutines for insertion, and searching
Insertion takes n*logn time complexity to fill the entire tree with n different values in the average/best case scenario
Searching takes logn time in the average/best case scenario

It also has a subroutine for destroying the entire node by node, starting from the leaf and going up to the root recursively

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/29/2015

*/

#include <iostream>

struct Treenode
{
	int data_;
	
	Treenode* left_;

	Treenode* right_;
};

class Tree
{
private:
	Treenode* root;

	// Insert a node into the tree (private function called internally)
	void insertNode( int value, Treenode* leaf );

	// Searching for a particular node inside the tree (private function called internally)
	Treenode* searchTree( int value, Treenode* leaf );

	// Destroying the entire tree one node at a time (private function called internally)
	void destroyTree( Treenode* leaf );

public:
	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		destroyTree();
	}

	// Insert a node into the tree
	void insertNode( int value );

	// Searching for a particular node inside the tree.
	// Takes the value to be searched as input and returns pointer to the node
	Treenode* searchTree( int value );

	// Front function for Destroying the entire tree (called once inside the destructor)
	void destroyTree();
};

void Tree::insertNode( int value, Treenode* leaf )
{
	if ( value < leaf->data_ )
	{
		if ( leaf->left_ == NULL )
		{
			leaf->left_ = new Treenode;
			leaf->left_->data_ = value;
			leaf->left_->left_ = NULL;
			leaf->left_->right_ = NULL;
		}
		else
		{
			insertNode( value, leaf->left_ );
		}
	}

	else if ( value >= leaf->data_ )
	{
		if ( leaf->right_ == NULL )
		{
			leaf->right_ = new Treenode;
			leaf->right_->data_ = value;
			leaf->right_->left_ = NULL;
			leaf->right_->right_ = NULL;
		}
		else
		{
			insertNode( value, leaf->right_ );
		}
	}
}

Treenode* Tree::searchTree( int value, Treenode* leaf )
{
	if ( leaf != NULL )
	{
		if ( value == leaf->data_ )
		{
			return leaf;
		}
		else if ( value < leaf->data_ )
		{
			return searchTree( value, leaf->left_ );
		}
		else if ( value > leaf->data_ )
		{
			return searchTree( value, leaf->right_ );
		}
	}

	else
	{
		return NULL;
	}
}

void Tree::destroyTree( Treenode* leaf )
{
	if ( leaf != NULL )
	{
		destroyTree( leaf->left_ );
		destroyTree( leaf->right_ );
		delete leaf;
	}
}

void Tree::insertNode( int value )
{
	if ( root == NULL )
	{
		root = new Treenode;
		root->data_ = value;
		root->left_ = NULL;
		root->right_ = NULL;
	}

	else
	{
		insertNode( value, root );
	}

}

Treenode* Tree::searchTree( int value )
{
	return searchTree( value, root );
}

void Tree::destroyTree()
{
	destroyTree( root );
}

int main()
{
	
}