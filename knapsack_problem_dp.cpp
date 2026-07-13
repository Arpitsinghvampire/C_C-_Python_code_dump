//knapsack_problem_dp.cpp

//here we would be given some weights and the cost regarding them , we want to find the maximum weight 
//which can be achieved given  constraint on the weight of the bag 
#include<iostream>
#include<vector>

using namespace std;

//here we are assuming that all the weights are greater than 0 
void knapsack_problem(vector<int> &weight , vector<int> &profit , int max_weight , vector<vector<int>> &dp)
{
	//the number of rows is the number of weights and the number of columns is the max_weight 
	for(int column = 0 ; column< max_weight+1 ; column++)
	{
		if(weight[0] <= column)
			dp[0][column] = profit[0];
		else
			dp[0][column] = 0 ;
	}

	for(int row = 0 ; row < weight.size() ; row++)
	{
		dp[row][0] = 0 ;
	}

	//now  we have set the rows and the columns , now lets set the other values 
	for(int row = 1; row<weight.size() ; row++)
	{
		for(int column = 1 ; column < max_weight+1 ; column++)
		{
			//you can either take or you dont take that element 
			int not_taken = dp[row-1][column];

			int taken = 0 ;
			if(weight[row] <= max_weight)
				taken = profit[row] + dp[row-1][max_weight-weight[row]];

			dp[row][column] = max(taken, not_taken);
		}
	}
	return ;
}