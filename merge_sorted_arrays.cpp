/* 

This algorithm merges two sorted arrays A and B into A (in a sorted manner)
It is assumed that A has enough extra buffer to hold B 

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 06/24/2015

*/


#include <iostream>

void merge_array ( int A[], int B[], int lastA, int lastB )
{
	int A_lastIndex = lastA - 1;
	int B_lastIndex = lastB - 1;
	int total_size = lastA + lastB - 1;

	while( B_lastIndex >= 0 )
	{
		while ( A_lastIndex >= 0 )
		{
			if ( A[A_lastIndex] > B[B_lastIndex] )
			{
				A[total_size] = A[A_lastIndex];
				A_lastIndex--;
			}
			else 
			{
				A[total_size] = B[B_lastIndex];
				B_lastIndex--;
			}
			total_size--;
		}
	}
}



int main()
{


}