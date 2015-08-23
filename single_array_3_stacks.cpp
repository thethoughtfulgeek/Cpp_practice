/* 

This program is used to create 3 stacks of equal sizes in a single array
It divides one array into 3 equal parts and then works on it. 
Leads to wastage of space

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/22/2015

*/

#include <iostream>

// Array that holds all the stacks
static const int total_array_size = 50;
static const int total_stack_num = 3;
static int* stacking_array = new int[total_array_size];
static int initial_stack_size = total_array_size/3;


class stack
/* This class initializes actual stacks */
{
private:
	// size of the particular stack
	int size_;

	// capacity of the particular stack
	int capacity_;

	// current head index of the stack
	int head_;

public:
	stack()
	{
		//Default constructor
	}

	// Parameterized constructor
	stack( int index, int capacity )
	{
		size_ = 0;
		capacity_ = capacity;
		head_ = index - 1;
	}

	// check if the stack is empty
	bool isempty()
	{
		if ( size_ > 0 )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// check if the stack is full
	bool isfull()
	{
		if ( size_ == capacity_ )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// push element onto the stack
	void push( int num )
	{
		if ( size_ < capacity_ )
		{
			head_++;
			size_++;
			stacking_array[head_] = num;
		}
		else
		{
			std::cout<<"Error! Stack full"<<'\n';
		}
	}

	// pop element from the stack
	// error checking whether the stack is empty or not must be done outside in the main loop and not here
	int pop()
	{
		if ( size_ > 0 )
		{
			int value = stacking_array[head_];
			stacking_array[head_] = 0;
			head_--;
			size_--;
			return value;
		}
		else
		{
			std::cout<<"Error Stack empty"<<'\n';
		}
	}
};

int main()
{
	stack* stack_ptr[total_stack_num];

	for ( int stackindex = 0; stackindex < total_stack_num; ++stackindex )
	{	
		stack_ptr[stackindex] = new stack( 0 + initial_stack_size*stackindex, initial_stack_size );
	}

	stack_ptr[1]->push( 10 );
	stack_ptr[1]->push( 20 );

	stack_ptr[0]->push( 100 );
	stack_ptr[1]->push( 3 );

	std::cout<<stack_ptr[1]->pop()<<'\t';
	std::cout<<stack_ptr[1]->pop()<<'\t';

	std::cout<<stack_ptr[2]->pop()<<'\t';
}