/* 
This program creates a file filled with strings and then reads and outputs last K lines of that file
Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 07/19/2015
*/

#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::string str;

	// Creating a new file and writing to it
	std::ofstream writefile;
	writefile.open( "file.dat" );

	std::cout<<"Enter strings to write"<<'\n';
	int i = 0;

	while ( i != 5 )
	{
		std::cin>>str;
		writefile<<str<<'\n';
		i++;
	}
	// File is written to, saved and closed
	writefile.close();

	// Now read last k lines of this file
	std::ifstream readfile;
	readfile.open( "file.dat" );

	std::cout<<"print last ? lines"<<'\n';
	int k = 0;
	std::cin>>k;

	//Checking for boundary cases
	if ( k > i ) // If the number of last lines to be printed are greater than the total number of lines stored in the file raise an error
	{
		std::cout<<"Error! File contains insufficient number of lines!"<<'\n';
	}

	else
	{
		// Copy contents of the entire file into a vector of strings!
		std::vector<std::string> string_vector;
		std::cout<<"Reading from file now:"<<'\n';
		while( std::getline( readfile, str ) )
		{
		//	std::cout<<str<<'\n';
			string_vector.push_back(str);
		}
		int i = 0;
		while ( k < string_vector.size() )
		{
			++i;
			++k;
		}
		// printing out last i lines
		for (int j = i; j < k; ++j)
		{
			std::cout<<string_vector[j]<<'\n';
		}
	}
	return 0;
}