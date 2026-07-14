//unbounded_knapsack_dp.cpp

//here in this question we can have unlimited occurences of a particular item , earlier we had only 
//one occurrence for each item 
#include<iostream>
#include<vector>

using namespace std;

void unbounded_knap(vector<int> profits , vector<int> weights , vector<vector<int>> &dp , int max_weight)
{
	//since we have unlimited occurence we just have to change one line from the traditional 
	//knapsack problem 
	for(int column = 1 ; column < max_weight + 1 ; column ++)
	{
		if(column > weights[0])
			dp[0][column] = profits[0] + dp[0][column-weights[0]];
		else
			dp[0][column] = 0 ;
	}

	for(int row = 0 ; row< profits.size() ; row++)
	{
		dp[row][0] = 0 ; //no profit for weight with bag weight 0 
	}

	for(int row = 1 ; row < profits.size() ; row++)
	{
		for(int column = 1 ; column < max_weight+1 ; column++)
		{
			int not_taken = dp[row-1][column];
			int taken = 0 ;
			if(weight[row]<= column)
				taken = profit[row] + dp[row][column - weight[row]]; //we can again take form the same  item weight 
			dp[row][column] = max(taken , not_taken);

		}
	}

}