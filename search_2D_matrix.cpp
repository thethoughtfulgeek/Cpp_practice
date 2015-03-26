#include<iostream>
#include<vector>

using namespace std;

#define ROW 2
#define COL 1

class Solution {
public:
    bool search_recursive_matrix(int row,int col,int num, vector<vector<int> > &matrix, int mid_el, int target, int count)
    {
        if (mid_el < 0 || mid_el > num || count > num)
        {
            return false;
        }

        if (num == 1)
        {
            return false;   
        }

        int req_row = (int)((mid_el-1)/col);
        int req_col = (mid_el-1)%col;
        
        if (matrix[req_row][req_col] == target)
        {
            return true;
        }

        else if (matrix[req_row][req_col] < target)
        {
            mid_el = mid_el +  1;
            count += 1;
            return search_recursive_matrix(row, col, num, matrix, mid_el, target, count);
            
        }
        else if (matrix[req_row][req_col] > target)
        {
            count += 1;
            mid_el = mid_el -  1;
            //cout<<mid_el;
            return search_recursive_matrix(row, col, num, matrix, mid_el, target, count);
        }
    }

    bool searchMatrix(vector< vector<int> > &matrix, int target) 
    {
        int row = matrix.size();
       //cout<<row;
        if (row == 0)
        {
            return  false;
        }
        int col = matrix[0].size();
     //   cout<<col;
        if (col == 0)
        {
            return  false;
        }
        int num_el = row*col;
      //  cout<<num_el;
        int mid_el = 0;
        if(num_el%2 == 0)
        {
            int mid_el = num_el/2;
            
        }
        else if(num_el%2 != 0)
        {
            int mid_el = (num_el+1)/2;
        }
        
     //   req_row = (int)((mid_el-1)/(col);
       // req_col = ((mid_el-1)%(col);
        // This converts the index of the given element into rows and columns
        // row = index/max_columns
        // col = index%max_columns
        // considering element 0 as well, index as well as row and column number have to start from 0 
        int count = 0;
        return search_recursive_matrix(row, col, num_el, matrix, mid_el, target, count);
     }
};

int main()
{
	Solution A1;
	cout<<"Enter matrix elements\n";
	vector<vector<int> > mat(ROW, vector<int> (COL));
	//cout<<mat.size();
	//cout<<mat[0].size();
	int target;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cin>>mat[i][j];
		}
	}
	cout<<"Matrix is: \n";
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Enter target\n";
	cin>>target;
	//cout<<mat.size()<<mat[0].size();
	cout<<A1.searchMatrix(mat, target);
	return 0;
}