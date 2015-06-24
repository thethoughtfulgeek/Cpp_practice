/* This algorithm finds the kth to the last element in a singly linked list 

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
};

int get_Last_Kelement(Node* head, int k)
{
	if ( head == NULL )
	{
		std::cout<<"Empty list!";
		return 0;
	}
	Node* fast = head;
	int count = 0;
	while( count < k)
	{
		fast = fast->getNextNode();
		if ( fast == NULL )
		{
			std::cout<<"Error! Length is not sufficient!";
			return 0;
		}
		count++;
	}
	while( fast->getNextNode() != NULL )
	{
		head = head->getNextNode();
		fast = fast->getNextNode();
	}
	return head->getData();
}






















int main()
{

}