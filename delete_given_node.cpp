/* 
This algorithm deletes a node to which it is given access to. It assumes that it receives no other information other than this. 
i.e. It does not have access to the head node. It only has access to the node which has to be deleted

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 06/23/2015

*/

#include <iostream>

class Node
{
private:
	int data;
	Node* next;

public:
	int getData()
	{
		return data;
	}

	Node* getNextNode()
	{
		return next;
	}
	void Setvalue( int value )
	{
		data = value;
	}
	void SetAddress( Node* add )
	{
		next = add;
	}
};

void Delete_given_node(Node* del_node)
{
	if ( del_node->getNextNode() || ( ( del_node->getNextNode() )->getNextNode() ) == NULL )
	{
		std::cout<<"Error! Insufficient length!";
		return;
	}
	int value = ( del_node->getNextNode() )->getData();
	del_node->Setvalue( value );
	del_node->SetAddress( ( del_node->getNextNode() )->getNextNode() );
}


int main()
{

}
