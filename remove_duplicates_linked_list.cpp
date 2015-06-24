/* This program is used to remove duplicates from an unsorted linked list */
/* It uses an extra buffer in the form of an unordered mao */

#include <iostream>
#include <unordered_map>
     
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
	void deleteNextNode(Node* current_node)
	{
		next = current_node;
	}

};
     
void RemoveDuplicate( Node* head )
{
	if ( head == NULL )
	{
		std::cout<<"Empty list!";
		return;
	}
	else
	{
		// Syntax for an unordered map ( unordered_map<key data type, value data type> map_name)
		// Key points to value
		unordered_map<int, bool> mymap;
		mymap[head->getValue()] = 1;
		Node* temp;
		
		while ( head->getNextNode() != NULL )
		{
			// if the particular key is not found in the container, count function returns -0
			if ( mymap.count( head->getNextNode()->getValue() ) == 0 ) 
			{
				// In that case, keep the node, enter it into map and move to the next one
				mymap[head->getNextNode()->getValue()] = 1;
				head = head->getNextNode();
			}
			else
			{	

				temp = head->getNextNode()->getNextNode();
				head->deleteNextNode(temp);
			}
		}

	}
}
     
    int main() {
    	// your code goes here
    	return 0;
    }