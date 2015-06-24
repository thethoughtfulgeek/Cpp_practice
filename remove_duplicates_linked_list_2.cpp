/* This program is used to remove duplicates from an unsorted linked list */
/* It restricts using an extra buffer for the same */

#include <iostream>
     
class Node
{
private:
	int data;
	Node* next;

public:
	Node(int x)
	{
		data = x;
		next = NULL;
	}
	int getValue()
	{
		return data;
	}
	Node* getNextNode()
	{
		return next;
	}
	void DeleteNode( Node* new_next )
	{
		next = new_next;
	}
};
     
// Remove duplicated nodes in linked list without extra buffer
void RemoveDuplicate(Node *head)
{
	if ( head == NULL)
	{
		std::cout<<"Empty linked list!";
		return;
	}
	else
	{
		while (head != NULL)
		{
			Node* current = head;
			Node* temp = current->getNextNode();
			while (temp != NULL)
			{
				if ( head->getValue() == temp->getValue() )
				{
					current->DeleteNode(temp->getNextNode());
					current = current->getNextNode();
					if ( current == NULL )
					{
						return;
					}
					temp = current->getNextNode();
				}
				else
				{
					current = current->getNextNode();
					temp = current->getNextNode();
				}
			}
			head = head->getNextNode();		
		}

	}
}
     
int main() 
{
	// your code goes here
    return 0;
}