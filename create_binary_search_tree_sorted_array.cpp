/* 

This program is used to create a Binary Search Tree of minimal height from an already sorted array
The array is sorted in increasing order

In order to have the minimal height of a Binary Search Tree, we shall take the middle element of the sorted array 
as the root. 
The left subarray will form the left subtree
The right subarray will form the right subtree

Once that division is done, we shall recursively implement the same strategy for each sub arrays by choosing the middle element
each time as parents

It also prints out the entire sorted tree

*/

#include <iostream>
#include <iomanip>

class TreeNode
{
private:
	int data_;

public:

	TreeNode* left_;

	TreeNode* right_;

	TreeNode()
	{
		// default constructor for the tree node
	}

	TreeNode( int value )
	{
		data_ = value;

		left_ = NULL;

		right_ = NULL;
	}

	int getData()
	{
		return data_;
	}
};

TreeNode* createBinarySearchTree( int sorted_array[], int start, int end )
{
	if ( start > end )
	{
		// Tree not possible at this point
		return NULL;
	}

	int mid = ( start + end )/2;
	TreeNode* root = new TreeNode( sorted_array[mid] );
	root->left_ = createBinarySearchTree( sorted_array, start, mid - 1 );
	root->right_ = createBinarySearchTree( sorted_array, mid + 1, end );

	return root;
}

void displaytree(TreeNode *current, int indent)
{
    if ( current != NULL )
    {
        displaytree(current->left_, indent + 4);
        if (indent > 0)
        {
        	std::cout<<std::setw(indent)<<" ";
        }
        std::cout<<current->getData()<<'\n';
        displaytree(current->right_, indent + 4);
    }
}

int main()
{
	int sorted_array[] = { 1,2,3,4,5,6,7,8,9,10 };

	TreeNode* root = NULL;

	root = createBinarySearchTree( sorted_array, 0, ( sizeof( sorted_array ) / sizeof( int ) ) - 1 );

	displaytree(root, 0);
}