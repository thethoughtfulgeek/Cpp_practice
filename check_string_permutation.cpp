/* This program gives an algorithm that when given two strings decides if they 
	are permutations of one another 
	<author> : Jaineel Dalal
	<date> :  06/20/2015
	<email id> : jdalal@andrew.cmu.edu
*/

#include <iostream>
#include <string>

bool check_perm( std::string& str1, std::string& str2 )
{
	int str1_char[256] = {0};
	int str2_char[256] = {0};
	// Assuming an integer array of size 256. It holds the count of each character in the given string
	for ( int i = 0; i < str1.length(); ++i )
	{
		str1_char[str1[i]]++;
		str2_char[str2[i]]++;
	}
	for (int i = 0; i <= 256 ; ++i)
	{
		if ( str1_char[i] != str2_char[i] )
		{
			return 0;
		}
		else
		{
			return 1;
		}

	} 
}


int main()
{
	std::string str1,str2;
	std::cout<<"Enter string1"<<'\n';
	std::cin>>str1;
	std::cout<<"Enter string2"<<'\n';
	std::cin>>str2;
	bool perm_check = 0;
	if ( str1.length() == str2.length() )
	{
		perm_check = check_perm( str1, str2 );
		if (perm_check == 0)
		{
			std::cout<<"Permutation!"<<'\n';
		}
		else
		{
			std::cout<<"Strings are different"<<'\n';
		}
	}
	else
	{
		std::cout<<"Strings are different\n";
		return 0;
	}
}