/* This program implements an algorithm that determines if a string has all unique characters */

/* Author: Jaineel Dalal <jdalal@andrew.cmu.edu>

Date 06/16/2015 */

#include <iostream>
#include <string>

std::string& string_sort( std::string &string_ref )
{
	char temp;
	for (int i = 1; i < string_ref.length(); ++i)
	{
		int j = i;
		while ( string_ref[j] < string_ref[j-1] )
		{
			temp = string_ref[j];
			string_ref[j] = string_ref[j-1];
			string_ref[j-1] = temp;
			j--;
		}
	}
	return string_ref;
}

bool string_char_repeat( std::string &string_ref )
{
	for (int i = 0; i < string_ref.length(); ++i)
	{
		if ( string_ref[i] == string_ref[i+1] )
		{
			return 0;
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
		std::string& sorted_str = string_sort( str );
		is_repeat = string_char_repeat( sorted_str );
		std::cout<<sorted_str;

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