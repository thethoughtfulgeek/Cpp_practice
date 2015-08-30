/*

This program is used to design an algorithm for sorting a stack in ascending order with the biggest element first
Only one additional stack is allowed
If unlimited stacks are allowed, we could use a quicksort or mergesort algorithm for sorting within the stack

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/28/2015

*/

#include <iostream>
#include <stack>

// sort_stack takes in a stack, sorts it out and returns the value
std::stack<int>& sort_stack( std::stack<int>& main_stack )
{
	// Variable that holds buffer value while sorting
	int temp_buffer;

	// Stack that holds the sorted values
	std::stack<int> sorted_stack;

	while ( main_stack.size() != 0 )
	{
		temp_buffer = main_stack.top();
		main_stack.pop();
		if ( sorted_stack.size() == 0 )
		{
			sorted_stack.push( temp_buffer );
		}
		else
		{
			if ( temp_buffer >= sorted_stack.top() )
			{
				sorted_stack.push(  temp_buffer );
			}
			else
			{
				while( temp_buffer < sorted_stack.top() || sorted_stack.size() != 0 )
				{
					main_stack.push( sorted_stack.top() );
					sorted_stack.pop();
				}
				sorted_stack.push( temp_buffer );
			}
		}
	}

}



int main()
{

}