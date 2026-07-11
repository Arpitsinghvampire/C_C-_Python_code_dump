//minimum_path_sum.cpp

//here we would be given a 2d matrix , each node has some weights , we want to find the minimum path sum 
//we want to find hte minimum sum of the path from the starting to the ending 
#include<iostream>
#include<vector>

using namespace std;

void minimum_path_sum(vector<vector<int>> matrix_weight , vector<vector<int>> &dp , int rows , int columns)
{
	// we can only go  right and  down only 

	int running_sum = 0;

	int running_sum1 = 0 ;

	for(int column = 0 ; column < columns ; column++)
	{
		dp[0][column] = matrix_weight[0][column] + runnning_sum ;
		running_sum += matrix_weight[0][column];
	}

	for(int row = 1 ; row<rows ; row++)
	{
		dp[row][0] = dp[row][0] + running_sum1;
		running_sum1 += running_sum1 + dp[row][0];
	}

	//now we fill the other values 
	for(int row = 1 ; row<rows ; row++)
	{
		for(int column = 1 ; column< columns ; column++)
		{
			dp[row][column] =  min(dp[row-1][column] , dp[row][column-1]) + matrix_weight[row][column];
		}
	}

	return dp[rows-1][columns-1];
}