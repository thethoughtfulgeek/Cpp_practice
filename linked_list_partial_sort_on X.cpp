/* 
This algorithm partitions a linked list around a value x such that all nodes less than x come before all nodes greater than or equal to x

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
	void newNode(int value)
	{
		data = value;
		next = NULL;
	}
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

void Partition_list( Node* head, int X)
{
	if ( head == NULL )
	{
		std::cout<<"Empty list!";
		return;
	}
	else
	{
		Node* BeforeX = NULL;
		Node* BeforeX_copy = BeforeX;
		Node* AfterX = NULL;
		Node*AfterX_copy = AfterX;

		while( head != NULL )
		{
			int value = head->getData();
			if ( value < X )
			{
				
				
			}
		}

	}
}







int main()
{

}