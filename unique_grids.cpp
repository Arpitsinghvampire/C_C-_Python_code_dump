//unique_grids.cpp

//here we would be given a 2d array , and we want to find the number of possible paths to get to the  stop position from the start position 
#include<iostream>
#include<vector>

using namespace std;

//here we will focus only on the dp approach particularly the dp approach 
//we can only go towards the right or down  and no other direction is there to traverse 
void grid_paths(int rows , int columns , vector<vector<int>> &dp)
{
	for(int row = 0 ; row<rows ;row++)
	{
		for(int column = 0 ; column < columns ; column ++)
		{
			if(row == 0 || column == 0)
			{
				dp[row][column] = 1; //by only traversing right for the row and only traversing down for the column
			}
			else
			{
				dp[row][column] = dp[row-1][column] + dp[row][column-1] ; // by traversing right from dp[row][column-1] and traversing 
				//down from dp[row-1][column]
			}
		}
	}
}