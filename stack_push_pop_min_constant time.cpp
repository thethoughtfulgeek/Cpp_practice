/* 

This program is used to design a stack which apart from the usual push and pop 
also has a function min to find minimum value in the stack.
push, pop and min operate in O(1) time. 

It does so by keeping track of all the min values so far in a separate stack

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/27/2015 

*/

#include <iostream>
#include <stack>

class my_stack : public std::stack<int>
{
private:
	stack* min_stack;

public:
	my_stack() : min_stack( new std::stack<int> )
	{
		// Default constructor with initializer list
	}

	~my_stack()
	{
		// Destructor deleting the dynamically created min_stack
		delete min_stack;
	}

	// pushes the given value on to the main stack after comparing it to the current minimum value
	// if it is lesser than the current minimum value, it also pushes it onto the dynamically created min_stack
	void push_in( int value );

	// pops the value at the top of the stack. If the value is equal to the current minimum value, it also pops the
	// current minimum value from the stack. Thus it always keeps track of the most recent minimum value.
	void pop_out();

	// only return (don't pop) the most recent minimum value at the top of the dynamicallly created min_stack
	int min();

};

void my_stack::push_in( int value )
{
	if ( this->size() > 0 )
	{
		if ( value <= min() )
		{
			min_stack->push( value );
		}
	}
	else
	{
		min_stack->push( value );
	}

	this->push( value );
}

void my_stack::pop_out( )
{
	int value = this->top();
	this->pop();
	if ( value == min() )
	{
		min_stack->pop();
	}
}

int my_stack::min()
{
	if ( min_stack->size() > 0 )
	{
		return min_stack->top();
	}
}

int main()
{
	my_stack Stack1;

	Stack1.push_in( 10 );
	Stack1.push_in( 20 );
	std::cout<<Stack1.min()<<'\n';
	Stack1.pop_out();
	Stack1.push_in( 0 );
	std::cout<<Stack1.min()<<'\n';
	Stack1.pop_out();
	std::cout<<Stack1.min()<<'\n';
}