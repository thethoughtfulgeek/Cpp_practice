// This program reverses a null terminated string

#include <iostream>
#include <string>

void reverse_string( std::string& str_ptr )
{
	char temp;
	int i = 0;
	int j = str_ptr.length() - 1;
	while( i <= j )
	{
		temp = str_ptr[i];
		str_ptr[i] = str_ptr[j];
		str_ptr[j] = temp;
		i++;
		j--;
	}
	std::cout<<str_ptr<<'\n';
}



int main()
{
	std::string str;
	std::cout<<"Enter string"<<'\n';
	std::cin>>str;
	int n =str.length();
	if ( n > 1)
	{
		reverse_string( str );
	}
	else
	{
		std::cout<<"Error! Enter longer string next time\n";
		return 0;
	}

	
}