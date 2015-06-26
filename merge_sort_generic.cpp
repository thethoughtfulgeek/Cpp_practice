/* 
This is a generic implementation of the merge sort algorithm 

Author: Jaineel Dalal <jdalal@andrew.cmu.edu>
Date: 06/24/2015

*/

#include <iostream>

void merge( int array[], int helper[], int low, int middle, int high )
{
	// Copy the current halves ONLY into helper array
	for (int i = 0; i <= high; ++i)
	{
		helper[i] = array[i];
	}

	int Lhelper = low; // Left end of helper array
	int RHelper = middle + 1; // right end of helper array
	int current = low;

	// Comparing both halves and copying the smallest element into the original array
	while( Lhelper <= middle && RHelper <= high )
	{
		if ( helper[Lhelper] <= helper[RHelper] )
		{
			array[current] = helper[Lhelper];
			Lhelper++;
		}
		else
		{
			array[current] = helper[RHelper];
			RHelper++;
		}
		current++;
	}
	
	// Once the smallest element is copied, copy the remaining elements from the left hand side helper array

	int remaining = middle - Lhelper;

	for (int i = 0; i < remaining; ++i)
	{
		array[current+i] = helper[Lhelper+i];		
	}
}



void merge_sort( int array[], int helper[], int low, int high )
{
	if ( low < high )
	{
		int middle = ( low + high )/2;
		merge_sort( array, helper, low, middle );
		merge_sort( array, helper, middle+1, high);
		merge( array, helper, low, middle, high );
	}
}


void merge_sort( int array[], int length )
{
	int helper[length];
	merge_sort( array, helper, 0, length-1 );
	std::cout<<*array;
}


int main()
{
	int array[] = {1,9,10,4,3,25,10,0};
	std::cout<<*array<<'\n';
	int n = sizeof(array)/sizeof(array[0]);
	merge_sort( array, n );
}