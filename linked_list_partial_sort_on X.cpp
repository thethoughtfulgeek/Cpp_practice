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

Node* Partition_list( Node* head, int X)
{
	if ( head == NULL )
	{
		std::cout<<"Empty list!";
		return 0;
	}
	else
	{
		Node* BeforeX = NULL;
		Node* BeforeX_final = NULL;
		Node* AfterX = NULL;
		Node* AfterX_final = NULL;

		while( head != NULL )
		{
			int value = head->getData();
			//std::cout<<value;
			if ( value < X )
			{
				if ( BeforeX == NULL )
				{
					BeforeX = head;
					//std::cout<<BeforeX->getData();
					BeforeX_final = BeforeX;				
				}
				else
				{
					BeforeX->SetAddress( head );
					BeforeX = head;
				}	
			}

			else
			{
				if ( AfterX == NULL )
				{
					AfterX = head;
					//std::cout<<BeforeX->getData();
					AfterX_final = AfterX;				
				}
				else
				{
					AfterX->SetAddress( head );
					AfterX = head;
				}
			}
			head = head->getNextNode();
		}

		// Merging of two linked lists into one
		BeforeX->SetAddress( AfterX_final );
		AfterX->SetAddress( NULL );
		return BeforeX_final;
	}
}







int main()
{

}