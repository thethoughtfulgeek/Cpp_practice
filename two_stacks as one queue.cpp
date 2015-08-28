/*

This program is used to implement a MyQueue class which implements a queue using two stacks.
It does so by using two stacks in reverse order with respect to one another. 
One stack holds the newest elements first (like any normal stack). We push to this stack.
The other stack holds the oldest elements first. We pop from this stack to implement a queue.

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 08/28/2015

*/

#include <iostream>
#include <stack>

class MyQueue : public std::stack<int>
{
private:
	// This stack is reverse of the original stack and it holds the oldest elements first.
	// Should be used for popping the elements out. When empty it gets new set of elements from stack NewestFirst_
	stack* OldestFirst_;

	// This is like a normal stack. It holds the newest elements first.
	// used for pushing the new elements every time. Once a while when the OldestFirst_ stack is empty, it copies all the elements over there
	stack* NewestFirst_;

public:
	MyQueue()
	{
		OldestFirst_ = new std::stack<int>;
		NewestFirst_ = new std::stack<int>;
	}

	~MyQueue()
	{
		// Default destructor
	}

	// used to push the values on to the queue
	void enqueue( int value );

	// used to pop the values from the queue
	void dequeue();

	// gives the next value to be popped out from the queue
	int top();

};

void MyQueue::enqueue( int value )
{
	NewestFirst_->push( value );
}

void MyQueue::dequeue()
{
	if ( OldestFirst_->size() > 0 )
	{
		OldestFirst_->pop();	
	}
	else
	{
		while( NewestFirst_->size() != 0 )
		{
			OldestFirst_->push( NewestFirst_->top() );
			NewestFirst_->pop();	
		}
		OldestFirst_->pop();
	}
}

int MyQueue::top()
{
	if ( OldestFirst_->size() > 0 )
	{
		return OldestFirst_->top();
	}
	else
	{
		return -1;
	}
}

int main()
{
	MyQueue queue1;
	
	queue1.enqueue(5);
	queue1.enqueue(15);
	queue1.enqueue(25);
	queue1.dequeue();
	std::cout<<queue1.top()<<'\n';
	queue1.enqueue(100);
	queue1.dequeue();
	std::cout<<queue1.top()<<'\n';
	queue1.enqueue(55);
	std::cout<<queue1.top()<<'\n';
}