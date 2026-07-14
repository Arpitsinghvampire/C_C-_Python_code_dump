//rod_cutting_dp.cpp

//here we will be given a rod , we have to cut the rod in such a way that we maximize our profits 
#include<iostream>
#include<vector>

using namespace std;


void rod_cutting(vector<int> profits  , vector<vector<int>> &dp , int rod_length)
{
	//we have to find the max profit we can achieve 
	//this is a 2d dp , containing the  rows as the  different size of the rod , and the columns as the rod lenght 
	//this basically tells us with the following preceding bar lengths , what profits i can achieve for a rod length 
	for(int row = 0 ; row< profits.size() ; row++)
	{
		dp[row][0] = 0 ;
	}
	for(int column = 1 ; column < rod_length+1 ; column++)
	{
		if(column >=1)
			dp[0][column] = profits[0] + dp[0][column-1];
	}

	//now we have fixed the base case , now lets store the general case 
	for(int row = 1 ; row < profits.size() ; row++)
	{
		for(int column = 1 ; column < rod_length+1 ; column++)
		{
			int not_taken = dp[row-1][column];

			int taken = 0 ;
			if(column>= row+1)
				taken = profits[row] + dp[row][column-row-1];

			dp[row][column] = max(not_taken , taken);
		}
	}

}