/* 
This program replaces all white spaces in a string with another string '%20'

Author: Jaineel Dalal
email id: <jdalal@andrew.cmu.edu>
Date: 06/21/2015
*/

#include <iostream>
#include <string>

void replace_space( std::string& str_ptr )
{
	int count_space = 0;
	for (int i = 0; i < str_ptr.length(); ++i)
	{
		if (str_ptr[i] == ' ')
		{
			count_space++;
		}
	}
	int new_string_length = str_ptr.length() + 2*count_space;
	std::string new_str[new_string_length];
	for (int i = 0, j = 0; j < new_string_length; ++i)
	{
		if (str_ptr[i] != ' ')
		{
			new_str[i] = str_ptr[i];
		}
		else
		{
			new_str[i] = '%';
			new_str[i+1] = '2';
			new_str[i+2] = '0';
			j = i + 3;
		}
	};



}

int main()
{
	std::string str;
	std::cout<<"Enter string"<<'\n';
	std::cin>>str;
	int n = str.length();
	if ( n > 1 )
	{
		replace_space( str );
	}
	else 
	{
		std::cout<<"Error! Enter a longer string next time"<<"\n";
	}

}