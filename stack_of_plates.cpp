/* 

This program is used to create a data structure SetofStacks that mimics a stack of plates.
SetofStacks is composed of several stacks where a new stack is created once the previous one exceeds capacity
However, SetofStacks.push() and SetofStacks.pop() behaves like a single stack
ie.  pop() must return values as if it was a single stack


Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/27/2015

*/

#include <iostream>
#include <stack>
#include <vector>

class SetofStacks : public std::stack<int>
{
private:
	// Vector that holds pointer of each individual Stack
	std::vector<stack*> stack_ptr_vector_;

	// length of each individual stack
	int single_stack_length_;

public:
	// Default constructor
	SetofStacks()
	{

	}

	// Parameterized constructor
	SetofStacks( int length )
	{

		stack_ptr_vector_.push_back( new std::stack<int> );

		single_stack_length_ = length;
	}

	// Destructor
	~SetofStacks()
	{
		for (int i = 0; i < stack_ptr_vector_.size(); ++i)
		{
			delete stack_ptr_vector_[i];
		}
		stack_ptr_vector_.clear();
	}

	// Push a value to SetofStacks just like any normal stack
	void push( int value );

	// Pop a value from SetofStacks just like any normal stack
	void pop();

	// Return the topmost value in the group of Stack SetofStacks
	int top();
};

void SetofStacks::push( int value )
{
	if ( stack_ptr_vector_.back()->size() == single_stack_length_ )
	{
		stack_ptr_vector_.push_back( new std::stack<int> );
		stack_ptr_vector_.back()->push( value );
	}
	else
	{
		stack_ptr_vector_.back()->push( value );
	}
}

void SetofStacks::pop()
{
	stack_ptr_vector_.back()->pop();
	if ( stack_ptr_vector_.back()->size() == 0 )
	{
		delete stack_ptr_vector_.back();
		stack_ptr_vector_.resize( stack_ptr_vector_.size() - 1 );
	}
}

int SetofStacks::top()
{
	return stack_ptr_vector_.back()->top();
}


int main()
{
	SetofStacks stacking_group(5);

	stacking_group.push(1);
	stacking_group.push(2);
	stacking_group.push(3);
	stacking_group.push(4);
	stacking_group.push(5);
	stacking_group.push(6);
	stacking_group.push(7);

	std::cout<<stacking_group.top()<<'\n';
	stacking_group.pop();

	std::cout<<stacking_group.top()<<'\n';
	stacking_group.pop();

	std::cout<<stacking_group.top()<<'\n';
	stacking_group.pop();
}