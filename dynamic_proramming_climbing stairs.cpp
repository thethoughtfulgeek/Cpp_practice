/* 

This program  implements a method to count the number of possible ways in which a child
can run up a staircase with n steps provided he can hop either 1,2, or 3 steps at a time

Recursive programming here considering the last step solution will take O(3^n) time to solve
Because there will be 3 choices to evaluate at each step. Either climb 1 step, 2 step or 3 steps
Normal recursive programming will fail in this scenario as many of the already calculated steps will be
calculated again which will lead to wastage of time

This can be taken care of by Dynamic programming where we can store the older results somewhere and still
access them and solve the entire problem in linear time

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 09/20/2015

*/

#include <iostream>

int num_ways_climbing( int n, int map[] )
{
	// step number being climbed right now
	// map is an array that holds a particular position
	//std::cout<<sizeof(map)<<'\t'<<map[n]<<"<--- "<<n<<'\n';
	if ( n < 0 )
	{
		//std::cout<<"1st"<<'\n';
		return 0;
	}
	else if ( n == 0 )
	{
		//std::cout<<"2nd"<<'\n';
		return 1;
	}
	else if ( map[n] > -1 )
	{
		//std::cout<<map[n]<<'\t'<<"3rd"<<'\n';
		return map[n];
	}
	else
	{
		map[n] = num_ways_climbing( n-1, map ) + num_ways_climbing( n-2, map ) + num_ways_climbing( n-3, map );
		//std::cout<<"4th"<<'\n';
		return map[n];
	}
}



int main()
{

}
