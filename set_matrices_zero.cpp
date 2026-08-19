//set_matrices_zero.cpp
//here we will be given an mxn matrix , if an element is zero , we have to set that whole row and column as 0 
#include<iostream>
#include<vector>
using namespace std;

vector<int> row_sum(vector<vector<int>> matrix , int m , int n)
{
	vector<int> row_sum(m , 0);

	for(int row = 0 ; row< m ; row++)
	{
		int sum =0 ;
		for(int column =0 ; column < n ; column++)
		{
			sum += matrix[row][column];
		}
		row_sum[row] = sum;
	}
	return row_sum;
}

vector<int> column_sum(vector<vector<int>> matrix , int m , int n)
{
	vector<int> column_sum(n , 0);

	for(int column =0 ; column < n ; column++)
	{
		sum = 0 ;
		for(int row = 0 ; row< m ; row++)
		{
			sum += matrix[row][column];
		}
		column_sum[column] = sum;
	}
	return column_sum;

}
//from here we would get the row sum and the column sum 
vector<vector<int>> convert_matrix(vector<vector<int>> &matrix , int m , int n)
{
	vector<int> rows_sums =  row_sum(matrix , m ,n);
	vector<int> columns_sums = column_sum(matrix , m , n);
	for(int current_row = 0 ; current_row < rows_sums.size() ; current_row++)
	{
		for(int current_column = 0 ; current_column< columns_sums.size() ; current_column++)
		{
			if(rows_sums[current_row] == n && columns_sums[current_column] == m)
				continue;
			else if(rows_sum[current_row] == n && columns_sums[current_column] !=m)
			{
				//make that column 0 but do not change any of the sums be it the row sum or the column sum 
				for(int row = 0 ; row< m ; row++)
				{
					matrix[row][current_column] = 0 ;
				}
			}
			else if(rows_sum[current_row] != n && columns_sums[current_column] == m)
			{
				//make that entire row as zero
				for(int column = 0 ; column < n ; column++)
				{
					matrix[current_row][column] = 0 ;
				}
			}
			else
			{
				//convert both the rows and the columns to 0 
				for(int row = 0 ; row < m ; row++)
				{
					matrix[row][current_column] = 0 ;
				}
				for(int column = 0 ; column < n ; column++)
				{
					matrix[current_row][column] = 0 ;
				}

			}
		}
	}
	return matrix ;
}