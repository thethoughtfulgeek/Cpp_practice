//This program is used to return a corresponding column title given a positive integer. Just like an excel sheet

/*For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB */

#include<iostream>

using namespace std;

class Solution 
{
public:
    string convertToTitle(int n) 
    {
    	string str;
    	int str_length = 0;
    	while(n>0)
    	{
	    	int temp_num = n%26;
	    	if(temp_num == 0)
	    	{
	    		temp_num = 26;
	    		str = str + string(1,char(temp_num+64));
//Adding 64 for converting ASCII values from numbers to capital alphabets (A,B etc)
	    		n = (n/26)-1;
//Move on to the next digit. In case its 26th letter ie Z, we have to subtract one because we start from 0 and hence Z is the 25th letter 	    		
	    	}
	    	else
	    	{
	    		str = str + string(1,char(temp_num+64));
	    		n = n/26;
	    	}
	    	str_length += 1;
//string length	    	
	    }
//Program for string reversal	    
	    string temp_str = str;
	    for(int i = 0; i<=str_length; i++)
	    {
	    	str[i] = temp_str[str_length-1-i];
	    } 
//String reversal program ends here	    
	    return str;
    }
};

int main()
{
	Solution numtocol;
	int num;
	string letter;
	while(1)
	{
		cout<<"enter number\n";
		cin>>num;
		
		if (num == 0)
      	{
	      	cout<<"Error! 0 is not a valid column number\n";
    	} 
      	
      	letter = numtocol.convertToTitle(num);
      	cout<<"Corresponding Column = "<<letter<<"\n";
	}
}

