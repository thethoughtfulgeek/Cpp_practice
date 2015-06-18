/* This program implements another version of an algorithm that determines if a string has all unique characters 
Here it assumed that we are not allowed to modify the string */

/* Author: Jaineel Dalal <jdalal@andrew.cmu.edu>

Date 06/17/2015 */

#include <iostream>
#include <string>

bool string_char_repeat( std::string &string_ref )
{
	bool charArray[256] = {0}; 
	for (int i = 0; i < string_ref.length(); ++i)
	{
		int val = string_ref[i];
		std::cout<<val<<'\n';
		if ( charArray[val] == true )
		{
			return 0;
		}
		else
		{
			charArray[val] = true;
		}
	}
	return 1;
}

int main()
{
	std::string str;
	bool is_repeat = 0;

	std::cout<<"Enter string"<<"\n";
	std::cin>>str;

	if ( str.length() > 1 )
	{	
		if ( str.length() > 256 )
		{
			std::cout<<"\n"<<"has repeated characters"<<"\n";
			return false;
		}
		is_repeat = string_char_repeat( str );
		if (is_repeat == 0)
		{
			std::cout<<"\n"<<"has repeated characters"<<"\n";
		}
		else
		{
			std::cout<<"\n"<<"All unique characters"<<"\n";	
		}
	}
	else
	{
		std::cout<<"\n"<<"Please enter more characters next time"<<"\n";
	}

}