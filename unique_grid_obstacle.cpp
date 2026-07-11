//unique_grid_obstacle.cpp

//in this code , we would also be given some 2d matrix , along with the location of the  obstacle , we want to find the number of ways 
//by which we can  go from the start to the end 
#include<iostream>
#include<vector>
using namespace std;

void unique_grid(vector<vector<int>> &dp , vector<vector<int>> graph_obstacle , int rows , int columns)
{
	for(int row =0 ; row < rows; row++)
	{
		for(int column = 0 ; column <  columns ;column++)
		{
			if(graph_obstacle[row][column] == -1)
			{
				dp[row][column] = 0 ;
			}
			else
			{
				if(row == 0 && column != 0)
				{
					dp[row][column] = dp[row][column-1];
				}

				else if(row != 0 && column ==0)
				{
					dp[row][column] = dp[row-1][column];
				}

				else if(row == 0 && column == 0)
				{
					dp[row][column] = 1 ;
				}
				else
				{
					dp[row][column] = dp[row-1][column] + dp[row][column-1];
				}
			}
		}
	}
}