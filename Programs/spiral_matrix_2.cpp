/* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
] */

 /* This code contains just the main "meat" of the code without any #include statements or int main(). All it does is explains the 
  main logic */ 
class Solution 
{
public:  
    vector<vector<int> > generateMatrix(int n) 
    //A function called generateMatrix that generates and returns a nxn square matrix of type vector<vector<int> > 
    {
    	if (n <= 0)
    	{
    		return vector<vector<int> >();
    	}
    	else
    	{
    		vector<vector<int> > spiral_mat(n, vector<int>(n));
    		int val = 1;
    		for (int level = 0; level < n; ++level, --n)
    		{
    			for (int i=level; i < n; ++i) 
    				{
    					spiral_mat[level][i] = val++;  
    				}
    			for (int i=level+1; i < n; ++i) 
    				{
    					spiral_mat[i][n-1] = val++;
    				}
     			for (int i=n-2; i >= level; --i) 
     				{
     					spiral_mat[n-1][i] = val++;  
     				}
     			for (int i=n-2; i > level; --i) 
     				{
     					spiral_mat[i][level] = val++;  
     				}
    		}
    		return spiral_mat;
    	}
    }
};
