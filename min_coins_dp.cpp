//min_coins_dp.cpp

//in this code , block we would be given some denominations , we have to find the minimum number of coins possible 
#include<iostream>
#include<vector>

using namespace std;

void min_coins(vector<int> denominations , int target, vector<int> &dp)
{
	//here the number of rows would be the size of the denominations vector and the number of columns would 
	//be target
	//lets fill the first row 
	for(int column = 1 ; column < target+1 ; column++)
	{
		if(column%denominations[0] == 0)
			dp[0][column] = column/denominations[0];
		else
			dp[0][column] = 0 ;
	}

	//now lets fill the first column 
	for(int row = 0 ; row< denominations.size() ; row++)
	{
		dp[row][0] = 0 ;
	}

	//now lets fill the 
	for(int row = 1 ; row< denominations.size() ; row++)
	{
		for(int column = 1; column < target+1 ; column++)
		{
			int not_taken =  dp[row-1][column];

			int taken = INT_MAX;

			if(denominations[row] <= target)
			{
				taken = 1 + dp[row][target-denominations[row]]; //because we can again take that element 
			}

			dp[row][column] = min(taken , not_taken);
		}
	}
}