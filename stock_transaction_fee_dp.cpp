//stock_transaction_fee_dp.cpp

//now each stock transaction also has a transaction fee 
#include<iostream>
#include<vector>

using namespace std;

void max_dp(vector<int> profits , int transaction_fee)
{
	vector<vector<int>> s1(profits.size() , vector<int>(2,0));

	for(int index = profits.size()-1 ; index>=0 ; index--)
	{
		//if you cant buy the stock , you can either sell or you dont want to sell 
		dp[index][0] = max(profits[index] - transaction_fee + dp[index+1][1] , dp[index+1][0]);

		dp[index][1] = max(-profits[index]-transaction_fee + dp[index+1][0] , dp[index+1][1]);
	}

	return dp[0][1];
}